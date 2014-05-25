#ifndef CERCLE_H
#define CERCLE_H
#include <iostream>
#include "Point.h"
#include "Forme.h"
using namespace std;

class Cercle : public Forme {
 private:
  float rayon_;
  Point centre_;
  
 public:
  Cercle();
  Cercle(float, float, float);
  ~Cercle();

  void setCentre(float, float);
  void setRayon(float);
  virtual void dessiner();
};

#endif
