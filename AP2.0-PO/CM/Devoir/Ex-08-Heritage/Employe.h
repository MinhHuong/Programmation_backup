#ifndef EMPLOYE_H
#define EMPLOYE_H
#include <iostream>
#include <string>
using namespace std;

class Employe {
 private:
  string e_nom;
  double e_salaire;
  
 public:
  Employe();
  Employe(string, double);

  void setSalaire(double);
  double getSalaire() const;
  string getNom() const;
};

#endif
