#include "cookbooktest.h"

CookBookTest::CookBookTest() : BaseTest() {
  printf("\nTesting the CookBook Functionality!\n");
  this->msgHead = "Tested";
  this->msgTail = "from the CookBook successfully!";
  this->cookbook = new CookBook("test");
  this->cookbook->load_ingredients("test/test.ib");
  this->cookbook->load_recipes("test/test.rb");
  this->test_all();
}

void CookBookTest::test_all() {
  this->caseCheckIngredientRegistry();
  this->caseCheckRecipeRegistry();
}

void CookBookTest::caseCheckIngredientRegistry() {
  char buf[128];
  Ingredient ing("123-321-123");
  bool r = this->cookbook->register_ingredient(ing);
  assert(true == r);
  sprintf(buf, this->succMsg.c_str(), msgHead.c_str(), "ingredient uuid", ing.get_xid().c_str(), msgTail.c_str());
  printf("%s\n", buf);
}

void CookBookTest::caseCheckRecipeRegistry() {
  char buf[128];
  Recipe rec("132-213-132");
  bool r = this->cookbook->register_recipe(rec);
  assert(true == r);
  sprintf(buf, this->succMsg.c_str(), msgHead.c_str(), "recipe uuid", rec.get_xid().c_str(), msgTail.c_str());
  printf("%s\n", buf);
}

CookBookTest::~CookBookTest() {}
