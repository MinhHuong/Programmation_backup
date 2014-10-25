#include "Ligne.h"
#include <iostream>

using namespace std;

Ligne::Ligne()
{
  debut = new Point;
  fin = new Point;
  cout << "Ligne::Constructeur par defaut" << endl;
}

Ligne::Ligne( Point* begin, Point* end )
{
  debut = begin;
  fin = end;
  cout << "Ligne::Constructeur avec parametres (2 Points)" << endl;
}

Ligne::Ligne( float x_begin, float y_begin, float x_end, float y_end )
{
  debut = new Point( x_begin, y_begin );
  fin = new Point( x_end, y_end );
  cout << "Ligne::Constructeur avec parametres (4 coordonnees" << endl;
}

Ligne::Ligne( const Ligne& l )
{
  debut = l.debut;
  fin = l.fin;
  cout << "Ligne::Constructeur par copie" << endl;
}

Ligne::~Ligne()
{
  if( debut != NULL ) delete debut;
  if( fin != NULL ) delete fin;

  cout << "Ligne::Destructeur" << endl;
}

void Ligne::afficher() const
{
  cout << "Ligne :" << endl;
  debut->afficher();
  fin->afficher();
}
