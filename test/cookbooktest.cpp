
#include "cookbooktest.h"

CookBookTest::CookBookTest() { 
  this->cookbook = new CookBook("test"); 
  this->test_all();
}

void CookBookTest::test_all() {
  // this->caseIngestCookBook();
  // this->caseCheckRegistry();
}

// void CookBookTest::caseIngestCookBook() {
//   this->cookbook->check_registry
//   assert(this->cookbook->get_book_size() == 7);
//   printf("Passed :: CookBook Injested Recipes!\n");
// }

// void CookBookTest::caseCheckRegistry() {
//   bool resp;
//   Ingredient ing(-9, "Test9");
//   this->cookbook->register_ingredient(ing);
//   resp = this->cookbook->check_registry(&ing);
//   assert(resp == true);
//   printf("Passed :: CookBook Registry Check!\n");
// }

CookBookTest::~CookBookTest() {}
