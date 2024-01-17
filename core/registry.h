#ifndef XREGISTRY_H
#define XREGISTRY_H

#include <fstream>
#include <string>
#include <vector>
#include "ingredient.h"
#include "recipe.h"

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
  std::string generate_uuid();
  std::string parse_row(std::string);
  void read_in_csv(std::string);
  ~xRegistry();
};



#endif // XREGISTRY_H //