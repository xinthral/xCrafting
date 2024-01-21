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
  std::string xid;
  std::string name;

private:
public:
  xObject();
  xObject(std::string);
  xObject(std::string,std::string);
  size_t set_name(std::string);
  std::string get_name();
  std::string get_xid();
  std::string set_xid(std::string);
  ~xObject();
};

#endif // XOBJ_H //
