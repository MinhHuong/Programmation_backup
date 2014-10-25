#include "Point.h"

#include <iostream>

using namespace std;

Point::Point()
{
  cout << "Point::Constructeur par defaut" << endl;
  _x = _y = 0.0;
}

Point::Point( float x, float y )
{
  cout << "Point::Constructeur avec parametres" << endl;
  _x = x;
  _y = y;
}

Point::Point( const Point& p )
{
  cout << "Point::Constructeur par copie" << endl;
  _x = p._x;
  _y = p._y;
}

Point::~Point()
{
  cout << "Point::Destructeur" << endl;
}

Point& Point::operator=( const Point& p )
{
  cout << "Point::Operation d'affectation" << endl;

  if( this != & p )
    {
      _x = p._x;
      _y = p._y;
    }

  return *this;
}

// prendre n'importe quel zone de memoire
Point& Point::operator+( const Point& p )
{ 
  cout << "Point::Operation +" << endl;

  _x += p._x;
  _y += p._y;

  return *this;
}

//determiner le zone de memoire pour stocker le resultat
void Point::plus( const Point& other, Point& result ) const
{
  cout << "Point::Operation +" << endl;
  
  result._x = _x + other._x;
  result._y = _y + other._x;
}

void Point::afficher() const
{
  cout << "Point (" << _x << ", " << _y << ")" << endl;
}
