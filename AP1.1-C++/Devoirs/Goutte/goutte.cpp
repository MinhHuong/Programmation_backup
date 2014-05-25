#include <iostream>
#include <unistd.h>
#include <cstdlib>
using namespace std;


int main()
{
  int N;
  cout << "Entrez N = " ; cin >> N ;

 
  for ( int k = 1 ; k < N-1 ; k++) // k : la ligne du 2e cadre (a l'interieur du 1er cadre)
    {
      for (int h = 1 ; h < N-1 ; h++) // h : la colonne du 2e cadre
	{
	  for (int i = 0 ; i < N ; i++) // i : la ligne du 1er cadre
	    {
	      for (int j = 0 ; j < N ; j++) // j : la colonne du 1er cadre
		{
		  if (i == 0 || i == N-1 || j == 0 || j == N-1)
		    cout << "#"; // dessiner le cadre
		  else if (i == h && j == k)
		    cout << "o"; // placer la boule "o" a une seule place dans un moment determine
		  else
		    cout << ' '; // ajouter les espaces dans les places restantes
		}
	      cout << endl; // pour deplacer la boule a la ligne suivante 
	    }

	  usleep (40000); // le programme s'arrete pendant 0.04 seconds (40000 microseconds)... 
	  system("clear"); //...avant d'effacer le cadre + la boule, puis re-afficher le cadre et 1 nouvelle boule  
	  if (k == N-2 && h == N-2) // alors si la boule arrive au bord du cadre et qu'on ne la veut pas s'arreter...
	    k = h = 1; // il faut re-affecter k,h leur premiere valeur = 1, et la boucle ci-dessus repete sans cesse 
	}
    }
}
  
