#ifndef POLYGONE_H
#define POLYGONE_H
#include "Point.h"
#include <iostream>
#include <string>
using namespace std;

class Polygone {
 private:
  Point * my_tab;
  static int my_taille;

 public:
  Polygone();
  Polygone(const Polygone & p);
  ~Polygone();
  
  string toString();

  void saisie();
  void deplace(float dx, float dy);
  void ajoutSommet(const Point & p);
  float Perimetre() const;

  void litFichier(string nom_fic);
  void ecritFichier(string nom_fic);

  Point getPoint(int ind) const;
  int getTaille() const;
  //const Point & getPoint(int ind) const;
  Polygone & operator=(const Polygone &p);
};

#endif
