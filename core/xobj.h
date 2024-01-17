#ifndef XOBJ_H
#define XOBJ_H

#define __FILENAME__ (__builtin_strrchr(__FILE__, '/') ? __builtin_strrchr(__FILE__, '/') + 1 : __FILE__)

#include <iostream>
#include <map>
#include <string>
#include "utilz.h"

class xObject {
protected:
  char buf[1024];
  int xid;
  std::string name;

private:
public:
  xObject();
  xObject(int);
  xObject(int,std::string);
  size_t set_name(std::string);
  std::string get_name();
  int get_xid();
  int set_xid(int);
  ~xObject();
};

#endif // XOBJ_H //
