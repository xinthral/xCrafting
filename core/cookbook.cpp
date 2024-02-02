#include "cookbook.h"

CookBook::CookBook() : xObject() {}

CookBook::CookBook(std::string filename) : bookname(filename) { this->registrar = new xRegistry(); }

bool CookBook::register_ingredient(Ingredient item) {
  if (!this->registrar->add_ingredient(item)) { return true; }
  printf("Ingredient not in registry\n");
  return false;
}

bool CookBook::register_recipe(Recipe item) {
  if (!this->registrar->add_recipe(item)) { return true; }
  printf("Recipe not in registry\n");
  return false;
}

int CookBook::get_book_size() { return this->cookbook.size(); }

void CookBook::load_ingredients(std::string filename) { this->registrar->parse_csv(1, filename); }

void CookBook::load_recipes(std::string filename) { this->registrar->parse_csv(2, filename); }

CookBook::~CookBook() { }