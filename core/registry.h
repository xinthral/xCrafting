#ifndef XREGISTRY_H
#define XREGISTRY_H

#include <fstream>
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include "ingredient.h"
#include "recipe.h"
#include "xobj.h"

/*
1: UUID;
2: RecipeName;
3: PrepTime;
4: CookTime;
5: CookType;
6: CookTemp;
7: IngredientUUID|#Count|Volume,...;
8: RecipeUUID|#Count|Volume,...;
9: Instr1|...; 
*/
class xRegistry : xObject {
protected:
private:
  std::fstream fin;
  std::ifstream registrar;
  std::vector<Ingredient> ingredients;
  std::vector<Recipe> recipes;
  std::map<std::string,std::string> ingMap;

public:
  xRegistry();
  xRegistry(std::string);
  int get_itype_index(std::string);
  void parse_csv(int,std::string);
  void parse_ingredient(std::string);
  void parse_recipe(std::string);
  std::string parse_raw(std::string);
  bool add_ingredient(Ingredient);
  bool verify_ingredient(Ingredient);
  bool add_recipe(Recipe);
  bool verify_recipe(Recipe);
  ~xRegistry();
};



#endif // XREGISTRY_H //