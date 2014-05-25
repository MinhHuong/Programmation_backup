#include "Trottinette.h"

// ROUE
Roue::Roue() {
  my_diametre = -1;
}

Roue::Roue(float diametre) {
  my_diametre = diametre;
}

Roue::Roue(const Roue & r) {
  my_diametre = r.my_diametre;
}

Roue::~Roue() {
  cout << "Roue : destructeur" << endl;
}

void Roue::setDiametre(float diametre) {
  my_diametre = diametre;
}

float Roue::getDiametre() const {
  return my_diametre;
}


// TROTTINETTE

Trottinette::Trottinette() {
  my_roue_avant = my_roue_arriere = Roue(0);
}

Trottinette::Trottinette(float diametre_avant, float diametre_arriere) {
  my_roue_avant = Roue(diametre_avant);
  my_roue_arriere = Roue(diametre_arriere);
}

Trottinette::~Trottinette() {
  cout << "Trottinette : destructeur" << endl;
}

void Trottinette::changerRoueAvant(Roue r) {
  my_roue_avant = r;
}

void Trottinette::changerRoueArriere(Roue r) {
  my_roue_arriere = r;
}

Roue Trottinette::getRoueAvant() const {
  return my_roue_avant;
}

Roue Trottinette::getRoueArriere() const {
  return my_roue_arriere;
}
