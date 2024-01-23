#ifndef RECIPE_H
#define RECIPE_H

#include <fstream>
#include "ingredient.h"
#include "xobj.h"

// Recipe_Name;
// UUID;
// Recipe Name;
// PrepTime(minutes);
// CookTime(minutes);
// CookType;
// CookTemp;
// Ingredient List: UUID|#|Volume,...;
// Nested Recipe List: UUID|#|Volume,...;
// Instruction List: Do thing1|Do thing2|Do thing3|consume!|...;

class Recipe : public xObject {
protected:
private:
  std::map<std::string, std::string> contains;
  std::vector<std::string> instructions;
  std::string cooktemp;
  int cooktime;
  int preptime;
  int cooktimemax;

public:
  Recipe();
  Recipe(std::string);
  Recipe(std::string,std::string);
  int ingredient_count();
  int insert_ingredient(std::string,std::string); 
  int remove_ingredient(std::string);
  void set_ingredients(std::vector<std::string>);
  void set_cooktime(int);
  void set_cooktemp(std::string);
  void set_preptime(int);
  void set_nested_recipes(std::vector<std::string>);
  int get_cooktime();
  std::string get_cooktemp();
  int get_preptime();
  void set_instructions(std::vector<std::string>);
  void user_input_instructions();
  void display_instructions(bool);
  void display_ingredients(bool);
  ~Recipe();
};

#endif // RECIPE_H //
