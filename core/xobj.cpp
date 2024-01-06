#include "xobj.h"

/*!
 * @brief   Default Constructor
*/
xObject::xObject() { this->name = Utilz::randomString(6); }

/*!
 * @brief   
*/
xObject::xObject(int id) : xObject() { 
  if (id >= 0) { printf("Internal ID Must be < 0: %d\n", this->xid); exit(-1); }
  int r = this->set_xid(id);
  if (r != id) { printf("ID Input Failure: %d\n", r); exit(-1); }
}

/*!
 * @brief   
*/
xObject::xObject(int id, std::string rename) :xObject(id) {
  this->set_xid(id);
  this->set_name(rename);
}

/*!
 * @brief   
*/
size_t xObject::set_name(std::string rename) { this->name = rename; return this->name.size(); }
std::string xObject::get_name() { return this->name; }

int xObject::get_xid() { return this->xid; }
int xObject::set_xid(int id) { this->xid = id; return this->xid; }

/*!
 * @brief   Default Deconstructor
*/
xObject::~xObject() { }
