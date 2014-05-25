#include "Livre.h"
using namespace std;

Livre::Livre(string aut, string titre, string sty, int j, int m, int a, int val,
	     string lang, string theme,
	     string edit, 
	     int je, int me, int ae) 
  : Ecrite(aut, titre, sty, j, m, a, val,
	   lang, theme),
    my_date_edition(je, me, ae)
{
  //cout << "Livre::Constructeur avec parametres" << endl;
  my_editeur = edit;
}

Livre::Livre(const Livre& l) 
  : Ecrite(l)
{
  //cout << "Livre::Constructeur par copie" << endl;
  my_editeur = l.my_editeur;
  my_date_edition = l.my_date_edition;
}

Livre::~Livre() {
  //cout << "Livre::Destructeur" << endl;
}

string Livre::toString() const {
  string info = "Information du livre :\n";
  info += Ecrite::toString();
  info += "Editeur : " + my_editeur + "\n";
  info += "Date d'edition : " + my_date_edition.toString() + "\n";
  
  return info;
}
