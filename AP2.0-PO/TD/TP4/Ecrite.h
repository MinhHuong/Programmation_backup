#ifndef ECRITE_H
#define ECRITE_H

#include <iostream>
#include "Oeuvre.h"
using namespace std;

class Ecrite : public Oeuvre {
 protected:
  string my_langue;
  string my_theme;

 public:
  Ecrite(string, string, string,
	 int, int, int, int,
	 string, string);
  Ecrite(const Ecrite&);
  ~Ecrite();

  string toString() const;
};

#endif
