#include "Fou.h"
#include <iostream>
#include <cmath>

using namespace std;

Fou::Fou()
  : Piece("Fou")
{
  //cout << "Fou::Constructeur par defaut" << endl;
}

Fou::Fou(int x, int y, bool w)
  : Piece(x, y, "Fou", w)
{
  //cout << "Fou::Constructeur avec parametres" << endl;
}

Fou::Fou(bool w)
  : Piece(w)
{
  //cout << "Fou::Constructeur avec parametres (bool)" << endl;
}

Fou::~Fou()
{
  //cout << "Fou::Destructeur" << endl;
}

bool Fou::deplacement(Echiquier& echiq, int x, int y) const
{
  if( x < 1 || x > 8 || y < 1 || y > 8 ||
      echiq.getPiece(x, y) != NULL )
    {
      return false;
    }

  if( abs(_x-x) != abs(_y-y) ) return false;

  int dx = ( _x < x ) ? 1 : -1;
  int dy = ( _y < y ) ? 1 : -1;
  int limit = abs( _x-x );
  int i = _x, j = _y;

  while( limit > 0 )
    {
      i += dx;
      j += dy;

      if( echiq.getPiece(i, j) != NULL )
	return false;
      else
	limit--;
    }
    
  return true;
}

bool Fou::enMat( Echiquier& echiq ) const
{
  // Fou a 4 possibilites de deplacement
  return ( checkEachDirection(echiq, _x, _y, 1, 1, _isWhite)  ||
	   checkEachDirection(echiq, _x, _y, 1, -1, _isWhite) ||
	   checkEachDirection(echiq, _x, _y, -1, 1, _isWhite) ||
	   checkEachDirection(echiq, _x, _y, -1, -1, _isWhite) );
}
