#ifndef XCRAFTING_REGISTRYTEST_H
#define XCRAFTING_REGISTRYTEST_H

#include "basetest.h"

class RegistryTest : public BaseTest {
protected:
private:
  xRegistry* registrar;

public:
  RegistryTest();
  void test_all();
  void test_ingestIngredients();
  ~RegistryTest();
};

#endif // XCRAFTING_REGISTRYTEST_H //