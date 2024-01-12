
#include "cookbooktest.h"

CookBookTest::CookBookTest() { 
  this->cookbook = new CookBook("test"); 
  this->test_all();
}

void CookBookTest::test_all() {
  this->caseIngestCookBook();
}

void CookBookTest::caseIngestCookBook() {
  this->cookbook->read_in_recipe();
  // this->cookbook
  assert(this->cookbook->get_book_size() == 7);
  printf("CookBook Test!\n");
}

CookBookTest::~CookBookTest() {}
