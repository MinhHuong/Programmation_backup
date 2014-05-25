#include <iostream>
#include <math.h>
#include <cstdlib>
using namespace std;

int fact(int n)
{
  if (n<=0) return 1;
  int p = 1;  
  for (int i = 1; i <= n ; i++) 
    {
      p *= i;
    }
  return p;
}


void test_fact()
{
  bool testfact = true;
  int resultfact[6] = {1,2,6,24,120,720};
  for (int n = 1 ; n <= 6 ; n++)
    {
      if(fact(n) != resultfact[n - 1]) 
	{
	  testfact = false;
	  cout << "Test : Erreur" << endl;
	}
      else 
	{ cout << "Test : Ok" << endl;}
    }
}

	





