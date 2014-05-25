#ifndef __MYTRIANGLE__
#define __MYTRIANGLE__
#include "Shape.h"
#include "Point.h"
#include "util.h"
#include <iostream>
using namespace std;

class Triangle : public Shape {
 protected:
  Point p1,p2,p3;

 public:
  Triangle(char col, const Point& a, const Point& b, const Point& c);
  virtual ~Triangle();
  virtual void move(int dx, int dy);
  virtual void draw(Screen & s);

  virtual bool appartenir(Point& p) ;
};

#endif
