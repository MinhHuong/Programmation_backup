#ifndef __POINT__
#define __POINT__

#include <sstream>
#include <string>

using namespace std;

class Point { 
 private :
  float my_abs, my_ord;
  static const float EPSILON;
  
  public :
  Point( float x, float y );
  Point();
  ~Point();
  Point( const Point & p );
  
  Point & operator=( const Point & p );
  string toString() const;
  float getX() const;
  float getY() const;
  void setX( float new_x );
  void setY( float new_y );

  // quelques services
  void deplace( float d_x, float d_y );
  float distance() const;
  float distance( const Point & p ) const;
  bool operator==( const Point & p ) const;
  bool operator<( const Point & p) const;
};

ostream& operator<<(ostream& out, const Point& p);

#endif

