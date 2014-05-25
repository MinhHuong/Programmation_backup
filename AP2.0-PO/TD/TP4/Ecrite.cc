#include "Ecrite.h"

Ecrite::Ecrite(string aut, string titre, string sty, int j, int m, int a, int val, 
	       string lang, string theme) 
  : Oeuvre(aut, titre, sty, j, m, a, val)
{
  //cout << "Ecrite::Constructeur avec parametres" << endl;
  my_langue = lang;
  my_theme = theme;
}

Ecrite::Ecrite(const Ecrite& e) 
  : Oeuvre(e)
{
  //cout << "Ecrite::Constructeur par copie" << endl;
  my_langue = e.my_langue;
  my_theme = e.my_theme;
}

Ecrite::~Ecrite() {
  //cout << "Ecrite::Destructeur" << endl;
}

string Ecrite::toString() const {
  string info = "";
  info += "Information de Ecrite : \n";
  info += Oeuvre::toString();
  info += "Langue ecrite : " + my_langue + "\n";
  info += "Theme : " + my_theme + "\n";
  
  return info;
}
