#include "Siege.h"

Siege::Siege() {
  my_pays = "";
  cout << "Siege : constructeur par defaut" << endl;
}

Siege::Siege(string pays) {
  my_pays = pays;
  cout << "Siege : constructeur avec parametre" << endl;
}

Siege::~Siege() {
  cout << "Siege : destructeur" << endl;
}

string Siege::getSiege() const {
  return my_pays;
}
