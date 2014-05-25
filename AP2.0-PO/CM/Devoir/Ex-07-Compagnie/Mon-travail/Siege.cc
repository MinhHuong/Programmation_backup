#include "Siege.h"

Siege::Siege() : my_pays("Non renseigne") {
  cout << "Siege : constructeur par defaut" << endl;
}

Siege::Siege(string pays) : my_pays(pays) {
  cout << "Siege : constructeur avec parametre" << endl;
}

Siege::~Siege() {
  cout << "Siege : destructeur" << endl;
}

void Siege::setPays(string pays) {
  my_pays = pays;
}

string Siege::getPays() const {
  return my_pays;
}
