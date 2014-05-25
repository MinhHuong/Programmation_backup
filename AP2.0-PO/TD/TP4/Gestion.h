#ifndef GESTION_H
#define GESTION_H

#include <iostream>
#include <string>
#include "Oeuvre.h"
#include "Plastique.h"
using namespace std;

class Gestion {
 private:
  const static int MAX = 100;
  Oeuvre * my_tabOeuvres[MAX];
  int my_nbOeuvres;

 public:
  Gestion();
  ~Gestion();
  
  void addOeuvre(Oeuvre * oeu);
  void set_possesseur(int indice, string poss);
  void set_date_acquis(int indice, int ja, int ma, int aa);
  Oeuvre * find_Oeuvre(int indice);
  void print_Oeuvre(int indice);
  void print_all_title();

};

#endif
