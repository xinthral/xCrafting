#ifndef XSQLITE_H
#define XSQLITE_H

#include <sqlite3.h>
#include "xobj.h"

class Database : public xObject {
protected:
  sqlite3* db;

private:
  std::string dbname;

public:
  Database();
  Database(std::string);
  int open_database();
  ~Database();
};

#endif // XSQLITE_H //