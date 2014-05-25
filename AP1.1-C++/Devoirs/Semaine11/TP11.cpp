#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

void substituer(string & mot, char s2, int n) {
  for (int i = 0 ; i < mot.length() ; i++)
    if (i == n)
      mot[i] = s2;
}


int main()
{
  string mot, find;
  char replace;
  int n;

  cout << "Entrez le mot : ";
  cin >> mot;
  cout << "Entrez le mot a trouver : ";
  cin >> find;

  n = mot.find(find);

  if (n == string::npos)
    cout << find << " pas trouve dans " << mot << endl;
  else 
    cout << find << " trouve dans " << mot << " a la position " << n << endl;
  
  cout << "Entrez le mot a remplacer : ";
  cin >> replace;

  substituer(mot, replace, n);
  cout << mot << endl;

  return EXIT_SUCCESS;
}

