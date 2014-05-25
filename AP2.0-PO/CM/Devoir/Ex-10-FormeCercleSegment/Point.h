#ifndef POINT_H
#define POINT_H
#include <iostream>
using namespace std;

class Point {
 private:
  float abs;
  float ord;

 public:
  Point();
  Point(float, float);
  Point(const Point&);
  ~Point();

  void setPoint(float, float);
  void getPoint() const;
};

#endif
