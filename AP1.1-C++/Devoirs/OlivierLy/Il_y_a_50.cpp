#include <iostream>
using namespace std;

#define taille 10

int main()
{
  int t[taille];
  
  for (int i = 0 ; i < taille; i++)
    { cout << "t[" << i << "] = " ;
      cin >> t[i]; }

  for (int i = 0 ; i < taille ; i++)
    {
      if (t[i] == 50)
	{ cout << "Il y a 50" << endl;
	  return 1 ; } //s'il y a 50, "break" nous sort du programme, celui-ci termine et ne fait plus rien
    }

  cout << "Pas de 50" << endl; //sans trouver 50, le "for" ci-dessus ne s'execute pas, alors le programme affiche sur l'ecran "Pas de 50"
}

      

  
