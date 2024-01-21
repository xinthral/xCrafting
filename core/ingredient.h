#ifndef INGREDIENT_H
#define INGREDIENT_H

#include <string>
#include "utilz.h"
#include "xobj.h"


class Ingredient : public xObject {
protected:
private:
  int quantity;
  std::string location;
  std::vector<std::string> provides;
  std::string _type;

public:
  static const std::string IName[5];
  Ingredient();
  Ingredient(std::string);
  Ingredient(std::string,std::string);
  Ingredient(std::string,std::string,int);
  Ingredient(std::string,std::string,int,std::string);
  std::string get_type();
  int set_type(std::string);
  int get_quantity();
  void set_quanitity(int);
  std::string get_location();
  void set_location(std::string);
  int add_provides(std::string);
  int provides_length();
  void display_provides();
  std::string type_repr(int);
  ~Ingredient();
};

#endif // INGREDIENT_H //
