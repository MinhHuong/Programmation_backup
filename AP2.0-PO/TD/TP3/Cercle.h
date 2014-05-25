#ifndef __CERCLE__
#define __CERCLE__

#include <sstream>
#include <string>
#include "Point.h"

using namespace std;

class Cercle {
 private :
  Point *my_centre;
  float my_rayon;

 public :
  Cercle();        
  ~Cercle();
  Cercle( float r );
  Cercle( float r, float x, float y );
  Cercle( float r, const Point & p );
  Cercle (const Cercle & c);
  string toString() const;
};

ostream& operator<<(ostream& out, const Cercle& c);

#endif

