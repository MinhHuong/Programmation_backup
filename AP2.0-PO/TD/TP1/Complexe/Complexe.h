#ifndef COMPLEXE_H
#define COMLEXE_H
#include <iostream>
#include <math.h>
#include "util.h"
using namespace std;

class Complexe { 
 private:
  float my_reel;
  float my_imaginaire;

 public:
  Complexe();
  Complexe(float, float);
  ~Complexe();
  string toString() const;
  void setReel(float);
  void setImaginaire(float);
  float getReel() const;
  float getImaginaire() const;
  
  void plus(const Complexe & c, Complexe & s) const;
  void fois(const Complexe & c, Complexe & p) const;
};

#endif
