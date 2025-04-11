#ifndef TAPE
#define TAPE

#include "utils.h"


class tape {
 public:
  tape(string entrada = " ");
  void execute_action(simbol_movement sm);
  void show_tape();
  string read_tape();
 private:
  int current_pos;
  vector<string> positive_tape;
  vector<string> negative_tape;
};

#endif