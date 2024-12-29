#include "xobj.h"

/*!
 * @brief   Default Constructor
*/
xObject::xObject() { 
  this->set_xid(Utilz::get_uuid());
  this->set_name(Utilz::randomString(6));
  this->prompt = ">>";
}

xObject::xObject(std::string id) { 
  if (id.empty()) { printf("Internal UUID cannot be NULL: %s\n", this->xid.c_str()); exit(-1); }
  std::string r = this->set_xid(id);
  if (strcmp(r.c_str(), id.c_str()) != 0) { printf("ID Input Failure: %s\n", r.c_str()); exit(-1); }
  this->set_name(Utilz::randomString(6));
  this->prompt = ">>";
}

xObject::xObject(std::string id, std::string name) {
  this->set_xid(id);
  this->set_name(name);
  this->prompt = ">>";
}

std::string xObject::get_name() { return this->name; }
std::string xObject::get_prompt() { return this->prompt; }
std::string xObject::get_xid() { return this->xid; }
size_t xObject::set_name(std::string rename) { this->name = rename; return this->name.size(); }
size_t xObject::set_prompt(std::string reprompt) { this->prompt = reprompt; return this->prompt.size(); }
std::string xObject::set_xid(std::string id) { this->xid = id; return this->xid; }

/*!
 * @brief   Default Deconstructor
*/
xObject::~xObject() { }
