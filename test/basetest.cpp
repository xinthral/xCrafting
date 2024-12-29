#include "basetest.h"

BaseTest::BaseTest() : succMsg("%s [%s (%s)] %s") {}

BaseTest::BaseTest(int testCount) : count(testCount) {}

void BaseTest::test_all() { printf("BaseTest::test_all needs to be overloaded!\n"); }

BaseTest::~BaseTest() {}
