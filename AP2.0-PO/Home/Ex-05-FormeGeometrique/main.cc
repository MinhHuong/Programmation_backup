#include <iostream>
#include <cstdlib>

#include "Rectangle.h"
#include "Carre.h"

using namespace std;

int main()
{
  Carre * rect = new Carre(6);

  delete rect;

  return EXIT_SUCCESS;
}
