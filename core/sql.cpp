#include "sql.h"

Database::Database(std::string name) {
    int exit = 0;
    this->dbname = name;
    this->open_database();
}

Database::Database() : Database("registrar.db") {}

int Database::open_database() {
  int response = sqlite3_open(this->dbname.c_str(), &(this->db));
  if (response) { std::cerr << "Error Opening Database: " << this->dbname << std::endl; }
  return response;
}

Database::~Database() { sqlite3_close(this->db); }
