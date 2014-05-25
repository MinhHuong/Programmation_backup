#ifndef __MYDESSINSHAPES__
#define __MYDESSINSHAPES__
#include "Shape.h"

class DessinShapes {
 private:
  static const int MAX = 100;
  Shape * my_tabShapes[MAX];
  int my_nbShapes;
  
 public:
  DessinShapes();
  ~DessinShapes();
  void addShape( Shape * pshape ); 
  // ajouter 1 pointeur Shape au tableau my_tabShapes

  void refresh( Screen & s );
  // afficher toutes les formes a l'ecran

  void setColourAll( char col ); // c
  void moveAll( int dx, int dy ); // d
  void eraseAll(); // e

  Shape * select(int ind) const;

  void setColourOne(int indice, char col);
  void moveOne(int indice, int dx, int dy);
  void erase(int indice);
  void eraseOne(int indice);

  Shape * select(const Point & p) const;
  void setColourOne(const Point & p, char col);
  void moveOne(const Point & p, int dx, int dy);
  void erase(const Point & p);
  void eraseOne(const Point & p);

  void modifierRayon(int indice, int r);
};

#endif

