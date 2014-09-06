#include "Entier.h"
#include <sstream>
#include <string>

using namespace std;

Entier::Entier()
{
  cout << "Entier::Constructeur par defaut" << endl;
  nombre = 0;
}

Entier::Entier( int nb )
{
  cout << "Entier::Constructeur avec parametres" << endl;
  nombre = nb;
}

Entier::Entier( const Entier& e )
{
  cout << "Entier::Constructeur par copie" << endl;
  nombre = e.nombre;
}

Entier::~Entier()
{
  cout << "Entier::Destructeur" << endl;
}

Entier Entier::operator=( const Entier& e )
{
  cout << "Entier::Operateur d'affectation" << endl;
  if( this != &e )
    {
      nombre = e.nombre;
    }

  return *this;
}

Entier Entier::operator/( const Entier& e ) const
{
  Entier resultat;

  if( e.nombre != 0 )
    {
      resultat.nombre = nombre / e.nombre;
    }

  return resultat;
}

Entier Entier::operator+( const Entier& e ) const
{
  Entier resultat;
  resultat.nombre = nombre + e.nombre;

  return resultat;
}

Entier Entier::operator-( const Entier& e ) const
{
  Entier resultat;
  resultat.nombre = nombre - e.nombre;

  return resultat;
}

Entier Entier::operator*( const Entier& e ) const
{
  Entier resultat;
  resultat.nombre = nombre * e.nombre;
  
  return resultat;
}

string Entier::toString() const
{
  ostringstream oss;
  oss << nombre;
  string s = oss.str();
  return s;
}

void Entier::incrementer() 
{
  nombre++;
}

void Entier::doSomething()
{
  incrementer();
}

const int Entier::getValue()
{
  return nombre;
}
