#ifndef INGREDIENT_H
#define INGREDIENT_H

#include <string>
#include "utilz.h"
#include "xobj.h"

class Ingredient : public xObject {
protected:
  enum Type { Seasoning, Protein, Produce, Craft };
  int quantity;
private:
public:
  Ingredient();
  Ingredient(int);
  ~Ingredient();
};

#endif // INGREDIENT_H //
