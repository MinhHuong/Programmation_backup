#include "Employe.h"

Employe::Employe()
  : e_nom ("nom"), e_salaire(0.0)
{ }

Employe::Employe(string nom, double salaire)
  : e_nom(nom), e_salaire(salaire)
{ }

void Employe::setSalaire(double salaire) {
  e_salaire = salaire;
}

double Employe::getSalaire() const {
  return e_salaire;
}

string Employe::getNom() const {
  return e_nom;
}
