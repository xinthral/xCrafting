
#include "cookbooktest.h"

CookBookTest::CookBookTest() : BaseTest() { 
  printf("\nTesting the CookBook Functionality!\n");
  this->msgHead = "Tested";
  this->msgTail = "from the CookBook successfully!";
  this->cookbook = new CookBook("test"); 
  this->test_all();
}

// void CookBookTest::test_all() {}

CookBookTest::~CookBookTest() {}
