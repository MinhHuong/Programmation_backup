#include "Screen.h"
#include "Point.h"
#include "Circle.h"


Circle::Circle( char col, const Point & a, int r )
{
  my_col = col;
  my_center = a;
  my_radius = r;
}

Circle::~Circle()
{}

void 
Circle::move( int dx, int dy )
{ 
  my_center.deplace( dx, dy );
}

void
Circle::draw( Screen & s ) 
{
  char oldPen = s.getColPen();
  s.setColPen( my_col );

  s.put_circle( my_center, my_radius );
  
  s.setColPen( oldPen );
}

bool Circle::appartenir(const Point& p) const {
  if (p.distance(my_center) <= my_radius)
    return true;
  else
    return false;
  /*
    int x_center = my_center.getX(),
      y_center = my_center.getY(),
      px = p.getX(),
      py = p.getY();

  if ( (px >= x_center-my_radius) &&
       (px <= x_center+my_radius) &&
       (py >= y_center-my_radius) &&
       (py <= y_center+my_radius) )
    return true;
  else
    return false;
  */
}

void Circle::setRadius(int r) {
  my_radius = r;
}
