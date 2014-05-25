#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

int main(int argc, char* argv[])
{
  string mot, s, a;
  int n;

  if(argc < 3) {
    cout << "Erreur : il manque des arguments." << endl;
    cout << "Usage : " << argv[0] << " mot s" << endl;
    exit(-1);
  }

  mot = argv[1];
  s  = argv[2];

  n = mot.find(s);

  if( n == string::npos )
    cout << s << " pas trouve dans " << mot << endl;
  else
    cout << s << " trouve dans " << mot << " a la position " << n << endl;
  
  return EXIT_SUCCESS;
}


