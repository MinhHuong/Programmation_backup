#include "Date.h"

Date::Date() {
  jour = NULL;
  mois = NULL;
  annee = NULL;
}

Date::Date(int j, int m, int a) {
  jour = new int;
  mois = new int;
  annee = new int;
  *jour = j;
  *mois = m;
  *annee = a;
}

Date::Date(const Date &d) {
  jour = new int;
  *jour = *(d.jour);
  
  mois = new int;
  *mois = *(d.mois);

  annee = new int;
  *annee = *(d.annee);
}

Date::~Date() {
  cout << "Date : destructeur" << endl;
  if (jour != NULL) delete jour;
  if (mois != NULL) delete mois;
  if (annee != NULL) delete annee;
}

void Date::setDate(int j, int m, int a) {
  jour = new int;
  mois = new int;
  annee = new int;
  *jour = j;
  *mois = m;
  *annee = a;
}

void Date::afficherDate() {
  cout << "C'est le " << *jour << "/" << *mois << "/" << *annee << endl;
}

int Date::getJour() {
  return *jour;
} 

int Date::getMois() {
  return *mois;
}

int Date::getAnnee() {
  return *annee;
}
