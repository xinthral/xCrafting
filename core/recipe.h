#ifndef RECIPE_H
#define RECIPE_H

#include "ingredient.h"
#include "xobj.h"

class Recipe : public xObject {
protected:
  std::map<std::string, Ingredient> contains;
private:
public:
  Recipe();
  Recipe(int);
  int ingredient_count();
  int insert_ingredient(std::string,Ingredient); 
  int remove_ingredient(std::string);
  ~Recipe();
};

#endif // RECIPE_H //