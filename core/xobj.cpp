#include "xobj.h"

xObject::xObject() : xObject(Utilz::CreateUUID(), Utilz::RandomString(6)) {}

xObject::xObject(std::string id) : xObject(id, Utilz::RandomString(6)) {}

xObject::xObject(std::string id, std::string name) {
  if (id.empty()) { printf("Internal UUID cannot be NULL: %s\n", this->xid.c_str()); exit(-1); }
  if (name.empty()) { printf("Name cannot be NULL: %s\n", name.c_str()); exit(-1); }
  this->set_xid(id);
  this->set_name(name);
  this->prompt = ">>";
}

std::string xObject::get_name() {
  return this->name;
}

std::string xObject::get_prompt() {
  return this->prompt;
}

std::string xObject::get_xid() {
  return this->xid;
}

size_t xObject::set_name(std::string rename) {
  this->name = rename;
  return this->name.size();
}

size_t xObject::set_prompt(std::string reprompt) {
  if (reprompt.empty()) {
    this->prompt = ">> ";
  } else {
    this->prompt = reprompt;
  }
  return this->prompt.size();
}

std::string xObject::set_xid(std::string id) {
  this->xid = id;
  return this->xid;
}

xObject::~xObject() {}
