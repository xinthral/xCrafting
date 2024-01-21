#ifndef XCRAFTING_INGREDIENTTEST_H
#define XCRAFTING_INGREDIENTTEST_H

#include "basetest.h"

class IngredientTest : public BaseTest {
protected:
private:
public:
  IngredientTest();
  void test_all();
  void test_newIngredientName();
  void test_newIngredientUUID();
  void test_newIngredientType();
  void test_newIngredientQuantity();
  ~IngredientTest();
};
#endif // XCRAFTING_INGREDIENTTEST_H //
