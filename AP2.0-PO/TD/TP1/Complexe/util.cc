#include "util.h"
#include <string>
#include <sstream>
#include <iostream>

using namespace std;

string intToString(int x) {
  ostringstream oss;
  oss << x;
  string s = oss.str();
  return s;
}


void menu() {
  cout << "\n----------*** LES NOMBRES COMPLEXES ***----------\n\n"
       << "   1. Ecrire un nombre complexe\n"
       << "   2. Afficher le nombre\n"
       << "   3. Additionner\n"
       << "   4. Multiplier\n\n"
       << "-------------------------------------------------\n";
}
