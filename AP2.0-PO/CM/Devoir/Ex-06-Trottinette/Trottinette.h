#ifndef TROTTINETTE_H
#define TROTTINETTE_H
#include <iostream>
using namespace std;

class Roue {
 private:
  float my_diametre;
  
 public:
  Roue();
  Roue(float diametre);
  Roue(const Roue & r);
  ~Roue();
  void setDiametre(float);
  float getDiametre() const;
};


class Trottinette {
 private:
  Roue my_roue_avant;
  Roue my_roue_arriere;

 public:
  Trottinette();
  Trottinette(float, float);
  ~Trottinette();
  void changerRoueAvant(Roue);
  void changerRoueArriere(Roue);
  Roue getRoueAvant() const;
  Roue getRoueArriere() const;
};

#endif
