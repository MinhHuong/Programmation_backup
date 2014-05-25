#include "Entier.h"

int main() {
  Entier e1;
  e1.init(5);
  e1.plus(6);

  Entier e2(3);
  e2.moins(7);

  Entier *e3=new Entier;
  e3->fois(8);

  Entier *e4=new Entier(8);
  e4->diviser(4);
  e4->diviser(0);

  delete e3;
  delete e4;  

  Entier a(5);
  Entier b(6);
  cout << (a+b).getValeur() << endl;
  return 0;
}
