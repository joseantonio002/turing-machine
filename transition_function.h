#ifndef TRANSITION
#define TRANSITION

#include "utils.h"


class transition_function {
 public:
  transition_function() {}
  void add_transition(state initial_state, vector<string> read_symbols, 
                                    state next_state, vector<simbol_movement> simbols_movements);
  transition_info get_transition(state current_state, vector<string> read_symbols);
  void show_transitions();

 private:
  vector<transition_info> transitions;
  int num_trans = 0;
};

#endif