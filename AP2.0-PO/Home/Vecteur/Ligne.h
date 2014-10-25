#ifndef _LIGNE_
#define _LIGNE_

#include "Point.h"

class Ligne
{
 private:
  Point* debut;
  Point* fin;

 public:
  Ligne();
  Ligne( Point*, Point* );
  Ligne( float, float, float, float );
  Ligne( const Ligne& );
  ~Ligne();
  
  void afficher() const;
};

#endif
