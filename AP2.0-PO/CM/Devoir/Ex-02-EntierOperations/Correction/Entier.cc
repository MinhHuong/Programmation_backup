#include "Entier.h"

Entier::Entier() {
  my_valeur = -1;
}

Entier::Entier(int valeur) {
  my_valeur = valeur;
}

Entier::Entier(const Entier &ent) {
  my_valeur = ent.my_valeur;
}

void Entier::init(int valeur) {
  my_valeur = valeur;
}

void Entier::plus(int valeur) {
  cout << my_valeur << " + " << valeur << " = " << my_valeur+valeur << endl;
}

void Entier::moins(int valeur) {
  cout << my_valeur << " - " << valeur << " = " << my_valeur-valeur << endl;
}

void Entier::fois(int valeur) {
  cout << my_valeur << " * " << valeur << " = " << my_valeur*valeur << endl;
}

void Entier::diviser(int valeur) {
  if (valeur != 0)
    cout << my_valeur << " / " << valeur << " = " << my_valeur/valeur << endl;
  else
    cout << "Division impossible" << endl;
}

Entier Entier::operator+(const Entier &ent) {
  Entier result;
  result.my_valeur = my_valeur + ent.my_valeur;
  return result;
}

int Entier::getValeur() {
  return my_valeur;
}
