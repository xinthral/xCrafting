#include "recipetest.h"

RecipeTest::RecipeTest() : BaseTest() {
  printf("\nTesting the Recipe Functionality!\n");
  this->msgHead = "Tested";
  this->msgTail = "for a Recipe successfully!";
  this->test_all();
}

void RecipeTest::test_all() {
  this->test_named_recipe();
  this->test_id_recipe();
  this->test_set_cooktime();
}

void RecipeTest::test_id_recipe() {
  char buf[128];
  std::string uuid = Utilz::CreateUUID();
  Recipe* recipe = new Recipe(uuid);
  assert(recipe->get_xid() == uuid);
  sprintf(buf, this->succMsg.c_str(), this->msgHead.c_str(), "uuid", recipe->get_xid().c_str(), this->msgTail.c_str());
  printf("%s\n", buf);
}

void RecipeTest::test_named_recipe() {
  char buf[128];
  std::string uuid = Utilz::CreateUUID();
  std::string name = "MaxSnax";
  Recipe* recipe = new Recipe(uuid, name);
  assert(recipe->get_name() == name);
  sprintf(buf, this->succMsg.c_str(), this->msgHead.c_str(), "name", recipe->get_name().c_str(), this->msgTail.c_str());
  printf("%s\n", buf);
}

void RecipeTest::test_set_cooktime() {
  char buf[128];
  int ct = 1800;
  Recipe* recipe = new Recipe();
  recipe->set_cooktime(ct);
  assert (ct == recipe->get_cooktime());
  sprintf(buf, this->succMsg.c_str(), this->msgHead.c_str(), "cooktime", std::to_string(recipe->get_cooktime()).c_str(), this->msgTail.c_str());
  printf("%s\n", buf);
}

RecipeTest::~RecipeTest() {}
