#include <iostream>
#include <string>
#include "Oeuvre.h"
#include "Date.h"
#include "util.h"

using namespace std;

Oeuvre::Oeuvre( string aut, string titre, string sty,
		int j, int m, int a, int val )
  : my_date_creation(j,m,a)
{
  //cout << "Oeuvre::Constructeur avec parametres" << endl;
  my_auteur = aut;
  my_titre = titre;
  my_style = sty;
  my_valest = val;
}

Oeuvre::~Oeuvre()
{
  //cout << "Oeuvre::Destructeur" << endl;
}

Oeuvre::Oeuvre(const Oeuvre& o) 
  : my_date_creation(o.my_date_creation)
{
  //cout << "Oeuvre::Constructeur par copie" << endl;
  my_auteur = o.my_auteur;
  my_titre = o.my_titre;
  my_style = o.my_style;
  my_valest = o.my_valest;
}

string
Oeuvre::toString() const
{
  string aff = "";
  //aff += "Affichage de Oeuvre :\n" ;
  aff += "Titre      :  " + my_titre +"\n";
  aff += "Auteur     :  " + my_auteur +"\n";
  aff += "Style      :  " + my_style +"\n";
  aff += "Cree(e) le :  " + my_date_creation.toString()+"\n";
  aff += "Valeur     :  " + intToString(my_valest) + " euros" +"\n";
  
  return aff;
}

string Oeuvre::getTitle() const {
  return my_titre;
}
