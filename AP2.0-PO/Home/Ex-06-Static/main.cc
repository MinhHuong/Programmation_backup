#include <iostream>
#include "Compter.h"

using namespace std;

int main()
{
  Compter * c = new Compter;
  cout << c->getCompter() << endl;

  Compter * c2 = new Compter;
  cout << c2->getCompter() << endl;

  delete c;
  cout << c->getCompter() << endl;

  delete c2;
  cout << c2->getCompter() << endl;

  return 0;
}
