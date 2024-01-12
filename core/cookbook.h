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

public:
  CookBook();
  CookBook(std::string);
  void read_in_recipe();
  int get_book_size();
  ~CookBook();
};

#endif // COOKBOOK_H //
