#include "transition_function.h"

void transition_function::show_transitions() {
  for(int i = 0; i < num_trans; i++) {
    cout << "Transition " << i << endl;
    cout << "Initial state: " << transitions[i].initial_state << endl;
    cout << "Next state: " << transitions[i].next_state << endl;
    cout << "Read symbols: ";
    for(int j = 0; j < transitions[i].read_symbols.size(); j++) {
      cout << transitions[i].read_symbols[j] << " ";
    }
    cout << endl;
    cout << "Simbols movements: ";
    for(int j = 0; j < transitions[i].simbols_movements.size(); j++) {
      cout << transitions[i].simbols_movements[j].simbol << " ";
      cout << transitions[i].simbols_movements[j].movement << " ";
    }
    cout << endl;
  }
}

transition_info transition_function::get_transition(state current_state, vector<string> read_symbols) {
  for(int i = 0; i < num_trans; i++) {
    if(transitions[i].initial_state == current_state) {
      bool found = true;
      for(int j = 0; j < read_symbols.size(); j++) {
        if(transitions[i].read_symbols[j] != read_symbols[j]) {
          found = false;
          break;
        }
      }
      if(found) {
        return transitions[i];
      }
    }
  }
  transition_info ti;
  ti.initial_state = STOPMACHINE;
  ti.next_state = STOPMACHINE;
  return ti;
}

void transition_function::add_transition(state initial_state, vector<string> read_symbols, 
                                    state next_state, vector<simbol_movement> simbols_movements) {
    transition_info ti;
    ti.initial_state = initial_state;
    ti.next_state = next_state;
    ti.read_symbols = read_symbols;
    ti.simbols_movements = simbols_movements;
    this->transitions.push_back(ti);
    num_trans++;
}