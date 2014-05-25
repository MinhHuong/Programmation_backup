#ifndef BUREAU_H
#define BUREAU_H
#include "Employe.h"

class Bureau : public Employe {
 private:
  float my_temps;

 public:
  Bureau();
  virtual void saisir();
  virtual void afficher();
  virtual float bonus();
};

#endif
