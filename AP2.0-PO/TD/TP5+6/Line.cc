#include "Screen.h"
#include "Point.h"
#include "Line.h"


Line::Line( char col, const Point & a, const Point & b )
{
  my_col = col; 
  my_w = a;
  my_e = b;
}

Line::Line( char col, const Point & a, int l )
{ 
  my_col = col; 
  my_w = a;
  my_e = Point( a.getX()+l-1, a.getY() );
}

Line::~Line()
{}

void 
Line::move( int dx, int dy ) 
{ 
  my_w.deplace( dx, dy );
  my_e.deplace( dx, dy );
}

void 
Line::draw( Screen & s ) 
{
  char oldPen = s.getColPen();
  s.setColPen( my_col );

  s.put_line( my_w, my_e );

  s.setColPen( oldPen );
}
/*
bool Line::equation(const Point& a, const Point& b, const Point& c) const {
  int x1 = a.getX(), y1 = a.getY(),
    x2 = b.getX(), y2 = b.getY();

  int px = c.getX(), py = c.getY();

  return ( (y1-y2)*(px-x1) + (x2-x1)*(py-y1) == 0);
}
*/
bool Line::appartenir(const Point& p) const {
  return equation(my_w, my_e, p);
}
