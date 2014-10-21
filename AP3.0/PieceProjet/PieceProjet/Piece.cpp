#include "Piece.h"
#include <iostream>
#include <string>

using namespace std;

int Piece::_compteur = 0;

Piece::Piece()
{
  _x = _y = -1;
  _nom = "";
  _isWhite = false;
  _compteur++;

  //cout << "Piece::Constructeur par defaut" << endl;
}

Piece::Piece(int x, int y, string n, bool white)
{
  _compteur++;

  if( x > 0 && x < 9 ) _x = x;
  else 
    {
      cout << "Coordonnee x invalide" << endl;
      _x = -1;
    }

  if( y > 0 && y < 9 ) _y = y;
  else 
    {
      cout << "Coordonnee y invalide" << endl;
      _y = -1;
    }

  _nom = n;
  _isWhite = white;

  //cout << "Piece::Constructeur avec parametres" << endl;
}

Piece::Piece(bool w)
{
  _isWhite = w;
  _x = _y = -1;
  _nom = "";
  _compteur++;

  //cout << "Piece::Constructeur avec parametres (bool)" << endl;
}

Piece::Piece(string nom)
{
  _nom = nom;
  _x = _y = -1;
  _isWhite = false;
  _compteur++;
  //cout << "Piece::Constructeur avec parametres (string)" << endl;
}

Piece::~Piece()
{
  _compteur--;
  //cout << "Piece::Destructeur" << endl;
}

void Piece::afficher()
{
  cout << "\n---------------------------\n";
  cout << "Position (" << _x << " , " << _y << " )" << endl;
  cout << "Nom : " << _nom << endl;

  string part = _isWhite ? "Blanc" : "Noir";
  cout << "Couleur : " << part << endl;
  cout << "---------------------------\n";
}

int Piece::getY() const
{
  return _y;
}

int Piece::getX() const
{
  return _x;
}

string Piece::getNom() const
{
  return _nom;
}

bool Piece::isWhite() const
{
  return _isWhite;
}

int Piece::getCompteur()
{
  return _compteur;
}

void Piece::setX(int x)
{
  _x = x;
}

void Piece::setY(int y)
{
  _y = y;
}

void Piece::setNom(string n)
{
  _nom = n;
}

void Piece::setPart(bool w)
{
  _isWhite = w;
}

bool Piece::validerEndroit() const
{
  return ( _x >= 1 && _x <= 8 && _y >= 1 && _y <= 8 );
}

Piece& Piece::operator=( const Piece& p )
{
  this->_nom = p._nom;
  this->_isWhite = !(p._isWhite);
}

bool Piece::capter( Echiquier& echiq, int x, int y ) const
{
  Piece* p = echiq.getPiece( x, y );
  return ( p != NULL && p->isWhite() != _isWhite );
}
