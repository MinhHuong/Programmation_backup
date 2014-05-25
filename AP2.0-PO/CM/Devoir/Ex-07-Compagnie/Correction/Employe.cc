#include "Employe.h"

Employe::Employe() : nom_("") {
  cout << "Employe : constructeur par defaut" << endl;
}

Employe::Employe(string nom) : nom_(nom) {
  cout << "Employe : constructeur avec parametre" << endl;
}

Employe::~Employe() {
  cout << "Employe : destructeur" << endl;
}

void Employe::setNom(string nom) {
  nom_ = nom;
}

void Employe::travailler() const {
  cout << "Je suis " << nom_ << " et je vais travailler" << endl;
}
