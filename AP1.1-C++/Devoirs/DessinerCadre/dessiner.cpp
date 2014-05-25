#include <iostream>
#include <math.h>
using namespace std;



int main()
{
  int N;
  cout << "N = "; cin >> N;

  string msg;
  cout << "Message = " ; cin >> msg;

  for (int i = 0 ; i < N ; i++)
    {
      if (i == N/2) //alors maintenant la position de i == N/2 est vide (sur f = 0 meme sur f = N - 1)
	{
	  int espace;
	  espace = (N - msg.length()-2)/2; //il faut moins 2 car "2" c'est la valeur de la place de 2 "x" au bord du cadre
	  cout << "x";
	  for ( int k = 0 ; k < espace ; k++)
	    cout << " " ;
	  cout << msg;
	  for ( int k = 0 ; k < espace ; k++)
	    cout << " " ;
	  if ((N - msg.length() - 2) % 2 == 1) //(N - msg.length() - 2) % 2 : la formule a calculer l'espace; on verifie si espace est pair/impair; si impair, il faut ajouter un " " devant "x" pour mieux controler le cadre, si pair, vice versa 
	    cout << " x";
	  else
	    cout << "x"; 
	}

      
      else //c'e-a-d pour les i qui sont DIFFERENTS de N/2 
	{
	 
	  for (int f = 0 ; f < N ; f++)
	    {
	      if (f == 0 || f == N - 1 || i == 0 || i == N - 1)
		cout << "x";
	      else
		cout << ' '; //ici on finit le traiteM de TOUTES les colonnes de la PREMIERE ligne (f0) 
	    }
	}
      cout << endl; //cela permet de sauter a la 2e ligne du cadre, puis la boucle for(f) continue
    }
}

