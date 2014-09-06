#ifndef _CARRE_
#define _CARRE_

#include "Rectangle.h"

class Carre : public Rectangle
{
 public:
  Carre();
  Carre( float );
  ~Carre();

  virtual void afficher();
  float getCote() const;
  virtual float getPerimetre();
};

#endif
