#ifndef __MYUTIL__
#define __MYUTIL__

#include "Point.h"

enum color{ white=' ', black='*', red='@', green='#', blue='%' };

void cinColour( char & col );
void cinPoint( Point & a );

void cinLine( char & col, Point & sw, Point & ne );
void cinLineHoriz( char & col, Point & sw, int & w );

void cinLineBrok( char & col, Point & sw, Point & ne, Point & m );

void cinRectangle( char & col, Point & sw, Point & ne );

void cinCircle( char & col, Point & c, int & r );

void cinTriangle(char & col, Point & a, Point & b, Point & c);

void cinSquare(char & col, Point & a, int & length);

void cinPosition(int & indice);

bool equation(Point& a, Point& b, Point& c);

#endif

