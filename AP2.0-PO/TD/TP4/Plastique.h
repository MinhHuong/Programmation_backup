#ifndef PLASTIQUE_H
#define PLASTIQUE_H

#include <string>
#include "Date.h"
#include "Oeuvre.h"

using namespace std;

class Plastique : public Oeuvre {
 public:
  Plastique( string artiste, string titre, string sty,
	    int j, int m, int a, int val,
	    string poss, int ja, int ma, int aa );
   Plastique(const Plastique&);
   ~Plastique();

   virtual string toString() const;

   void setPossesseur(string);
   void setDateAcquis(int, int, int);

 private:
   string my_possesseur;
   Date my_date_acquis; 
};

#endif

