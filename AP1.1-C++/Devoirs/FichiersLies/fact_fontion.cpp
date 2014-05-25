#include <iostream>
using namespace std;

#define taille 6

int fact (int n)
{
  if (n <= 1) return 1;
  else
    return n*fact(n - 1);
}
