#ifndef XCRAFTING_BOTW_H
#define XCRAFTING_BOTW_H

#include <vector>
#include <stdio.h>
#include "../core/cookbook.h"
#include "../core/ingredient.h"
#include "../core/recipe.h"
#include "../core/registry.h"
#include "../core/utilz.h"

class CommandLine {
protected:
private:
  xRegistry* registrar;
  std::vector<std::string> _history;

public:
  CommandLine();
  void display_ingredients();
  void display_recipes();
  void injest_ingredient();
  void injest_recipe();
  void history();
  ~CommandLine();
};
#endif // XCRAFTING_BOTW_H //
