#ifndef _VECTEUR_
#define _VECTEUR_

#include "Point.h"

class Vecteur
{
 private:
  Point debut, fin; 

 public:
  Vecteur();
  Vecteur( const Point&, const Point& );
  Vecteur( float, float, float, float );
  Vecteur( const Vecteur& );
  ~Vecteur();

  void afficher() const;
};

#endif
