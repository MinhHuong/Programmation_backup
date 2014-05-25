#ifndef LIVRE_H
#define LIVRE_H

#include <iostream>
#include "Ecrite.h"
using namespace std;

class Livre : public Ecrite {
 private:
  string my_editeur;
  Date my_date_edition;

 public:
  Livre(string, string, string, 
	int, int, int, int,
	string, string,
	string, int, int, int);
  Livre(const Livre&);
  ~Livre();

  string toString() const;
};

#endif
