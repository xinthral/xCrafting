#include "cookbook.h"

CookBook::CookBook() { }

void CookBook::read_in_recipe(std::string filename) {
  char* token;
  std::string row, output;
  std::vector<std::string> rowArray;
  this->cookbook.open(("docs/" + filename));
  int step = 0;
  while (std::getline(cookbook, row)) {
    std::cout << "Row: " << row.c_str() << std::endl;
    token = strtok(const_cast<char*>(row.c_str()), ";::;\r\n");
    std::cout << step << ": " << token << std::endl;
    while (token != NULL) {
      rowArray.push_back(token);
      token = strtok(NULL, ";::;\r\n");
    }
    step++;
  }

  // for (auto i : rowArray) { std::cout << "_::::_" << i << std::endl; }
}

CookBook::~CookBook() { }