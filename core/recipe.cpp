#include "recipe.h"


Recipe::Recipe() : xObject() {
  this->cooktimemax = 604'800;
}


Recipe::Recipe(std::string id) : xObject(id) {
  this->cooktimemax = 604'800;
}


Recipe::Recipe(std::string id, std::string name) : xObject(id, name) {
  this->cooktimemax = 604'800;
}


void Recipe::display_ingredients(bool headers) {
  if (headers) {
    printf("Ingredients:\n");
  }
  for (auto i : this->contains) {
    printf("::%s\n", i.first);
  }
}


void Recipe::display_instructions(bool showtime) {
  if (showtime) {
    std::cout << "  The Preptime is: " << this->preptime << std::endl;
    std::cout << "  The Cooktime is: " << this->cooktime << std::endl;
  }

  for(std::string s : this->instructions) { 
    std::cout << s << std::endl; 
  }
}


std::string Recipe::get_cooktemp() {
  return this->cooktemp;
}


int Recipe::get_cooktime() {
  return this->cooktime;
}


int Recipe::get_preptime() {
  return this->preptime;
}


int Recipe::ingredient_count() {
  return contains.size(); 
}


int Recipe::insert_ingredient(std::string uuid, std::string ingredient) {
  contains[uuid] = ingredient; 
  return this->ingredient_count();
}


int Recipe::remove_ingredient(std::string uuid) {
  contains.erase(uuid);
  return this->ingredient_count();
}


void Recipe::set_ingredients(std::vector<std::string> ingredientlist) {
  char* token;
  for (auto ing : ingredientlist) { 
    token = strtok(const_cast<char*>(ing.c_str()), ";\r\n");
    this->contains[token] = ing;
  }
}


void Recipe::set_cooktemp(std::string temp) {
  this->cooktemp = temp;
}


void Recipe::set_cooktime(int newtime) {
  if (newtime < 0 || newtime > this->cooktimemax) {
    printf("Invalid cooktime: %d\n", newtime);
  } else {
    this->cooktime = newtime;
  }
}


void Recipe::set_instructions(std::vector<std::string> input) {
  for (auto itr : input) {
    this->instructions.push_back(itr);
  }
}


void Recipe::set_nested_recipes(std::vector<std::string> recipelist) {
  char* token;
  for (auto rec : recipelist) {
    token = strtok(const_cast<char*>(rec.c_str()), ";\r\n");
    this->contains[token] = rec;
  }
}


void Recipe::set_preptime(int preptime) {
  if (preptime < 0) { printf("Invalid preptime: %d\n", preptime); }
  else { this->preptime = preptime; }
}


void Recipe::user_input_instructions() {
  std::string input;
  int idx = 0;
  bool repeat = true;

  input = this->get_name() + " Cooking Instructions!";
  this->instructions.push_back(input);
  printf("Input Instructions: \n");
  while (repeat) {
    printf("%s ", this->get_prompt().c_str());
    input = Utilz::UserInput(this->get_prompt());
    this->instructions.push_back(input);
    if (input.compare("!exit") == 0) { repeat = false; }
  }
}

Recipe::~Recipe() {}
