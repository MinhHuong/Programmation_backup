#include "Cercle.h"
#include "Segment.h"
#include <typeinfo>
#include <vector>

int main() {
  /*
  vector <Forme*> v;
  Segment *s = new Segment(1.0,2.0,-1.0,-2.0);
  Cercle *c = new Cercle(3.0,1.0,1.0);
  v.push_back(s);
  v.push_back(c);

  cout << endl << "Dessiner un segment : " << endl;
  v[0]->dessiner();

  cout << endl << "Dessiner un cercle : " << endl;
  v[1]->dessiner();

  delete s;
  delete c;*/

  /*
  Forme * f = new Segment(1.0,2.0,-1.0,-2.0);
  f->dessiner();
  */
  
  Cercle c(3.0,1.0,1.0);
  c.dessiner();

  return 0;
}
