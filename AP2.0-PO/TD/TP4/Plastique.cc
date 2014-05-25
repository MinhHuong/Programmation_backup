#include <iostream>
#include <string>
#include "Plastique.h"
#include "Oeuvre.h"
#include "Date.h"
#include "util.h"

using namespace std;

Plastique::Plastique( string artiste, string titre, string sty,
                    int j, int m, int a, int val,
		    string poss, int ja, int ma, int aa )
  : Oeuvre(artiste, titre, sty, j, m, a, val),
    my_date_acquis(ja,ma,aa)
{ 
  //cout << "Plastique::Constructeur avec parametres" << endl;
  my_possesseur = poss;
}

Plastique::Plastique(const Plastique& p) 
  : Oeuvre(p) 
{
  //cout << "Plastique::Constructeur par copie" << endl;
  my_possesseur = p.my_possesseur;
  my_date_acquis = p.my_date_acquis;
}

Plastique::~Plastique()
{
  //cout << "Plastique::Destructeur" << endl;
}

string Plastique::toString() const
{
  string inf;
  inf += Oeuvre::toString();
  inf += "Possesseur :  " + my_possesseur +"\n";
  inf +=  "Acquis(e) le :  " + my_date_acquis.toString();
  return inf;
}

void Plastique::setPossesseur(string poss) {
  my_possesseur = poss;
}

void Plastique::setDateAcquis(int ja, int ma, int aa) {
  my_date_acquis.setDate(ja,ma,aa);
}
