#include "cookbook.h"

CookBook::CookBook() { }

CookBook::CookBook(std::string filename) : bookname(filename) { }

void CookBook::read_in_recipe() {
  char* token;
  std::string row, output;
  this->book.open(("docs/" + this->bookname + ".rb"));
  int step = -1;
  while (std::getline(book, row)) {
    std::cout << "Row: " << row.c_str() << std::endl;
    token = strtok(const_cast<char*>(row.c_str()), ";::;\r\n");
    // std::cout << step << ": " << token << std::endl;
    this->cookbook.push_back(Recipe(step, token));
    while (token != NULL) {
      token = strtok(NULL, ";::;\r\n");
    }
    step--;
  }
}

int CookBook::get_book_size() { return this->cookbook.size(); }

CookBook::~CookBook() { }
