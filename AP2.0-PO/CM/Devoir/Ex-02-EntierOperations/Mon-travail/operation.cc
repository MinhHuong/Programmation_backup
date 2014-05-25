#include "operation.h"

Entier::Entier() {
  nb_1 = 0;
  nb_2 = 0;
}

Entier::Entier(int nb1, int nb2) {
  nb_1 = nb1;
  nb_2 = nb2;
}

void Entier::init(int op1, int op2) {
  nb_1 = op1; 
  nb_2 = op2;
}

void Entier::plus() {
  cout << nb_1 << " + " << nb_2 << " = " << nb_1+nb_2 << endl;
}

void Entier::moins() {
  cout << nb_1 << " - " << nb_2 << " = " << nb_1-nb_2 << endl;
}

void Entier::fois() {
  cout << nb_1 << " * " << nb_2 << " = " << nb_1*nb_2 << endl;
}

void Entier::diviser() {
  if (nb_2 != 0)
    cout << nb_1 << " / " << nb_2 << " = " << nb_1/nb_2 << endl;
  else
    cout << "nb_2 = 0. Division impossible." << endl;
}

Entier Entier::operator+(const Entier &e) {
  Entier resultat;
  resultat.nb_1 = nb_1 + e.nb_1;
  resultat.nb_2 = nb_2 + e.nb_2;
  return resultat;
}

int Entier::getValue_1() {
  return nb_1;
}

int Entier::getValue_2() {
  return nb_2;
}
