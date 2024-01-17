#ifndef COOKBOOK_H
#define COOKBOOK_H

#include "ingredient.h"
#include "recipe.h"
#include "utilz.h"
#include "xobj.h"

class CookBook : public xObject {
protected:

private:
  std::string bookname;
  std::ifstream book;
  std::vector<Recipe> cookbook;
  std::vector<Ingredient> registry;

public:
  CookBook();
  CookBook(std::string);
  std::string parse_ingredients(char*);
  void register_ingredient(Ingredient);
  bool check_registry(Ingredient*);
  Ingredient get_ingredient(int);
  Ingredient get_ingredient(std::string);
  int get_book_size();
  ~CookBook();
};

#endif // COOKBOOK_H //
