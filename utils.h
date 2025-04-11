#ifndef UTILS
#define UTILS


#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <stdlib.h> 

using namespace std;

typedef string state;

const state STOPMACHINE = "STOPMACHINE";
const string BLANK = ".";
const string LEFT = "L";
const string RIGHT = "R";
const string STOP = "S";



std::vector<std::string> split_string(const std::string &input);

struct simbol_movement {
  string simbol;
  string movement;
};

struct transition_info
{
  state initial_state;
  state next_state;
  vector<string> read_symbols;
  vector<simbol_movement> simbols_movements; 
};


#endif