#ifndef XOBJ_H
#define XOBJ_H

#include <string>
#include "utilz.h"

class xObject {
protected:
  int xid;
  std::string name;
private:
public:
  xObject();
  xObject(int);
  xObject(int,std::string);
  size_t set_name(std::string);
  int get_xid();
  int set_xid(int);
  ~xObject();
};

#endif // XOBJ_H //