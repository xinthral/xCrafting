#ifndef XREGISTRY_H
#define XREGISTRY_H

#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include "ingredient.h"
#include "recipe.h"

// Recipe_Name;
// UUID;
// Recipe Name;
// PrepTime(?1);
// CookTime(?1);
// CookType;
// CookTemp;
// Ingredient List: UUID,#,Volume|...;
// Nested Recipe List: UUID,#,Volume|...;
// Instruction List: Do thing1, Do thing2, thing3, consume!|...;

class xRegistry {
protected:
private:
  std::fstream fin;
  std::ifstream registrar;
  std::vector<Ingredient> ingredients;
  std::vector<Recipe> recipes;

public:
  xRegistry();
  xRegistry(std::string);
  void parse_csv(int,std::string);
  std::string parse_ingredient(std::string);
  std::string parse_recipe(std::string);
  std::string parse_raw(std::string);
  std::string parse_elements(std::string);
  ~xRegistry();
};



#endif // XREGISTRY_H //