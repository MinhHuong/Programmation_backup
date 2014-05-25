#include "Trottinette.h"

int main() {
  Roue r1(5);
  cout << r1.getDiametre() << endl;

  Roue r2;
  r2.setDiametre(7);
  cout << r2.getDiametre() << endl;

  Roue r3(r1);
  cout << r3.getDiametre() << endl;

  Roue r4(10);
  cout << r4.getDiametre() << endl;
  
  Trottinette T_1(15,20);
  T_1.changerRoueAvant(r4);
  T_1.changerRoueArriere(r1);
  cout << (T_1.getRoueAvant()).getDiametre() << endl;
  cout << (T_1.getRoueArriere()).getDiametre() << endl;
}
