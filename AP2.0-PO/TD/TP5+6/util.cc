#include <iostream>
#include "Point.h"
#include "util.h"

using namespace std;

void
cinColour( char & col )
{
  cout << "Couleur ? b(lack) r(ed) g(reen) B(lue)" << endl;
  cin >> col;
  while( col!='b' && col!='r' && col!='g' && col!='B' )
  {
    cout << "Pas definie, recommencez" << endl;
    cin >> col;
  }
  switch( col )
  {
    case 'b': col = black; break;
    case 'r': col = red;   break;
    case 'g': col = green; break;
    case 'B': col = blue;  break;
  }
}

void
cinPoint( Point & a )
{
  int x, y;
  cout << "abs puis ord" << endl;
  cin >> x >> y;
  a.setX( x );
  a.setY( y );
}

void
cinLine( char & col, Point & sw, Point & ne )
{
  cout << "Saisie de Line" << endl;
  cinColour( col );
  cout << "Point sw ?  ";
  cinPoint( sw );
  cout << "Point ne ?  ";
  cinPoint( ne );
}

void
cinLineHoriz( char & col, Point & sw, int & w )
{
  cout << "Saisie de Line horizontale" << endl;
  cinColour( col );
  cout << "Point sw ?  ";
  cinPoint( sw );
  cout << "length ?" << endl;
  cin >> w;
}

void
cinLineBrok( char & col, Point & sw, Point & ne, Point & m )
{
  cout << "Saisie de Line cassee" << endl;
  cinColour( col );
  cout << "Point sw ?  ";
  cinPoint( sw );
  cout << "Point ne ?  ";
  cinPoint( ne );
  cout << "Point m ?  ";
  cinPoint( m );
}

void 
cinRectangle( char & col, Point & sw, Point & ne )
{
  cout << "Saisie de Rectangle" << endl;
  cinColour( col );
  cout << "Point sw ?  ";
  cinPoint( sw );
  cout << "Point ne ?  ";
  cinPoint( ne );
}

void 
cinCircle( char & col, Point & c, int & r )
{
  cout << "Saisie de Circle" << endl;
  cinColour( col );
  cout << "Point center ?  ";
  cinPoint( c );
  cout << "radius ?" << endl;
  cin >> r;
}

void cinTriangle(char & col, Point & a, Point & b, Point & c) {
  cout << "Saisie de Triangle" << endl;
  cinColour(col);
  cout << "Point 1 ? ";
  cinPoint(a);
  cout << "Point 2 ? ";
  cinPoint(b);
  cout << "Point 3 ? ";
  cinPoint(c);
}

void cinSquare(char & col, Point & a, int & length) {
  cout << "Saisie de Square" << endl;
  cinColour(col);
  cout << "Point bas-gauche ? ";
  cinPoint(a);
  cout << "Longueur d'un cote ? ";
  cin >> length;
}

void cinPosition(int & indice) {
  cout << "Saisie de l'indice a trouver : ";
  cin >> indice;
}

bool equation(Point& a, Point& b, Point& c) {
  int x1 = a.getX(), y1 = a.getY(),
    x2 = b.getX(), y2 = b.getY();

  int px = c.getX(), py = c.getY();

  return ( (y1-y2)*(px-x1) + (x2-x1)*(py-y1) == 0);
}
