#ifndef BOITE_H
#define BOITE_H
#include "Point.h"

class Boite {
 private:
  Point my_bas_gauche;        
  Point my_haut_droite;
  Point* my_points; 
  int my_nb_alloues;
  int my_nb_points;

  Boite();
  void agrandir();
 
 public:
  Boite(const Point & p);
  Boite(const Boite & b);
  ~Boite();                   

  void affiche() const;
  bool interieur(const Point & p) const;
  void ajouterPoint(const Point & p);
  void supprimerPoint(const Point & p);
  Boite & operator=(const Boite & b);
};

#endif 
