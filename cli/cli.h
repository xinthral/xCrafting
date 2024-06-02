#ifndef XCRAFTING_CLI_H
#define XCRAFTING_CLI_H

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

public:
  CommandLine();
  void display_ingredients();
  void display_recipes();
  void injest_ingredient();
  void injest_recipe();
  ~CommandLine();
};

#endif // XCRAFTING_CLI_H //
