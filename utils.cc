#include "utils.h"


std::vector<std::string> split_string(const std::string &input) {
  std::vector<std::string> result;
  std::istringstream iss(input);
  std::string word;
  while (iss >> word) {
    result.push_back(word);
  }
  return result;
}