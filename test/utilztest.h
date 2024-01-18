#ifndef UTILZTEST_H
#define UTILZTEST_H

#include "basetest.h"

class UtilzTest : public BaseTest {
protected:
private:
public:
  UtilzTest();
  void test_all();
  void test_StringToArray();
  void test_StringToArray_TrailingSpace();
  void test_NewUuid();
  ~UtilzTest();
};

#endif // UTILZTEST_H //