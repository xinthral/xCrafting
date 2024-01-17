#include "registry.h"

xRegistry::xRegistry() {}

std::string xRegistry::parse_row(std::string row) {
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

void xRegistry::read_in_csv(std::string filename) {
  std::string row;
  this->registrar.open(("docs/" + filename));
  int step = 1;
  while (std::getline(registrar, row)) {
    // std::cout << step << ": " << row.c_str() << std::endl;
    row = this->parse_row(row);
    // std::cout << "Row: " << row.c_str() << std::endl;
    // this->cookbook.push_back(Recipe(step, row));
    step++;
  }
}

xRegistry::~xRegistry() {}
