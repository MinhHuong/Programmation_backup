// fichier Date.cc

#include <iostream>
#include <string>
#include "Date.h"
#include "util.h"

using namespace std;

Date::Date()
{
  //cout << "Date::Constructeur par defaut" << endl;
  my_jour = 1;
  my_mois = 1;
  my_annee = 1970;
}

Date::~Date()
{
  // cout << "Date::Destructeur" << endl;
}

Date::Date( int j, int m, int a )
{
  //cout << "Date::Constructeur avec parametres" << endl;
  my_jour = j;
  my_mois = m;
  my_annee = a;
}

Date::Date( const Date & d )
{
  // cout << "Date::Constructeur par copie" << endl;
  my_jour = d.my_jour;
  my_mois = d.my_mois;
  my_annee = d.my_annee;
}

void
Date::setDate( int j, int m, int a )
{
  my_jour = j;
  my_mois = m;
  my_annee = a;
}

void
Date::getDate( int &j, int &m, int &a ) const
{
  j = my_jour;
  m = my_mois;
  a = my_annee;
}

string
Date::toString() const
{
  return intToString(my_jour)+"/" + intToString(my_mois)
    + "/" +intToString(my_annee);
}

int Date::getJour() const {
  return my_jour;
}

int Date::getMois() const {
  return my_mois;
}

int Date::getAnnee() const {
  return my_annee;
}
