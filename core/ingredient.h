#ifndef INGREDIENT_H
#define INGREDIENT_H

#include <string>
#include "utilz.h"
#include "xobj.h"

class Ingredient : public xObject {
protected:
  enum Type { Seasoning, Protien, Produce, Craft };
  int quantity;
private:
public:
  Ingredient();
  Ingredient(int);
  Ingredient(int,std::string);
  ~Ingredient();
};

#endif // INGREDIENT_H //
