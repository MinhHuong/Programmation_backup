#ifndef _RECTANGLE_
#define _RECTANGLE_

#include <iostream>

class Rectangle
{
 protected:
  float _long;
  float _lar;

 public:
  Rectangle();
  Rectangle( float , float );
  ~Rectangle();

  virtual void afficher();
  float getLongueur() const;
  float getLargeur() const;
  virtual float getPerimetre() = 0;
};

#endif
