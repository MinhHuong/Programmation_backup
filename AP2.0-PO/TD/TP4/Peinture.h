#ifndef PEINTURE_H
#define PEINTURE_H

#include <iostream>
#include "Plastique.h"
#include "Oeuvre.h"

using namespace std;

class Peinture : public Plastique {
 private:
  string my_support;
  string my_matiere;

 public:
  Peinture(string aut, string titre, string sty,
	   int j, int m, int a, int val,
	   string poss, int ja, int ma, int aa,
	   string supp, string mat);

  Peinture(const Peinture& peint);
  ~Peinture();

  virtual string toString() const;
};

#endif
