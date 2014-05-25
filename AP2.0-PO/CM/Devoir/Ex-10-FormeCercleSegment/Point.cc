#include "Point.h"

Point::Point() 
  : abs(0), ord(0) { 
  cout << "Point : constructeur par defaut" << endl;
}

Point::Point(float x, float y) 
  : abs(x), ord(y) { 
  cout << "Point : constructeur avec parametre" << endl;
}

Point::Point(const Point& p) 
  : abs(p.abs), ord(p.ord) { 
  cout << "Point : constructeur par copie" << endl;
}

Point::~Point() { 
  cout << "Point : destructeur" << endl;
}

void Point::setPoint(float x, float y) {
  abs = x;
  ord = y;
}

void Point::getPoint() const {
  cout << "Coordonnees : (" << abs << "," << ord << ")" << endl;
}
 
