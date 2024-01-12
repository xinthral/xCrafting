#include "cli.h"

void TestCookBook() { CookBookTest* book = new CookBookTest(); }
void TestIngredient() { IngredientTest* item = new IngredientTest(); }
void TestRecipe() { RecipeTest* steps = new RecipeTest(); }

int main(int argc, char const *argv[]) {
  TestCookBook();
  return 0;
}
