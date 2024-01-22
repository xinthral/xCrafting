#include "registrytest.h"

RegistryTest::RegistryTest() : BaseTest() { 
  printf("\nTesting the Registry Functionality!\n");
  this->msgHead = "Tested";
  this->msgTail = "from the Registrar!";

  this->registrar = new xRegistry();
  this->test_all(); 
}

void RegistryTest::test_all() { 
  this->test_ingestIngredients(); 
  this->test_ingestRecipes();
  this->test_verificationIngredient();
  this->test_verificationRecipe();
}

void RegistryTest::test_ingestIngredients() { 
  this->registrar->parse_csv(1, "test/test.ib"); 
  this->registrar->display_ingredients();
  printf("%s [%s] %s\n", msgHead.c_str(), "injesting ingredients", msgTail.c_str());
}

void RegistryTest::test_ingestRecipes() { 
  this->registrar->parse_csv(2, "test/test.rb"); 
  this->registrar->display_recipes();
  printf("%s [%s] %s\n", msgHead.c_str(), "injesting recipes", msgTail.c_str());
}

void RegistryTest::test_verificationIngredient() {
  Ingredient ing("012-234-456", "test_verificationIngredient");
  this->registrar->add_ingredient(ing);
  assert(this->registrar->verify_ingredient(ing) == false);
  printf("%s [%s] %s\n", msgHead.c_str(), "verified ingredient", msgTail.c_str());
}

void RegistryTest::test_verificationRecipe() {
  Recipe rec("654-432-210", "test_verificationRecipe");
  this->registrar->add_recipe(rec);
  assert(this->registrar->verify_recipe(rec) == false);
  printf("%s [%s] %s\n", msgHead.c_str(), "verified recipe", msgTail.c_str());
}

RegistryTest::~RegistryTest() {}
