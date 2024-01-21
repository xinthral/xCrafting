#include "ingredienttest.h"

IngredientTest::IngredientTest() { 
  printf("\nTesting the Ingredient Functionality!\n");
  this->msgHead = "Tested";
  this->msgTail = "for Ingredient successfully!";
  this->test_all(); 
}

void IngredientTest::test_all() {
  this->test_newIngredientName();
  this->test_newIngredientUUID();
  this->test_newIngredientType();
  this->test_newIngredientQuantity();
}

void IngredientTest::test_newIngredientName() {
  std::string name = Utilz::randomString(6);
  std::string uuid = Utilz::get_uuid();
  Ingredient ing(uuid, name);
  assert(ing.get_name() == name);
  printf("%s [%s (%s)] %s\n", msgHead.c_str(), "name", name.c_str(), msgTail.c_str());
}

void IngredientTest::test_newIngredientUUID() {
  std::string uuid = Utilz::get_uuid();
  Ingredient ing(uuid);
  assert(ing.get_xid() == uuid);
  printf("%s [%s (%s)] %s\n", msgHead.c_str(), "uuid", uuid.c_str(), msgTail.c_str());
}

void IngredientTest::test_newIngredientType() {
  Ingredient ing(Utilz::get_uuid());
  std::string itype = "Protein";
  ing.set_type(itype);
  std::string rtype = ing.get_type();
  assert(strcmp(rtype.c_str(), itype.c_str()) == 0);
  printf("%s [%s (%s)] %s\n", msgHead.c_str(), "type", "Protein", msgTail.c_str());
}

void IngredientTest::test_newIngredientQuantity() {
  Ingredient ing;
  ing.set_quanitity(1);
  assert(1 == ing.get_quantity());
  printf("%s [%s (%d)] %s\n", msgHead.c_str(), "quantity", ing.get_quantity(), msgTail.c_str());
}

IngredientTest::~IngredientTest() {}
