#include <iostream>
#include <cstdlib>
#include "Entier.h"

using namespace std;

int main()
{
  Entier a(3);

  cout << a.toString() << endl;
  a.toString() = "4";
  cout << a.toString() << endl;

  return EXIT_SUCCESS;
}
