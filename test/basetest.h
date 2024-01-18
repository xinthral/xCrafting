#ifndef XCRAFTING_BASETEST_H
#define XCRAFTING_BASETEST_H

#include <assert.h>
#include <stdio.h>
#include "../core/cookbook.h"
#include "../core/ingredient.h"
#include "../core/recipe.h"
#include "../core/registry.h"
#include "../core/utilz.h"

class BaseTest {
protected:
  std::string msgHead;
  std::string msgBody;
  std::string msgTail;
  int count;

private:
public:
  BaseTest();
  BaseTest(int);
  void test_all();
  ~BaseTest();
};

#endif // XCRAFTING_BASETEST_H //