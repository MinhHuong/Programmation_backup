#include "Carre.h"

using namespace std;

Carre::Carre()
{
  cout << "Carre::Constructeur par defaut" << endl;
}

Carre::Carre( float cote )
  : Rectangle( cote, cote )
{
  cout << "Carre::Constructeur avec parametres" << endl;
}

Carre::~Carre()
{
  cout << "Carre::Destructeur" << endl;
}

void Carre::afficher()
{
  cout << "CARRE" << endl;
}

float Carre::getCote() const
{
  return _long;
}

float Carre::getPerimetre()
{

}
