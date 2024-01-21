#include "recipetest.h"

RecipeTest::RecipeTest() : BaseTest() {
  printf("\nTesting the Recipe Functionality!\n");
  this->msgHead = "Tested";
  this->msgTail = "for a Recipe successfully!";
  this->test_all();
}

// void RecipeTest::test_all() {}

RecipeTest::~RecipeTest() {}
