#include "Carre.h"
#include <iostream>

using namespace std;

Carre::Carre()
  : Rectangle()
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

float Carre::perimetre() const
{
  return width * 4;
}
