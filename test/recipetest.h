#ifndef XCRAFTING_RECIPETEST_H
#define XCRAFTING_RECIPETEST_H

#include "basetest.h"

class RecipeTest : public BaseTest {
protected:
private:
public:
  RecipeTest();
  void test_all();
  void test_id_recipe();
  void test_named_recipe();
  void test_set_cooktime();
  ~RecipeTest();
};

#endif // XCRAFTING_RECIPETEST_H //