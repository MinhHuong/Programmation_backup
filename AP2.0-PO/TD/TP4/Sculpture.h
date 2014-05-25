#ifndef SCULPTURE_H
#define SCULPTURE_H

#include <iostream>
#include "Plastique.h"
using namespace std;

class Sculpture : public Plastique {
 private:
  string my_materiau;
  
 public:
  Sculpture(string, string, string, 
	    int, int, int, int,
	    string, int, int, int,
	    string);
  Sculpture(const Sculpture& s);
  ~Sculpture();

  string toString();
};

#endif
