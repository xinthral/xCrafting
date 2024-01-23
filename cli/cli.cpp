#include "cli.h"

int main(int argc, char const *argv[]) {
  xRegistry registrar;
  CookBook book("test.rb");
  Ingredient in1;
  Ingredient in2;
  Recipe nom(Utilz::get_uuid(), "Milk");

  registrar.parse_csv(1, "core.ib");
  registrar.parse_csv(2, "core.rb");
  registrar.display_ingredients();
  registrar.display_recipes();
  
  return 0;
}
