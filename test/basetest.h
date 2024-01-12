#ifndef XCRAFTING_BASETEST_H
#define XCRAFTING_BASETEST_H

#include <assert.h>
#include <stdio.h>
#include "../core/cookbook.h"
#include "../core/ingredient.h"
#include "../core/recipe.h"

class BaseTest {
protected:
private:
public:
  BaseTest();
  void test_all();
  ~BaseTest();
};

#endif // XCRAFTING_BASETEST_H //