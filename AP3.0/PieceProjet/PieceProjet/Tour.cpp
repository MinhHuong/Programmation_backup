#include "Tour.h"

#include <iostream>
#include <cmath>

using namespace std;

Tour::Tour()
  : Piece("Tour")
{
  //cout << "Tour::Constructeur par defaut" << endl;
}

Tour::Tour(int x, int y, bool w)
  : Piece(x, y, "Tour", w)
{
  //cout << "Tour::Constructeur avec parametres" << endl;
}

Tour::Tour(bool w)
  : Piece(w)
{
  //cout << "Tour::Constructeur avec parametres (bool)" << endl;
}

Tour::~Tour()
{
  //cout << "Tour::Destructeur" << endl;
}

bool Tour::deplacement(Echiquier& echiq, int x, int y) const
{
  if( x < 1 || x > 8 || y < 1 || y > 8 || 
      ( x == _x && y == _y ) )
    {
      return false;
    }

  int deb, limit;

  if( x == _x ) 
    {
      deb = ( _y < y ) ? _y : y;
      limit = abs( _y-y );
      
      while( limit > 0 )
	{
	  deb++;

	  if( echiq.getPiece( _x, deb ) != NULL )
	    {
	      return false;
	    }
	  else
	    {
	      limit--;
	    }
	}

      return true;
    }

  if( y == _y )
    {
      deb = ( _x < x ) ? _x : x;
      limit = abs( _x-x );

      while( limit > 0 )
	{
	  deb++;

	  if( echiq.getPiece( deb, _y ) != NULL )
	    {
	      return false;
	    }
	  else
	    {
	      limit--;
	    }
	}

      return true;
    }
}

bool Tour::enMat( Echiquier& echiq ) const
{
  // Tour a 4 possibilites de deplacement
  return ( checkEachDirection(echiq, _x, _y, 1, 0, _isWhite) ||
	   checkEachDirection(echiq, _x, _y, -1, 0, _isWhite) ||
	   checkEachDirection(echiq, _x, _y, 0, 1, _isWhite) ||
	   checkEachDirection(echiq, _x, _y, 0, -1, _isWhite) );
}
