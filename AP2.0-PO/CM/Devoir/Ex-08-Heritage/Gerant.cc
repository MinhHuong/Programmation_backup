#include "Gerant.h"

Gerant::Gerant() {
  nb_employes = 0;
}

Gerant::Gerant(string nom, double salaire) 
  : Employe(nom,salaire) 
{ 
  nb_employes = 0;
}


void Gerant::ajouter() {
  nb_employes++;
}

int Gerant::getNbEmploye() const {
  return nb_employes;
}

double Gerant::getSalaire() const {
  return Employe::getSalaire() + 1000;
}
