#include "Secretaire.h"
using namespace std;

Secretaire::Secretaire() {
  salaire_sec = 0.0;
}

Secretaire::Secretaire(string nom, int age)
  : Employe(nom,age) { }

Secretaire::~Secretaire() { }

void Secretaire::set_salaire(double salaire) {
  salaire_sec = salaire;
}

string Secretaire::get_type() const {
  return "Secretaire";
}
