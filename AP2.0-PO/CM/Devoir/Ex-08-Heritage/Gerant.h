#ifndef GERANT_H
#define GERANT_H
#include <iostream>
#include <string>
#include "Employe.h"
using namespace std;

class Gerant : public Employe {
 private:
  int nb_employes;

 public:
  Gerant();
  Gerant(string, double);

  void ajouter();
  int getNbEmploye() const;
  double getSalaire() const;
};

#endif
