#include "cli.h"

int main(int argc, char const *argv[]) {
  xRegistry registrar;
  CookBook book("test.rb");
  Ingredient in1;
  Ingredient in2;
  Recipe nom(-3, "Milk");

  registrar.parse_csv(0, "ingredients.csv");
  // int r1 = nom.insert_ingredient("t1", in1);
  // int r2 = nom.insert_ingredient("t2", in2);
  // int r3 = nom.remove_ingredient("t2");
  // nom.display_instructions(false);
  // nom.display_ingredients(false);
  // std::cout << "Names: " << in1.get_name() << " : " << in2.get_name() << std::endl;
  
  return 0;
}
