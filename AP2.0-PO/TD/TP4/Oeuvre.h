// fichier Oeuvre.h

#ifndef OEUVRE_H
#define OEUVRE_H

#include <string>
#include "Date.h"

using namespace std;

class Oeuvre {
 public:
  Oeuvre();
  Oeuvre( string aut, string titre, string sty,
	  int j, int m, int a, int val );
  Oeuvre(const Oeuvre&);
  virtual ~Oeuvre();
  virtual string toString() const;
  string getTitle() const;
  
 private:
  string my_auteur;
  string my_titre;
  string my_style;
  Date my_date_creation;  
  int my_valest;
};

#endif // #ifndef OEUVRE_H

