#include "Rectangle.h"
#include <iostream>

using namespace std;

Rectangle::Rectangle()
{
  cout << "Rectangle::Constructeur par defaut" << endl;

  width = height = 0.0;
}

Rectangle::Rectangle( float x, float y )
{
  cout << "Rectangle::Constructeur avec parametres" << endl;

  width = x;
  height = y;
}

Rectangle::~Rectangle()
{
  cout << "Rectangle::Destructeur" << endl;
}

float Rectangle::perimetre() const
{
  return ( width + height )*2;
}
