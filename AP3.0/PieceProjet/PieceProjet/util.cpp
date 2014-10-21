#include "util.h"
#include "Piece.h"
#include "Echiquier.h"
#include "Roi.h"

#include <typeinfo>

bool checkPieceMat( Piece* p, bool part )
{
  return ( p != NULL &&
	   typeid(*p) == typeid(Roi) &&
	   p->isWhite() != part );
}

bool checkEachDirection( Echiquier& e, int x, int y, int dx, int dy, bool part )
{
  Piece* p;

  while( x >= 1 && x <= 8 && 
	 y >=1 && y <= 8 )
    {
      if( (x == 8 && dx > 0) ||
      	  (y == 8 && dy > 0) ||
      	  (x == 1 && dx < 0) ||
      	  (y == 1 && dy < 0) )
      	break;
      
      x += dx;
      y += dy;
      p = e.getPiece(x, y);
      
      if( checkPieceMat(p, part) )
	return true;
    }
  
  return false;
}

void cinPosition( std::string form, int &x, int &y )
{
  cout << "\nEntrez x et y pour " << form << " : "; 
  cin >> x >> y;
}

void coutPart( bool &part )
{
  string info = part ? "BLANC" : "NOIR";
  cout << "\n\t----- JOUEUR " << info << " -----" << endl;
}
