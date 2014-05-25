#include "Date.h"

Date::Date() 
  : jour(NULL), mois(NULL), annee(NULL)
{ 
  cout << "Date : constructeur par defaut" << endl;
}

Date::Date(int j, int m, int a) {
  cout << "Date : constructeur avec parametre" << endl;

  jour = new int;
  *jour = j;

  mois = new int;
  *mois = m;

  annee = new int;
  *annee = a;
}

Date::~Date() {
  cout << "Date : destructeur" << endl;
  if (jour != NULL) delete jour;
  if (mois != NULL) delete mois;
  if (annee != NULL) delete annee;
}

void Date::setDate(int j, int m, int a) {
  jour = new int;
  *jour = j;

  mois = new int;
  *mois = m;

  annee = new int;
  *annee = a;
}

void Date::afficherDate() {
  cout << *jour << "/" << *mois << "/" << *annee << endl;
}
