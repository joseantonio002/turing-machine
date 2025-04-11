#include "turing_machine.h"

turing_machine::turing_machine(string filename) {
  ifstream ifile(filename);
  if (!ifile) {
    cerr << "Error, could not open the file with the instance" << std::endl;
  }
  string line;
  // ignoramos los comentarios en la cabecera
  while(getline(ifile, line) && line[0] == '#') {
    //cout << line;
  } 
  valid_states = split_string(line); // estados posibles
  getline(ifile, line);
  string_alphabet = split_string(line); // alfabeto de la cadena
  getline(ifile, line);
  tape_alphabet = split_string(line); // alfabeto de la cinta
  getline(ifile, line);
  starting_state = line; // estado inicial
  // comprueba si el estado inicial pertenece al conjunto de estados
  check_state(starting_state);
  getline(ifile, line);
  final_states = split_string(line); // estados finales
  getline(ifile, line);
  number_tapes = stoi(line); // numero de cintas
  while(getline(ifile, line)) {
    vector<string> info_transition = split_string(line);
    check_state(info_transition[0]);
    check_state(info_transition[number_tapes + 1]);
    vector<string> rs;
    for(int i = 1 ; i < number_tapes + 1; i++) {
      check_tape_symbol(info_transition[i]);
      rs.push_back(info_transition[i]);
    }
    vector<simbol_movement> simbols_movements;
    for(int i = number_tapes + 2; i < info_transition.size(); i += 2) {
      check_tape_symbol(info_transition[i]);
      check_movement(info_transition[i + 1]);
      simbol_movement sm;
      sm.simbol = info_transition[i];
      sm.movement = info_transition[i + 1];
      simbols_movements.push_back(sm);
    }
    // estado inicial simbolos_leidos estado finas simbolo-movimiento para cada cinta
    transition_functiontm.add_transition(info_transition[0], rs, 
                       info_transition[number_tapes + 1], simbols_movements);
  }
}

void turing_machine::show_turing_machine() {
  cout << "Valid states: ";
  for(int i = 0; i < valid_states.size(); i++) {
    cout << valid_states[i] << " ";
  }
  cout << endl;
  cout << "String alphabet: ";
  for(int i = 0; i < string_alphabet.size(); i++) {
    cout << string_alphabet[i] << " ";
  }
  cout << endl;
  cout << "Tape alphabet: ";
  for(int i = 0; i < tape_alphabet.size(); i++) {
    cout << tape_alphabet[i] << " ";
  }
  cout << endl;
  cout << "Starting state: " << starting_state << endl;
  cout << "Final states: ";
  for(int i = 0; i < final_states.size(); i++) {
    cout << final_states[i] << " ";
  }
  cout << endl;
  cout << "Number of tapes: " << number_tapes << endl;
  transition_functiontm.show_transitions();
}

vector<string> turing_machine::read_tapes(vector<tape> tapes) {
    vector<string> read_symbols;
    for(int i = 0; i < number_tapes; i++) {
        read_symbols.push_back(tapes[i].read_tape());
    }
    return read_symbols;
}

bool turing_machine::analize_string(string input_string) {
  vector<tape> tapes;
  for(char c : input_string) check_input(c);
  if (input_string != ".") tapes.push_back(tape(input_string)); //tomo . como cadena vacia
  else tapes.push_back(tape());
  for(int i = 1; i < number_tapes; i++) {
    tapes.push_back(tape());
  }
  state current_state = starting_state;
  bool machine_stopped = false;
  while(!machine_stopped) {
    vector<string> read_symbols = read_tapes(tapes);
    transition_info ti = transition_functiontm.get_transition(current_state, read_symbols);
    if(ti.initial_state == STOPMACHINE) {
      machine_stopped = true;
    } else {
      current_state = ti.next_state;
      for(int i = 0; i < number_tapes; i++) {
        tapes[i].execute_action(ti.simbols_movements[i]);
      }
    }
  }
  cout << "Cintas: " << endl;
  for(int i = 0; i < number_tapes; i++) {
    tapes[i].show_tape();
  }
  for(int i = 0; i < final_states.size(); i++) {
    if(current_state == final_states[i]) {
      return true;
    }
  }
  return false;
}

void turing_machine::analize_file(string filename) {
  ifstream ifile(filename);
  if (!ifile) {
    cerr << "Error, could not open the file with the instance" << std::endl;
  }
  string line;
  while(getline(ifile, line)) {
    cout << "Cadena: " << line << endl;
    if(analize_string(line)) cout << "Aceptada" << endl;
    else cout << "Rechazada" << endl;
    cout << endl;
  }
}

bool turing_machine::check_state(state s) {
  for(int i = 0; i < valid_states.size(); i++) {
    if(s == valid_states[i]) {
      return true;
    }
  }
  cerr << "Error, the state " << s << " is not valid" << endl;
  exit(1);
}

bool turing_machine::check_tape_symbol(string s) {
  for(int i = 0; i < tape_alphabet.size(); i++) {
    if(s == tape_alphabet[i]) {
      return true;
    }
  }
  cerr << "Error, the tape symbol " << s << " is not valid" << endl;
  exit(1);
}

bool turing_machine::check_movement(string s) {
  if(s == LEFT || s == RIGHT || s == STOP) {
    return true;
  }
  cerr << "Error, the movement " << s << " is not valid" << endl;
  exit(1);
}

bool turing_machine::check_input(char c) {
  for(int i = 0; i < string_alphabet.size(); i++) {
    if(string(1, c) == string_alphabet[i]) {
      return true;
    }
  }
  cerr << "Error, the input " << c << " is not valid" << endl;
  exit(1);
}