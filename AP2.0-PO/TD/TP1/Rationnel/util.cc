#include "util.h"
#include <string>
#include <sstream>
#include <iostream>

using namespace std;

int pgcd(int x, int y) {
  if (x == y)
    return x;
  if (x < 0)
    x *= (-1);
  if (y < 0)
    y *= (-1);
  if (x > y)
    return pgcd(y,x-y);
  else
    return pgcd(x,y-x);
}


string intToString(int x) {
  ostringstream oss;
  oss << x;
  string s = oss.str();
  return s;
}


void menu() {
  cout << "\n============ MANIPULATION DES NOMBRES RATIONNELS ============\n\n"
       << "   1. Ecrire un nombre rationnel" << endl
       << "   2. Inverser le nombre" << endl
       << "   3. Tester l'egalite" << endl
       << "   4. Additionner" << endl
       << "   5. Soustraire" << endl
       << "   6. Multiplier" << endl
       << "   7. Diviser" << endl
       << "   8. Afficher le nombre" << endl
       << "\n======================== ************** =========================\n";
}


void cinNombre(int& n, int& d, Rationnel& r) {
  cout << "Entre le nombre (num puis deno) : ";
  cin >> n >> d;
  r.setNum(n);
  r.setDeno(d);
}


void cinResult(Rationnel a, Rationnel b, Rationnel c, char op) {
  // operateur + - * /
  if ( (c.getNum() != 0) && (c.getDeno() != 0) ) 
    cout << a.toString_normal() << ' ' << op << ' ' << b.toString_normal() << " = " << c.toString_reduit() << endl;

  // egalite
  else 
    cout << a.toString_normal() << ' ' << op << ' ' << b.toString_normal() << endl;
}
