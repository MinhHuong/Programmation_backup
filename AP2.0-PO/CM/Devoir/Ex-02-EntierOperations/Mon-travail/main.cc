#include "operation.h"

int main() {
  Entier e1;
  e1.init(4,5);
  e1.plus();
  //e.init(6,3);
  //e.plus();
  //e.moins();	
  //e.fois();
  //e.diviser();
  //e.init(6,0);
  //e.diviser();
  //e.nb_1=3;
  //cout << e.nb_1;
  //ca ne marche pas car nb_1 est private
  //e.nb_2=5;
  //cout << e.nb_2 << endl;
  Entier e2(3,7);
  e2.plus();
  Entier *e3=new Entier(5,6);
  e3->plus();
  delete e3;

  Entier *e4=new Entier;
  e4->init(7,8);
  e4->moins();
  delete e4;

  Entier a(1,2);
  Entier b(3,4);
  cout << (a+b).getValue_1() << endl;
  cout << (a+b).getValue_2() << endl;
}
