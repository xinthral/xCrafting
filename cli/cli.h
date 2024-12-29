#ifndef XCRAFTING_CLI_H
#define XCRAFTING_CLI_H

#include <vector>
#include <stdio.h>
#include "../core/cookbook.h"
#include "../core/ingredient.h"
#include "../core/recipe.h"
#include "../core/registry.h"
#include "../core/utilz.h"

#include <unistd.h>

class CommandLine {
protected:
private:
  xRegistry* registrar;
  std::vector<int> _history;

public:
  CommandLine();
  void display_ingredients();
  void display_recipes();
  void injest_ingredient();
  void injest_recipe();
  void history();
  void append_history(int);
  ~CommandLine();
};

#endif // XCRAFTING_CLI_H //
