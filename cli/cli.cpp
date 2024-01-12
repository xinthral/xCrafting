#include "cli.h"

int main(int argc, char const *argv[]) {
  CookBook book("test");
  Ingredient in1;
  Ingredient in2;
  Recipe nom(-3, "Milk");
  int r1 = nom.insert_ingredient("t1", in1);
  int r2 = nom.insert_ingredient("t2", in2);
  int r3 = nom.remove_ingredient("t2");
  nom.display_instructions(false);
  nom.display_ingredients(false);
  std::cout << "Names: " << in1.get_name() << " : " << in2.get_name() << std::endl;
  book.read_in_recipe();
  return 0;
}
