#include "cli.h"

void TestCookBook() { CookBookTest* book = new CookBookTest(); }
void TestIngredient() { IngredientTest* item = new IngredientTest(); }
void TestRecipe() { RecipeTest* steps = new RecipeTest(); }
void TestRegistry() { RegistryTest* registrar = new RegistryTest(); }
void TestUtilz() { UtilzTest* utilz = new UtilzTest(); }

int get_choice(char* input) {
  errno = 0;
  char* p;
  long conv = strtol(input, &p, 10);
  if (*p != '\0' || errno != 0) { return -1; }
  if (std::abs(conv) > INT_MAX - 2) { return -2; }
  return (int)conv;
}

void print_usage() {
  printf("\n%s [option]\n", __FILE__);
}

void print_help() {
  print_usage();
  printf("\nHelp Options:\n");
  printf("  -h :Display Help Menu\n");
  printf("   0 :Test Them all\n");
  printf("   1 :Test CookBook\n");
  printf("   2 :Test Ingredient\n");
  printf("   3 :Test Recipe\n");
  printf("   4 :Test Registry\n");
  printf("   5 :Test Utilz\n");
  printf("\n");
}

int main(int argc, char *argv[], char* envp[]) {

  if (argc < 2) { print_help(); return -1; }
  int choice = get_choice(argv[1]);
  // if ((choice = get_choice(argv[1])) < -5) { return -1; }
  // printf("Choice: %d\n", choice);
  switch(choice) {
    case 0:
      TestCookBook();
      TestIngredient();
      TestRecipe();
      TestRegistry();
      TestUtilz();
      break;
    case 1:
      TestCookBook();
      break;
    case 2:
      TestIngredient();
      break;
    case 3:
      TestRecipe();
      break;
    case 4:
      TestRegistry();
      break;
    case 5:
      TestUtilz();
      break;
    default:
      printf("This is not the test you were looking for!\n");
      break;
  }
  return 0;
}
