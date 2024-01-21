#include "recipe.h"

Recipe::Recipe() : xObject() {}
Recipe::Recipe(std::string id) : xObject(id) { this->cooktimemax = 604,800; }
Recipe::Recipe(std::string id, std::string name) : xObject(id, name) { }


int Recipe::ingredient_count() { return contains.size(); }
int Recipe::insert_ingredient(std::string key, Ingredient ing) { contains[key] = ing; return this->ingredient_count(); }
int Recipe::remove_ingredient(std::string key) { contains.erase(key); return this->ingredient_count(); }
void Recipe::set_cooktemp(std::string temp) { this->cooktemp = temp; }
void Recipe::set_cooktime(int cooktime) {
  if (cooktime < 0 || cooktime > this->cooktimemax) { printf("Invalid cooktime: %d\n", cooktime); }
  else { this->cooktime = cooktime; }
}

void Recipe::set_preptime(int preptime) {
  if (preptime < 0) { printf("Invalid preptime: %d\n", preptime); }
  else { this->preptime = preptime; }
}

std::string Recipe::get_cooktemp() { return this->cooktemp; }
int Recipe::get_cooktime() { return this->cooktime; }
int Recipe::get_preptime() { return this->preptime; }
void Recipe::display_instructions(bool both) {
  if (both) {
    std::cout << "  The Cooktime is: " << this->cooktime << std::endl;
    std::cout << "  The Preptime is: " << this->preptime << std::endl;
  }

  for(std::string s : this->instructions) { 
    std::cout << s << std::endl; 
  }
}

void Recipe::user_input_instructions() {
  std::string input = this->name + " Cooking Instructions!";
  int idx = 1;
  while (input.rfind("!exit") != 0) {
    std::sprintf(buf, " %d: %s", idx, input.c_str());
    this->instructions.push_back(buf);
    std::cout << "Input Instructions: ";
    // std::cin.ignore(); 
    std::getline(std::cin, input, '\n');
    while (std::cin.fail()) {
      std::cin.clear();
      std::cin.ignore();
      std::cout << "Invalid Input >> Reinput String: ";
      std::cin >> input;
    }
    idx++;
  }
}

void Recipe::display_ingredients(bool headers) { for (auto i : this->contains) { std::cout << "::" << i.first << std::endl; } }

Recipe::~Recipe() {}
