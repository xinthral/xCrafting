#include "ingredient.h"

Ingredient::Ingredient(int id) : xObject(id) { }

Ingredient::Ingredient() : Ingredient(-1) {
  name = Utilz::randomString(6);
}

Ingredient::~Ingredient() { }
