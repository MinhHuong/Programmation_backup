#include <iostream>
#include <cstdlib> 
#include <string>
using namespace std;

int main()
{
  string mot = "tata";
  string s = "a";
  int n;

  n = mot.find(s);

  if( n == string::npos )
    cout << s << " pas trouve dans " << mot << endl;
  else
    cout << s << " trouve dans " << mot << " a la position " << n << endl;

  return EXIT_SUCCESS;
}


