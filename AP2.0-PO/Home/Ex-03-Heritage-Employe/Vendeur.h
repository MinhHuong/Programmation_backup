#ifndef VENDEUR_H
#define VENDEUR_H
#include "Employe.h"
#include <iostream>
#include <string>

class Vendeur : public Employe {
 private:
  float coef;
  
 public:
  Vendeur();
  virtual void saisir();
  virtual void afficher();
  virtual float bonus();
};

#endif
