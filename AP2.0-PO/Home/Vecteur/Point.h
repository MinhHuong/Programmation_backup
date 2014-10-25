#ifndef _POINT_
#define _POINT_

class Point
{
 private:
  float _x, _y;
  
 public:
  Point();
  Point( float, float );
  Point( const Point& p );
  ~Point();

  Point& operator=( const Point& p );
  Point& operator+( const Point& p ); 
  void plus( const Point& other, Point& result ) const;

  void afficher() const;
};

#endif
