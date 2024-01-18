#include "registry.h"

xRegistry::xRegistry() {}

void xRegistry::parse_csv(int filetype, std::string filename) {
  std::string row;
  this->registrar.open(("docs/" + filename));
  int step = 1;
  while (std::getline(registrar, row)) {
    // std::cout << step << ": " << row.c_str() << std::endl;
    switch (filetype) {
      case 0:
        row = this->parse_raw(row);
        break;
      case 1:
        row = this->parse_ingredient(row);
        break;
      case 2:
        row = this->parse_recipe(row);
        break;
      default:
        printf("Valid Options: [1,2]\n");
        return;
    }
    // this->cookbook.push_back(Recipe(step, row));
    step++;
  }
}

std::string xRegistry::parse_raw(std::string row) {
  char* token;
  std::string output;
  token = strtok(const_cast<char*>(row.c_str()), ";\r\n");
  while (token != NULL) { 
    output += "\n"; 
    output += token;
    token = strtok(NULL, ";\r\n"); 
  }
  std::cout << "Raw: " << output.c_str() << std::endl;
  return output;
}

std::string xRegistry::parse_elements(std::string elementlist) {
  char* token;
  std::string output;
  token = strtok(const_cast<char*>(elementlist.c_str()), "|");
  std::cout << "Element: " << elementlist.c_str() << std::endl;
  while (token != NULL) { 
    output += token; 
    token = strtok(NULL, "|"); 
  }
  return output;
}

std::string xRegistry::parse_ingredient(std::string row) {
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

std::string xRegistry::parse_recipe(std::string row) {
  char* token;
  std::string output;
  token = strtok(const_cast<char*>(row.c_str()), ";::;\r\n");
  while (token != NULL) { 
    output += token; 
    token = strtok(NULL, ";::;\r\n"); 
  }
  std::cout << "Recipe: " << output.c_str() << std::endl;
  return output;
}

xRegistry::~xRegistry() {}
