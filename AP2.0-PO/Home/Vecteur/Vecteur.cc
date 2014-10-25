#include "Vecteur.h"
#include <iostream>

using namespace std;

Vecteur::Vecteur()
  : debut(), 
    fin()
{
  cout << "Vecteur::Constructeur par defaut" << endl;
}

Vecteur::Vecteur( const Point& p_deb, const Point& p_fin )
  : debut( p_deb ),
    fin( p_fin )
{
  cout << "Vecteur::Constructeur avec parametres (recevant 2 Points)" << endl;
}

Vecteur::Vecteur( float x_deb, float y_deb, float x_fin, float y_fin )
  : debut( x_deb, y_deb ),
    fin( x_fin, y_fin )
{
  cout << "Vecteur::Constructeur avec parametres (recevant 4 coordonnees)" << endl;
}

Vecteur::Vecteur( const Vecteur& v )
  : debut( v.debut ),
    fin( v.fin )
{
  cout << "Vecteur::Constructeur par copie" << endl;

  /* debut = v.debut;
   * fin = v.fin
   * 
   * Point::Constructeur par copie --> v.debut
   * Point::Constructeur par copie --> v.fin
   * Point::Operation d'affectation
   * Point::Operation d'affectation
   */
}

Vecteur::~Vecteur()
{
  cout << "Vecteur::Destructeur" << endl;
}

void Vecteur::afficher() const
{
  cout << "Vecteur : " << endl;
  debut.afficher();
  fin.afficher();
}

