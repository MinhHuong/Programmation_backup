#include "Triangle.h"
using namespace std;

Triangle::Triangle(char col, const Point& a, const Point& b, const Point& c) {
  my_col = col;
  p1 = a;
  p2 = b;
  p3 = c;
}

Triangle::~Triangle() {}

void Triangle::move(int dx, int dy) {
  p1.deplace(dx,dy);
  p2.deplace(dx,dy);
  p3.deplace(dx,dy);
}

void Triangle::draw(Screen & s) {
  char oldPen = s.getColPen();
  s.setColPen(my_col);

  s.put_line(p1,p2);
  s.put_line(p2,p3);
  s.put_line(p3,p1);

  s.setColPen(oldPen);
}

bool Triangle::appartenir(Point& p) {
  int px = p.getX();
  int fois = 0;

  for (int i = 0 ; i < 3 ; i++) {
    for (int j = px ; j < 60 ; j++) {
      px++;
      p.setX(px);
      if ( equation(p1, p2, p) ||
	   equation(p1, p3, p) ||
	   equation(p2, p3, p) ) {
	fois++;
	cout << "Intersection = " << fois << endl;
      }
    }
  }
  
  if (fois % 2 == 0)
    return false;
  else
    return true;

  /*
  int x1 = p1.getX(), 
    x2 = p2.getX(), 
    x3 = p3.getX(),
    y1 = p1.getY(),
    y2 = p2.getY(),
    y3 = p3.getY();
    
  int x_bg, y_bg, x_hd, y_hd;

  // Trouver le bas gauche
  x_bg = (x1 < x2)?x1:x2;
  x_bg = (x3 < x_bg)?x3:x_bg;
  
  y_bg = (y1 < y2)?y1:y2;
  y_bg = (y3 < y_bg)?y3:y_bg;

  //Trouver le haut droite
  x_hd = (x1 > x2)?x1:x2;
  x_hd = (x3 > x_hd)?x3:x_hd;

  y_hd = (y1 > y2)?y1:y2;
  y_hd = (y3 > y_hd)?y3:y_hd;

  int px = p.getX(), py = p.getY();

  if ( (px >= x_bg) &&
       (px <= x_hd) &&
       (py >= y_bg) &&
       (py <= y_hd) )
    return true;
  else
    return false;
  */
}
