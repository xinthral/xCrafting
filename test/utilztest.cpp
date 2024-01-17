#include "utilztest.h"

/*!
 * @def     __FILENAME__ 
 * @brief   Translate Filename to reusable macro
*/
#define __FILENAME__ (__builtin_strrchr(__FILE__, '/') ? __builtin_strrchr(__FILE__, '/') + 1 : __FILE__)

UtilzTest::UtilzTest() {
  printf("Testing the Utilz Functionality!\n");
  this->msgHead = "Tested";
  this->msgTail = "for Utilz!";
  this->test_all();
}

void UtilzTest::test_all() {
  this->test_StringToArray();
  this->test_StringToArray_TrailingSpace();
  this->test_NewUuid();
}

void UtilzTest::test_StringToArray() {
  std::string testline = "this is a test";
  std::vector<std::string> cmds;
  Utilz::StringToArray(testline, cmds);
  assert(cmds.size() == 4);
  printf("%s [%s] %s\n", msgHead.c_str(), "StringToArray", msgTail.c_str());
}

void UtilzTest::test_StringToArray_TrailingSpace() {
  std::string testline = "this is a test ";
  std::vector<std::string> cmds;
  Utilz::StringToArray(testline, cmds);
  assert(cmds.size() == 4);
  printf("%s [%s] %s\n", msgHead.c_str(), "StringToArray Trailing Space", msgTail.c_str());
}

void UtilzTest::test_NewUuid() {
  std::string resposne = Utilz::get_uuid();
  printf("%s [%s] %s\n", msgHead.c_str(), resposne.c_str(), msgTail.c_str());
}

UtilzTest::~UtilzTest() { }
