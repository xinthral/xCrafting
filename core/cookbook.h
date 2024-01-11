#ifndef COOKBOOK_H
#define COOKBOOK_H

#include "ingredient.h"
#include "recipe.h"
#include "utilz.h"
#include "xobj.h"

class CookBook : public xObject {
protected:
  struct {
    std::string name;
    int temperature;
    int cooktime;
    int preptime;
  } Meal;

private:
  std::ifstream cookbook;

public:
  CookBook();
  void read_in_recipe(std::string);
  ~CookBook();
};

#endif // COOKBOOK_H //