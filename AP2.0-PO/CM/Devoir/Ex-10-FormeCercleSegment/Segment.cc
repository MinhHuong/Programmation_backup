#include "Segment.h"

Segment::Segment() 
  : debut(Point(0.0,0.0)),
    fin (Point(0.0,0.0)) {
  cout << "Segment : constructeur par defaut" << endl;
}

Segment::Segment(float deb_x, float deb_y, float fin_x, float fin_y) 
  : debut(deb_x,deb_y),
    fin(fin_x,fin_y) {
  cout << "Segment : constructeur avec parametre" << endl;
}

Segment::~Segment() {
  cout << "Segment : destructeur" << endl;
}

void Segment::setDebut(float deb_x, float deb_y) {
  debut = Point(deb_x,deb_y);
}

void Segment::setFin(float fin_x, float fin_y) {
  fin = Point(fin_x,fin_y);
}

void Segment::dessiner() {
  cout << "Tracez un segment ayant 2 extremites :" << endl;
  debut.getPoint();
  fin.getPoint();
}
