#include "Roi.h"
#include <iostream>

using namespace std;

Roi::Roi()
  : Piece("Roi")
{
  //cout << "Roi::Constructeur par defaut" << endl;
}

Roi::Roi(int x, int y, bool w)
  : Piece(x, y, "Roi", w)
{
  //cout << "Roi::Constructeur avec parametres (coordonnees)" << endl;
}

Roi::Roi(bool w)
  : Piece(w)
{
  //cout << "Roi::Constructeur avec parametres (bool)" << endl;
  _nom = "Roi";
}

Roi::~Roi()
{
  //cout << "Roi::Destructeur" << endl;
}

bool Roi::deplacement(Echiquier& echiq, int x, int y) const
{
  return ( (x >=1 && x <= 8 && y >=1 && y <= 8) && 
	   ( echiq.getPiece(x, y) == NULL ) &&
	   ((x == _x+1 && y == _y+1) ||
	    (x == _x+1 && y == _y) ||
	    (x == _x+1 && y == _y-1) ||
	    (x == _x   && y == _y+1) ||
	    (x == _x   && y == _y-1) ||
	    (x == _x-1 && y == _y+1) ||
	    (x == _x-1 && y == _y) ||
	    (x == _x-1 && y == _y-1)) );
}

bool Roi::enMat( Echiquier& echiq ) const
{
  int x_mod, y_mod;
  bool result = false;
  Piece *p;

  for( int dx = 1 ; dx >= (-1) ; dx-- )
    {
      x_mod = _x + dx;

      if( x_mod <= 8 && x_mod >= 1 ) 
	{
	  for( int dy = 1 ; dy >= (-1) ; dy-- )
	    {
	      y_mod = _y + dy;

	      if( y_mod >= 1 && y_mod <= 8 && !(dx == 0 && dy == 0) )
		{
		  p = echiq.getPiece(x_mod, y_mod);
		  result = ( result || 
			     checkPieceMat(p, _isWhite) );
		}
	    }
	}
    }

  return result;
}

bool Roi::etreEnMat( Echiquier& echiq )
{
  bool result = false, partial;
  Piece* p;

  for( int i = 0 ; i < 64 ; i++ )
    {
      p = echiq.getPiece(i);
      
      if( p != NULL && p != this )
	{
	  partial = p->enMat(echiq);
	  result = ( result || partial );
	}
    }

  return result;
}

bool Roi::enPat( Echiquier& echiq )
{
  // aucune piece ne peut se deplacer sauf le Roi
  // Reste a finir


  // aucun mouement du Roi n'est valide sans le mettre en echec

  int nbInvalide = 0, totalDeplacement = 0, old_x = _x, old_y = _y;
  Roi old_roi( old_x, old_y, _isWhite );

  echiq.enlever( old_x, old_y );
  
  for( int dx = 1 ; dx >= (-1) ; dx-- )
    {
      _x = old_x;
      _y = old_y;

      _x = _x + dx;
      
      if( _x >= 1 && _x <= 8 )
	{
	  for( int dy = 1 ; dy >= (-1) ; dy-- )
	    {
	      _y = old_y;
	      _y = _y + dy;

	      if( _y >= 1 && _y <= 8 && !(dx == 0 && dy == 0) )
		{
		  totalDeplacement++;
		  echiq.deplacerPiece( this, _x, _y );

		  if( this->etreEnMat(echiq) ) // nombre de deplacements INVALIDES
		    {
		      nbInvalide++;
		    }
		  
		  echiq.affiche();
		  echiq.enlever( _x, _y );
		}
	    }
	}
    }

  echiq.placerPiece( &old_roi );
  echiq.affiche();

  return ( nbInvalide == totalDeplacement );
}
