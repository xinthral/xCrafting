#include "cli.h"

int main(int argc, char const *argv[]) {
  Ingredient in1(-1);
  Ingredient in2(-2);
  Recipe nom(-3);
  int r1 = nom.insert_ingredient("t1", in1);
  int r2 = nom.insert_ingredient("t2", in2);
  int r3 = nom.remove_ingredient("t2");
  printf("%d / %d / %d\n", r1, r2, r3);
  return 0;
}
