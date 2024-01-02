#ifndef RECIPE_H
#define RECIPE_H

#include <stdio.h>
#include <string>
#include "xobj.h"

class Recipe : public xObject {
protected:
private:
public:
  Recipe();
  Recipe(int);
  ~Recipe();
};

#endif // RECIPE_H //