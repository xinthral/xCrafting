#ifndef COOKBOOK_H
#define COOKBOOK_H

#include "ingredient.h"
#include "recipe.h"
#include "registry.h"
#include "utilz.h"
#include "xobj.h"

class CookBook : public xObject {
protected:
  xRegistry* registrar;

private:
  std::string bookname;
  std::ifstream book;
  std::vector<Recipe> cookbook;

public:
  CookBook();
  CookBook(std::string);
  void register_ingredient(Ingredient);
  void register_recipe(Recipe);
  bool check_ingredient_with_registry(Ingredient*);
  bool check_recipe_with_registry(Recipe*);
  Ingredient get_ingredient_by_name(std::string);
  Ingredient get_ingredient_by_uuid(std::string);
  int get_book_size();
  ~CookBook();
};

#endif // COOKBOOK_H //
