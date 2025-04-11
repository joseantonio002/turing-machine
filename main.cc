#include "turing_machine.h"

int main() {
  string machine_file;
  string input_file;
  cout << "Introduce el nombre del fichero de la maquina de turing: ";
  cin >> machine_file;
  cout << "Introduce el nombre del fichero de las cadenas a analizar: ";
  cin >> input_file;
  turing_machine tm(machine_file);
  //tm.show_turing_machine();
  tm.analize_file(input_file);
  return 0;
}