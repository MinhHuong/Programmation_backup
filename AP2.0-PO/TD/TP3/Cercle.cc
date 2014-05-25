#include <iostream>
#include <sstream>
#include <string>
#include "Cercle.h"
#include "Point.h"

using namespace std;

ostream& operator<<(ostream& out, const Cercle& c) {
  out << c.toString();
  return out;
}

Cercle::Cercle()
// ici, appel Point::constructeur par defaut
{
  cout << "Cercle::Constructeur par defaut" << endl;
  my_rayon = 0;
  my_centre = new Point();
}

Cercle::~Cercle()
{
  cout << "Cercle::Destructeur" << endl;
  if (my_centre != NULL)
    delete my_centre;
  // ici, appel Point::destructeur
}

Cercle::Cercle( float r )
// ici, appel Point::constructeur par defaut
{  cout << "Cercle::Constructeur rayon " << endl;
  my_rayon = r;
  my_centre = new Point;
}

Cercle::Cercle( float r, float x, float y )
//: my_centre(x,y)
{
  cout << "Cercle::Constructeur rayon + x + y " << endl;
  my_rayon = r;
  // modification du point construit par defaut
  my_centre = new Point;
  my_centre->setX(x);
  my_centre->setY(y);
}

Cercle::Cercle( float r, const Point & p )
// ici, appel Point::constructeur par defaut
//: my_centre(p.getX(),p.getY())
{
  cout << "Cercle::Constructeur rayon + point " << endl;
  my_rayon = r;
  // modification du point construit par defaut
  my_centre = new Point;
  *my_centre = p;  // affectation bien definie
                  // ou sinon :
                  // my_centre.setX( p.getX() );
                  // my_centre.setY( p.getY() );
}

Cercle::Cercle (const Cercle & c) 
{
  cout << "Cercle::Constructeur par copie" << endl;
  my_centre = new Point;
  *my_centre = *(c.my_centre);
  my_rayon = c.my_rayon;
}

string
Cercle::toString() const
{
  ostringstream ostr;

  ostr << "centre : " << my_centre->toString() << endl;
  ostr << "rayon :  " << my_rayon;
  return ostr.str();
}
