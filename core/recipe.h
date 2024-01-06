#ifndef RECIPE_H
#define RECIPE_H

#include "ingredient.h"
#include "xobj.h"

class Recipe : public xObject {
protected:
  std::map<std::string, Ingredient> contains;
  std::vector<std::string> instructions;
  int temperature;
  int cooktime;
  int preptime;
  int cooktimemax;
private:
public:
  Recipe();
  Recipe(int);
  Recipe(int,std::string);
  int ingredient_count();
  int insert_ingredient(std::string,Ingredient); 
  int remove_ingredient(std::string);
  void set_cooktime(int);
  void set_preptime(int);
  int get_cooktime();
  int get_preptime();
  void setup_instructions();
  void display_instructions(bool);
  void display_ingredients(bool);
  ~Recipe();
};

#endif // RECIPE_H //