#include "Cavalier.h"

#include <iostream>
#include <cmath>

using namespace std;

Cavalier::Cavalier()
  : Piece("Cavalier")
{
  //cout << "Cavalier::Constructeur par defaut" << endl;
}

Cavalier::Cavalier(int x, int y, bool w)
  : Piece(x, y, "Cavalier", w)
{
  //cout << "Cavalier::Constructeur avec parametres" << endl;
}

Cavalier::~Cavalier()
{
  //cout << "Cavalier::Destructeur" << endl;
}

bool Cavalier::deplacement(Echiquier& echiq, int x, int y) const
{
  if( x <= 0 || x > 8 || y <= 0 || y > 8 )
    {
      return false;
    }
  else
    {
      if( abs(_x-x) == 2 )
	{
	  return ( abs(_y-y) == 1 );
	}
      else if( abs(_x-x) == 1 )
	{
	  return ( abs(_y-y) == 2 );
	}
      else
	{
	  return false;
	}
    }
}

bool Cavalier::enMat( Echiquier& echiq ) const
{
  bool result = false;
  Piece* p;
  int x, y;

  for( int dx = 2 ; dx >= -2 ; dx-- )
    {
      for( int dy = 2 ; dy >= -2 ; dy-- )
	{
	  if( dx != 0 && dy != 0 && abs(dx) != abs(dy) )
	    {
	      x = _x + dx;
	      y = _y + dy;

	      if( x >= 1 && x <= 8 && y >= 1 && y <= 8 )
		{
		  p = echiq.getPiece(x, y);
		  result = ( result || checkPieceMat(p, _isWhite) );
		}
	    }
	}
    }

  return result;
}
