#include "registry.h"

xRegistry::xRegistry() {}

void xRegistry::parse_csv(int filetype, std::string filename) {
  std::string row;
  int step = 1;
  //! Opens File
  this->registrar.open(filename);
  
  // Read until EOD
  while (std::getline(registrar, row)) {
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
    step++;
  }
  //! Closes File
  this->registrar.close();
}

std::string xRegistry::parse_raw(std::string row) {
  char* token;
  std::string output;
  token = strtok(const_cast<char*>(row.c_str()), ";\r\n");
  while (token != NULL) { 
    output += token;
    token = strtok(NULL, ";\r\n"); 
    if (token != NULL) { output += ";::;"; }
  }
  std::cout << "\nRaw: " << output.c_str() << std::endl;
  // this->parse_elements(output);
  return output;
}

std::string xRegistry::parse_recipe(std::string row) {
  char* token;
  std::string output;
  token = strtok(const_cast<char*>(row.c_str()), "|");
  while (token != NULL) { 
    output += token; 
    token = strtok(NULL, "|\r\n"); 
  }
  std::cout << "\nRecipe: " << row.c_str() << std::endl;
  return output;
}

std::string xRegistry::parse_ingredient(std::string row) {
  char* token;
  std::string output;
  token = strtok(const_cast<char*>(row.c_str()), ",");
  while (token != NULL) { 
    output += token; 
    token = strtok(NULL, ",\r\n"); 
  }
  std::cout << "\nIngredient: " << row.c_str() << std::endl;
  return output;
}

xRegistry::~xRegistry() {}
