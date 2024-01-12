#include "cookbook.h"

CookBook::CookBook() { }

CookBook::CookBook(std::string filename) : bookname(filename) { }

void CookBook::read_in_recipe() {
  char* token;
  std::string row, output;
  std::vector<std::string> rowArray;
  this->book.open(("docs/" + this->bookname + ".rb"));
  int step = -1;
  while (std::getline(book, row)) {
    std::cout << "Row: " << row.c_str() << std::endl;
    token = strtok(const_cast<char*>(row.c_str()), ";::;\r\n");
    std::cout << step << ": " << token << std::endl;
    while (token != NULL) {
      this->cookbook.push_back(Recipe(step, token));
      token = strtok(NULL, ";::;\r\n");
    }
    step--;
  }
  
  // for (auto i : rowArray) { std::cout << "_::::_" << i << std::endl; }
  free(token);
}

int CookBook::get_book_size() { return this->cookbook.size(); }

CookBook::~CookBook() { }