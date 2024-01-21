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
}

void RegistryTest::test_ingestIngredients() { 
  this->registrar->parse_csv(1, "test/test.ib"); 
  printf("%s [%s] %s\n", msgHead.c_str(), "injesting ingredients", msgTail.c_str());
}

void RegistryTest::test_ingestRecipes() { 
  this->registrar->parse_csv(2, "test/test.rb"); 
  printf("%s [%s] %s\n", msgHead.c_str(), "injesting recipes", msgTail.c_str());
}

RegistryTest::~RegistryTest() {}
