#include "registrytest.h"

RegistryTest::RegistryTest() : BaseTest() { 
  printf("\nTesting the Registry Functionality!\n");
  this->msgHead = "Tested";
  this->msgTail = "from the Registrar!";

  this->registrar = new xRegistry();
  this->registrar->parse_csv(1, "test/test.ib"); 
  this->registrar->parse_csv(2, "test/test.rb"); 
  this->test_all(); 
}

void RegistryTest::test_all() { 
  this->test_ingestIngredients(); 
  this->test_ingestRecipes();
  this->test_verificationIngredient();
  this->test_verificationRecipe();
}

void RegistryTest::test_ingestIngredients() {
  char buf[128];
  // this->registrar->display_ingredients();
  sprintf(buf, this->succMsg.c_str(), msgHead.c_str(), "injesting ingredients", msgTail.c_str());
  printf("%s\n", buf);
}

void RegistryTest::test_ingestRecipes() { 
  char buf[128];
  // this->registrar->display_recipes();
  sprintf(buf, this->succMsg.c_str(), msgHead.c_str(), "injesting recipes", msgTail.c_str());
  printf("%s\n", buf);
}

void RegistryTest::test_verificationIngredient() {
  char buf[128];
  Ingredient ing("012-234-456", "test_verificationIngredient");
  this->registrar->add_ingredient(ing);
  assert(this->registrar->verify_ingredient(ing) == false);
  sprintf(buf, this->succMsg.c_str(), msgHead.c_str(), "verified ingredient", msgTail.c_str());
  printf("%s\n", buf);
}

void RegistryTest::test_verificationRecipe() {
  char buf[128];
  Recipe rec("654-432-210", "test_verificationRecipe");
  this->registrar->add_recipe(rec);
  assert(this->registrar->verify_recipe(rec) == false);
  sprintf(buf, this->succMsg.c_str(), msgHead.c_str(), "verified recipe", msgTail.c_str());
  printf("%s\n", buf);
}

RegistryTest::~RegistryTest() {}
