#include "cookbook.h"

CookBook::CookBook() : xObject() {}

CookBook::CookBook(std::string filename) : bookname(filename) {}

void CookBook::register_ingredient(Ingredient item) {
  if (this->check_registry(&item)) { return; }
  // this->registrar.push_back(item);
}

bool CookBook::check_registry(Ingredient* item) {
  // for (std::vector<Ingredient>::iterator itr = this->registry.begin(); itr != this->registry.end(); itr++) {
  //   if (itr->get_name() == item->get_name()) { return true; }
  // }
  std::cout << "Check_Registry: " << item->get_name() << " not found." << std::endl;
  return false;
}

Ingredient CookBook::get_ingredient_by_name(std::string name) { return Ingredient(); }
Ingredient CookBook::get_ingredient_by_uuid(std::string uuid) { return Ingredient(); }

int CookBook::get_book_size() { return this->cookbook.size(); }

CookBook::~CookBook() { }
