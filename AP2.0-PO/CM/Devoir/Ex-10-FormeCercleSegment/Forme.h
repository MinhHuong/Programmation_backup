#ifndef FORME_H
#define FORME_H
#include <iostream>
using namespace std;

class Forme {
 public:
  Forme();
  ~Forme();
  virtual void dessiner() = 0;
  //void dessiner();
  //virtual void dessiner();
};

#endif
