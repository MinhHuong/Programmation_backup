#ifndef _MY_UTIL_
#define _MY_UTIL_

#include <string>
#include <iostream>

using namespace std;

class Piece;
class Echiquier;
class Roi;

bool checkPieceMat( Piece* p, bool part );

// Tour, Fou
bool checkEachDirection( Echiquier& e, 
			 int x, int y, 
			 int dx, int dy, 
			 bool part );

void cinPosition( string form, int &x, int &y );

void coutPart( bool &part );

#endif
