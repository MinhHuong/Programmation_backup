#include "Dame.h"
#include <iostream>
#include <cmath>

using namespace std;

Dame::Dame()
  : Piece("Dame")
{
  //cout << "Dame::Constructeur par defaut" << endl;
}

Dame::Dame(int x, int y, bool w)
  : Piece(x, y, "Dame", w),
    Tour(w), Fou(w)
{
  //cout << "Dame::Constructeur avec parametres" << endl;
}

Dame::~Dame()
{
  //cout << "Dame::Destructeur" << endl;
}

bool Dame::deplacement(Echiquier& echiq, int x, int y) const
{
  return ( Fou::deplacement(echiq, x, y) ||
	   Tour::deplacement(echiq, x, y) );
}

bool Dame::enMat( Echiquier& echiq ) const
{
  return ( Fou::enMat(echiq) ||
	   Tour::enMat(echiq) );
}
