#include "ingredient.h"

const std::string Ingredient::IName[] = { "Culinary", "Protein", "Produce", "Grain", "Craft" };

Ingredient::Ingredient() : xObject() {}
Ingredient::Ingredient(std::string id) : xObject(id) {}
Ingredient::Ingredient(std::string id, std::string name) : xObject(id, name) {}
Ingredient::Ingredient(std::string id, std::string name, int count) : xObject(id, name) { this->set_quanitity(count); }
Ingredient::Ingredient(std::string id, std::string name, int count, std::string type) : Ingredient(id, name, count) { this->set_type(type); }

std::string Ingredient::get_type() { return this->_type; }
int Ingredient::set_type(std::string newType) {
  std::string iname;
  int output = 0;
  for (int i = 0; i < 5; i++) {
    iname = Ingredient::IName[i];
    if (strcmp(iname.c_str(), newType.c_str()) == 0) {
      output = i;
      this->_type = iname;
    }
  }
  return output;
}
int Ingredient::get_quantity() { return this->quantity; }
void Ingredient::set_quanitity(int newValue) { this->quantity = newValue; }
std::string Ingredient::get_location() { return this->location; }
void Ingredient::set_location(std::string newValue) { this->location = newValue; }
int Ingredient::add_provides(std::string benefit) { this->provides.push_back(benefit); return this->provides.size(); }
int Ingredient::provides_length() { return this->provides.size(); }
void Ingredient::display_provides() { for (auto c : this->provides) { printf(" :%s\n", c.c_str()); }}
std::string Ingredient::type_repr(int index) { return this->IName[index]; }

Ingredient::~Ingredient() {}
