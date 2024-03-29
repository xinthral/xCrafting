#ifndef UTILZ_H
#define UTILZ_H

#include <algorithm>
#include <ctime>
#include <iterator>
#include <random>
#include <stdio.h>
#include <string>
#include <string.h>
#include <vector>

namespace Utilz {
  std::string FileName(const char *);
  std::string FileName(int, const char *);
  std::string TimeStamp();
  void StringToArray(std::string, std::vector<std::string>&);
  std::string HeadString(int, std::string);
  std::string TailString(int, std::string);
  void Strip(std::string&);
  std::string randomString(int);
  std::string get_uuid();
}; // namespace Utilz

extern "C" {
  int addIt(int, int);
};

#endif // UTILZ_H //
