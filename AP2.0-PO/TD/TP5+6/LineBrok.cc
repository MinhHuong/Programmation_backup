#include "Screen.h"
#include "Point.h"
#include "Line.h"
#include "LineBrok.h"


LineBrok::LineBrok( char col, const Point & a, const Point & b, const Point & m )
  : Line( col, a, b )
{
  my_m = m;
}

LineBrok::~LineBrok()
{}

void 
LineBrok::move( int dx, int dy ) 
{
  Line::move( dx, dy );
  my_m.deplace( dx, dy );
}

void 
LineBrok::draw( Screen & s ) 
{ 
  char oldPen = s.getColPen();
  s.setColPen( my_col );

  s.put_line( my_w, my_m );
  s.put_line( my_m, my_e );
  
  s.setColPen( oldPen );
}

bool LineBrok::appartenir(const Point& p) const {
  return ( equation(my_e, my_w, p) ||
	   equation(my_e, my_m, p) ||
	   equation(my_w, my_m, p) );
}
