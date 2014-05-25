#ifndef SEGMENT_H
#define SEGMENT_H
#include <iostream>
#include "Forme.h"
#include "Point.h"
using namespace std;

class Segment : public Forme {
 private:
  Point debut;
  Point fin;
  
 public:
  Segment();
  Segment(float, float, float, float);
  ~Segment();

  void setDebut(float, float);
  void setFin(float, float);
  virtual void dessiner();
};

#endif
