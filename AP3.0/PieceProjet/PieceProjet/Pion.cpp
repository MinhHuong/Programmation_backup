#include "Pion.h"
#include <iostream>
#include <cmath>
#include <stdexcept>

using namespace std;

Pion::Pion()
  : Piece("Pion")
{
  //cout << "Pion::Constructeur par defaut" << endl;
}

Pion::Pion(int x, int y, bool w)
  : Piece(x, y, "Pion", w)
{
  //cout << "Pion::Constructeur avec parametres" << endl;
}

Pion::~Pion()
{
  //cout << "Pion::Destructeur" << endl;
}

bool Pion::deplacement(Echiquier& echiq, int x, int y) const
{
  if( x < 1 || x > 8 || y < 1 || y > 8 )
    {
      return false;
    }
  else
    {
      //capter l'autre Piece
      if( x-_x == -1 || x-_x == 1 )
	{
	  if( _isWhite )
	    {
	      return ( y-_y == 1 && capter( echiq, x, y ) );
	    }
	  else
	    {
	      return ( _y-y == 1 && capter( echiq, x, y ) );
	    }
	}
      
      if( abs( x-_x ) > 1 )
	{
	  return false;
	}

      // move normal
      if( _y == 7 || _y == 2 ) //first move
	{
	  if( _isWhite )
	    return ( y-_y >= 1 && y-_y <= 2 );
	  else
	    return ( _y-y >= 1 && _y-y <= 2 );
	}
      else 
	{
	  if( _isWhite ) 
	    return ( y-_y == 1 && echiq.getPiece( x, y ) == NULL );
	  else
	    return ( _y-y == 1 && echiq.getPiece( x, y ) == NULL );
	}
    }
}

bool Pion::enMat( Echiquier& echiq ) const
{
  int distance = _isWhite ? 1 : -1;
  int x_mod, y_mod = _y + distance;
  bool result = false;
  Piece* p;
  
  for( int dx = 1 ; dx >= (-1) ; dx-- )
    {
      if( dx != 0 )
	{
	  x_mod = _x + dx;

	  if( x_mod >= 1 && x_mod <= 8 &&
	      y_mod >= 1 && y_mod <= 8 )
	    {
	      p = echiq.getPiece(x_mod, y_mod);
	      result = ( result || checkPieceMat(p, _isWhite) );
	    }
	}
    }

  return result;
}

Dame& Pion::operator=( Piece* p ) 
{
  this->_nom = "Dame";
  this->_x = p->getX();
  this->_y = p->getY();
}
