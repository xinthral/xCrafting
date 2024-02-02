#include "utilz.h"

std::string Utilz::FileName(const char* file) {
  std::string fileName = file;
  size_t pos = fileName.find(".");
  return fileName.substr(0, pos);
}

std::string Utilz::FileName(int length, const char* file) {
  std::string output = Utilz::FileName(file);
  return Utilz::HeadString(length, output);
}

std::string Utilz::TimeStamp() {
  std::time_t time = std::time({});
  char output[std::size("ddd mmm dd hh:mm:ss")];
  std::string fmtString = "%a %b %d %T";
  std::strftime(
    std::data(output), 
    std::size(output), 
    fmtString.c_str(), 
    std::localtime(&time)
  );
  return output;
}

void Utilz::StringToArray(std::string input, std::vector<std::string>& output) {
  char* token = strtok(const_cast<char*>(input.c_str()), " \r\n");
  while (token != NULL) {
    output.push_back(token);
    token = strtok(NULL, " \r\n");
  }
}

std::string Utilz::HeadString(int length, std::string input) {
  std::string output = input;
  output.resize(length);
  return output;
}

std::string Utilz::TailString(int length, std::string input) {
  std::string output;
  size_t l = input.size() - length;
  for (size_t i = l; i < input.size(); i++) { output += input[i]; }
  return output;
}

void Utilz::Strip(std::string& input) {
  std::string::iterator pos = std::remove(input.begin(), input.end(), ' ');
  input.erase(pos, input.end());
}

std::string Utilz::randomString(int length) {
  std::srand(std::time({}));
  std::string lexigraph = "AaBbCcDdEeFfGgHhIiJjKkLlMmNnOoPpQqRrSsTtUuVvWwXxYyZz";
  std::string output = "";
  int idx = -1;
  for (int i = 0; i < length; i++) {
    idx = 1 + rand() % lexigraph.size();
    output += lexigraph[idx];
  }
  return output;
}

std::string Utilz::get_uuid() {
  const char *hex = "0123456789AaBbCcDdEeFf";
  const bool formatted[] = { 0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0 };
  std::string newuuid;
  std::random_device dev;
  std::mt19937 rng(dev());
  std::uniform_int_distribution<int> dist(0, 21);

  for (int i = 0; i < 16; i++) {
      if (formatted[i]) newuuid += "-";
      newuuid += hex[dist(rng)];
      newuuid += hex[dist(rng)];
  }
  return newuuid ;
}

void Utilz::FilePathConversion(int direction, std::string& filename) {
  size_t pos = 0;
  if (direction == 1) {
    // Dos2Unix
    while ((pos = filename.find("\\\\", pos)) != std::string::npos) {
      filename.replace(pos, 2, "/");
      pos += 1; // Move past the inserted backslash
    }
  } else {
    // Unix2Dos
    while ((pos = filename.find('/', pos)) != std::string::npos) {
      filename.replace(pos, 1, "\\");
      pos += 2; // Move past the inserted backslash
    }
  }
}