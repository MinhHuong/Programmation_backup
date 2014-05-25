#ifndef EMPLOYE_H
#define EMPLOYE_H
#include <iostream>
#include <string>

class Employe {
 protected:
  std::string my_id;
  std::string my_nom;
  float my_salaire;

 public:
  Employe();

  virtual void saisir();
  virtual void afficher();
  virtual float bonus() = 0;
  // fonction abstraite pure
};

#endif
