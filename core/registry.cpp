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
  int step = 2;
  std::string output, uuid, rname, ctype;
  token = strtok(const_cast<char*>(row.c_str()), ";\r\n");
  while (token != NULL) { 
    output += token;
    // switch (step) {
    //   case 2: iname = token; break;
    //   case 3: itype = token; break;
    //   case 4: loc = token; 
    //   default: break;
    // }
    token = strtok(NULL, ";\r\n");
    if (token != NULL) { output += ";::;"; }
    step++;
  }
  // printf("Recipe: %s\n", output.c_str());
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

xRegistry::~xRegistry() {}
