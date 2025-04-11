#ifndef TURINGMACHINE
#define TURINGMACHINE

#include "transition_function.h"
#include "tape.h"


class turing_machine {
 public:
  turing_machine(string filename);
  void show_turing_machine();
  bool analize_string(string input_string);
  void analize_file(string filename);
 private:
  //vector<tape> tapes;
  transition_function transition_functiontm;
  vector<state> valid_states;
  vector<string> string_alphabet;
  vector<string> tape_alphabet;
  state starting_state;
  vector<state> final_states;
  int number_tapes;
  vector<string> read_tapes(vector<tape> tapes);
  bool check_state(state s);
  bool check_tape_symbol(string s);
  bool check_movement(string m);
  bool check_input(char c);
};








#endif