#include "Rectangle.h"

using namespace std;

Rectangle::Rectangle()
{
  cout << "Rectangle::Constructeur par defaut" << endl;
}

Rectangle::Rectangle( float longueur, float largeur )
{
  cout << "Rectangle::Constructeur avec parametres" << endl;
  _long = longueur;
  _lar = largeur;
}

Rectangle::~Rectangle()
{
  cout << "Rectangle::Destructeur" << endl;
}

void Rectangle::afficher()
{
  cout << "RECTANGLE" << endl;
}

float Rectangle::getLongueur() const
{
  return _long;
}

float Rectangle::getLargeur() const
{
  return _lar;
}
