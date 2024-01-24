#include "registry.h"

xRegistry::xRegistry() : xObject() {}

int xRegistry::get_itype_index(std::string name) {
  int output = 0;
  for(int i = 0; i < 5; i++) {
    if (strcmp(Ingredient::IName[i].c_str(), name.c_str()) == 0) {
      output = i;
    }
  }
  return output;
}

void xRegistry::parse_csv(int filetype, std::string filename) {
  std::string row;
  int step = 1;
  //! Opens File
  this->registrar.open(filename);
  
  // Read until EOD
  while (std::getline(registrar, row)) {
    switch (filetype) {
      case 0:
        row = this->parse_raw(row);
        break;
      case 1:
        this->parse_ingredient(row);
        break;
      case 2:
        this->parse_recipe(row);
        break;
      default:
        printf("Valid Options: [1,2]\n");
        return;
    }
    step++;
  }

  //! Closes File
  this->registrar.close();
}

void xRegistry::parse_recipe(std::string row) {
  /* 
  1: UUID;
  2: RecipeName;
  3: PrepTime;
  4: CookTime;
  5: CookType;
  6: CookTemp;
  7: IngredientUUID|#Count|Volume,...;
  8: RecipeUUID|#Count|Volume,...;
  9: Instr1|...; 
  */
  char* token;
  int step = 1;
  int ctimei, ctempi, ptimei;
  std::string output, uuid, rname, ptime, ctime, ctype, ctemp;
  std::vector<std::string> ingr;
  std::vector<std::string> recp;
  std::vector<std::string> inst;
  token = strtok(const_cast<char*>(row.c_str()), ";\r\n");
  while (token != NULL) { 
    output += token;
    switch (step) {
      case 1: uuid = token; break; 
      case 2: rname = token; break;
      case 3: ptime = token; break;
      case 4: ctime = token; break;
      case 5: ctype = token; break;
      case 6: ctemp = token; break;
      case 7:
        this->parse_ingredient_from_recipe(token, ingr);
        break;
      case 8:
        this->parse_nested_from_recipe(token, recp);
        break;
      case 9:
        this->parse_instructions_from_recipe(token, inst);
      default: break;
    }
    token = strtok(NULL, ";\r\n");
    if (token != NULL) { output += ";::;"; }
    step++;
  }
  // printf("Recipe: %s\n", output.c_str());
  Recipe rec(uuid, rname);
  ptimei = atoi(ptime.c_str());
  ctimei = atoi(ctime.c_str());
  rec.set_preptime(ptimei);
  rec.set_cooktime(ctimei);
  rec.set_cooktemp(ctemp);
  // FIXME: the follow need to be made
  rec.set_ingredients(ingr);
  rec.set_nested_recipes(recp);
  rec.set_instructions(inst);
  this->add_recipe(rec);
}

void xRegistry::parse_ingredient(std::string row) {
  /* 
  1: UUID;
  2: Ingedient Name;
  3: Type;
  4: Location;
  */
  std::string output, uuid, iname, itype, loc;
  char* token;
  int step = 1, idx = 0;
  token = strtok(const_cast<char*>(row.c_str()), ";\r\n");
  while (token != NULL) { 
    output += token;
    switch (step) {
      case 1: uuid = token; break;
      case 2: iname = token; break;
      case 3: itype = token; break;
      case 4: loc = token; 
      default: break;
    }
    token = strtok(NULL, ";\r\n");
    if (token != NULL) { output += ";::;"; }
    step++;
  }
  Ingredient ing(uuid, iname, 1, itype);
  ing.set_location(loc);
  this->add_ingredient(ing);
  // printf("Ingredient: %s\n", output.c_str());
}

void xRegistry::parse_ingredient_from_recipe(std::string row, std::vector<std::string>& output) {
  char* token;
  char* symbol;
  token = strtok(const_cast<char*>(row.c_str()), ",\r\n");
  while (token != NULL) {
    symbol = strtok(token, "|\r\n");
    output.push_back(symbol);
    token = strtok(NULL, ",");
  }
}

void xRegistry::parse_nested_from_recipe(std::string row, std::vector<std::string>& output) {
  char* token;
  char* symbol;
  token = strtok(const_cast<char*>(row.c_str()), ",\r\n");
  while (token != NULL) {
    symbol = strtok(token, "|\r\n");
    output.push_back(symbol);
    token = strtok(NULL, ",");
  }
}

void xRegistry::parse_instructions_from_recipe(std::string row, std::vector<std::string>& output) {
  char* token;
  token = strtok(const_cast<char*>(row.c_str()), "|\r\n");
  while (token != NULL) {
    output.push_back(token);
    token = strtok(NULL, "|\r\n");
  }
}

std::string xRegistry::parse_raw(std::string row) {
  char* token;
  std::string output;
  token = strtok(const_cast<char*>(row.c_str()), ";\r\n");
  while (token != NULL) { 
    output += token;
    token = strtok(NULL, ";\r\n");
    if (token != NULL) { output += ";::;"; }
  }
  printf("Raw: %s\n", output.c_str());
  return output;
}

bool xRegistry::add_ingredient(Ingredient ingredient) {
  if (this->verify_ingredient(ingredient)) { this->ingredients.push_back(ingredient); return true; }
  return false;
}

bool xRegistry::verify_ingredient(Ingredient ingredient) {
  for(auto itr = this->ingredients.begin(); itr < this->ingredients.end(); ++itr) {
    if (strcmp(itr->get_name().c_str(), ingredient.get_name().c_str()) == 0) { return false; }
  }
  return true;
}

bool xRegistry::add_recipe(Recipe recipe) {
  if (this->verify_recipe(recipe)) { this->recipes.push_back(recipe); return true; }
  return false;
}
bool xRegistry::verify_recipe(Recipe recipe) {
  for(auto itr = this->recipes.begin(); itr < this->recipes.end(); ++itr) {
    if (strcmp(itr->get_name().c_str(), recipe.get_name().c_str()) == 0) { return false; }
  }
  return true;
}

void xRegistry::display_ingredients() {
  std::string s;
  int t, l, r;
  printf("\n");
  for (auto itr : this->ingredients) {
    s = itr.get_name();
    t = s.length();
    l = 16 + (t / 2);
    r = 32 - l;
    printf("[[]%*s%*s[]]\n", l, s.c_str(), r, "");
  }
  printf("\n");
}

void xRegistry::display_recipes() {
  std::string s;
  int t, l, r;
  printf("\n");
  for (auto itr : this->recipes) {
    s = itr.get_name();
    t = s.length();
    l = 16 + (t / 2);
    r = 32 - l;
    printf("[[]%*s%*s[]]\n", l, s.c_str(), r, "");
  }
  printf("\n");
}

xRegistry::~xRegistry() {}
