#include "registrytest.h"

RegistryTest::RegistryTest() { 
  printf("Testing the Registry Functionality!\n");
  this->msgHead = "Tested";
  this->msgTail = "from the Registrar!";

  this->registrar = new xRegistry();
  this->test_all(); 
}

void RegistryTest::test_all() { this->test_ingestIngredients(); }

void RegistryTest::test_ingestIngredients() { 
  // this->registrar->parse_csv(0, "ingredients.csv"); 
  this->registrar->parse_csv(0, "test.csv"); 
  printf("%s [%s] %s\n", msgHead.c_str(), "injesting ingredients", msgTail.c_str());
}

RegistryTest::~RegistryTest() {}
