#include <iostream>
#include <math.h>
#include "factsomme.h"

int main()
{
  int N;
  cout << "Entrez N = " ; cin >> N;

  int n;
  for ( int n = 1 ; n <= N ; n++)
    cout << "fact(" << n << ")" << fact(n) << endl;
}
