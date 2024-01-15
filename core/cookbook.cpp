#include "cookbook.h"

CookBook::CookBook() { }

CookBook::CookBook(std::string filename) : bookname(filename) { }

void CookBook::read_in_recipe() {
  std::string row;
  this->book.open(("docs/" + this->bookname + ".rb"));
  int step = -1;
  while (std::getline(book, row)) {
    // std::cout << step << ": " << row.c_str() << std::endl;
    row = this->parse_row(row);
    // std::cout << "Row: " << row.c_str() << std::endl;
    this->cookbook.push_back(Recipe(step, row));
    step--;
  }
}

std::string CookBook::parse_row(std::string row) {
  char* token;
  std::string output;
  token = strtok(const_cast<char*>(row.c_str()), ";::;\r\n");
  // std::cout << "Row: " << row.c_str() << std::endl;
  while (token != NULL) { 
    output += token; 
    token = strtok(NULL, ";::;\r\n"); 
  }
  return output;
}

std::string CookBook::parse_ingredients(char* ingredientlist) {}

void CookBook::register_ingredient(Ingredient item) {
  if (this->check_registry(&item)) { return; }
  this->registry.push_back(item);
}

bool CookBook::check_registry(Ingredient* item) {
  for (std::vector<Ingredient>::iterator itr = this->registry.begin(); itr != this->registry.end(); itr++) {
    if (itr->get_name() == item->get_name()) { return true; }
  }
  // std::cout << "Check_Registry: " << item->get_name() << " not found." << std::endl;
  return false;
}

Ingredient CookBook::get_ingredient(int index) {}

Ingredient CookBook::get_ingredient(std::string name) {}

int CookBook::get_book_size() { return this->cookbook.size(); }

CookBook::~CookBook() { }
