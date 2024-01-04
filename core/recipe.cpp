#include "recipe.h"

Recipe::Recipe(int id) : xObject(id) { }

Recipe::Recipe() : Recipe(-1) { }

int Recipe::ingredient_count() { return contains.size(); }

int Recipe::insert_ingredient(std::string key, Ingredient ing) { contains[key] = ing; return this->ingredient_count(); }

int Recipe::remove_ingredient(std::string key) { contains.erase(key); return this->ingredient_count(); }

Recipe::~Recipe() { }
