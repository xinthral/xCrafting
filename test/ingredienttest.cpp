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
  char buf[128];
  std::string name = Utilz::RandomString(6);
  std::string uuid = Utilz::CreateUUID();
  Ingredient ing(uuid, name);
  assert(ing.get_name() == name);
  sprintf(buf, this->succMsg.c_str(), this->msgHead.c_str(), "name", ing.get_name().c_str(), this->msgTail.c_str());
  printf("%s\n", buf);
}

void IngredientTest::test_newIngredientUUID() {
  char buf[128];
  std::string uuid = Utilz::CreateUUID();
  Ingredient ing(uuid);
  assert(ing.get_xid() == uuid);
  sprintf(buf, this->succMsg.c_str(), this->msgHead.c_str(), "uuid", ing.get_xid().c_str(), this->msgTail.c_str());
  printf("%s\n", buf);
}

void IngredientTest::test_newIngredientType() {
  char buf[128];
  Ingredient ing(Utilz::CreateUUID());
  std::string itype = "Protein";
  ing.set_type(itype);
  std::string rtype = ing.get_type();
  assert(strcmp(rtype.c_str(), itype.c_str()) == 0);
  sprintf(buf, this->succMsg.c_str(), this->msgHead.c_str(), "type", ing.get_type().c_str(), this->msgTail.c_str());
  printf("%s\n", buf);
}

void IngredientTest::test_newIngredientQuantity() {
  char buf[128];
  Ingredient ing;
  ing.set_quanitity(1);
  assert(1 == ing.get_quantity());
  sprintf(buf, this->succMsg.c_str(), this->msgHead.c_str(), "quantity", "1", this->msgTail.c_str());
  printf("%s\n", buf);
}

IngredientTest::~IngredientTest() {}
