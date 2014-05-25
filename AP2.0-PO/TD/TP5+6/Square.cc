#include "Square.h"
using namespace std;

Square::Square(char col, const Point& a, int length) 
  : Rectangle(col,a,length,length)
{
  my_ne.setX(a.getX() + length);
  my_ne.setY(a.getY() + length);
  l = length;
}

Square::~Square() {}

void Square::move(int dx, int dy) {
  Rectangle::move(dx,dy);
}

void Square::draw(Screen & s) {
  Rectangle::draw(s);
}

bool Square::appartenir(const Point& p) const {
  return Rectangle::appartenir(p);
}
