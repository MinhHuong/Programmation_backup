#ifndef ENTIER_H
#define ENTIER_H
#include <iostream>
using namespace std;

class Entier {
 private:
  int my_valeur;
  
 public:
  Entier();
  Entier(int valeur);
  Entier(const Entier &e);
  void init(int valeur);
  void plus(int valeur);
  void moins(int valeur);
  void fois(int valeur);
  void diviser(int valeur);
  Entier operator+(const Entier &ent);
  int getValeur();
};

#endif
