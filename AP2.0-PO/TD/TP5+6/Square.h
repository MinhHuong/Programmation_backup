#ifndef __MYSQUARE__
#define __MYSQUARE__

#include <iostream>
#include "Rectangle.h"
using namespace std;

class Square : public Rectangle {
 protected:
  // herite de my_sw de la classe Rectangle
  int l;

 public:
  Square(char my_col, const Point& a, int length);
  virtual ~Square();
  virtual void move(int dx, int dy);
  virtual void draw(Screen & s);
  virtual bool appartenir(const Point& p) const;
};

#endif
