#include "Vendeur.h"
using namespace std;

Vendeur::Vendeur() {
  coef = 0.0;
}

void Vendeur::saisir() {
  Employe::saisir();

  float c;
  cout << "Coefficient de bonus : ";
  cin >> c;
  coef = c;
}

void Vendeur::afficher() {
  Employe::afficher();
  cout << "Mon coefficient de bonus = " << coef << endl;
}

float Vendeur::bonus() {
  return 150000*coef;
}
