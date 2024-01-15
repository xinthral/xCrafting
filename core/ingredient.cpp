#include "ingredient.h"

Ingredient::Ingredient() : Ingredient(-1) { name = Utilz::randomString(6); }

Ingredient::Ingredient(int id) : xObject(id) {}

Ingredient::Ingredient(int id, std::string name) : xObject(id) { this->set_name(name); }

Ingredient::~Ingredient() {}
