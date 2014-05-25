#include <iostream>
#include <cstdlib>
#include <math.h>
using namespace std;


/*
int main()
{
  cout << "Entrez votre note : " ; 
  float note;
  cin >> note;
  (note >= 10) ? cout << "Vous avez la moyenne" << endl : (note >= 8) ? cout << "Note non eliminatoire" << endl : cout << "Note eleminatoire" << endl; //1 autre forme de la condition
}
*/





/*
#define TAILLE 10

int main()
{
  int t[TAILLE];
  for ( int i = 0; i < TAILLE; i++)
    { cout << "t[" << i << "] = ";
      cin >> t[i];
    }
}
*/





/*#define taille 10

int main()
{
  int t[taille];
  for ( int i = 0 ; i < taille ; i++) 
    {
      cout << "t[" << i << "] = ";
      cin >> t[i];
    }
  for ( int i = 0 ; i < taille ; i++)
    {
      if (t[i] == 50)
	{
	  cout << "Il y a 50" << endl;
	  return 1;//pour sortir de la boucle mais le programme ne cesse pas
	}
      else if (i >= 9) // i >= 9 indique la derniere valeur du tableau, si le prog n'arrive pas a trouver la valuer 50, il va indiquer la ligne ci-dessous en 1 seule ligne au lieu d'en affiquer plusieurs 
	{
	  cout << "Pas de 50" << endl;
	}
    }
    }*/







/*
#define taille 10

int main()
{
  int t[taille];
  for ( int i = 0 ; i < taille ; i++) 
    {
      cout << "t[" << i << "] = ";
      cin >> t[i];
    }
  for ( int i = 0 ; i < taille ; i++) 
    {
      if (t[i] == 50)
	{  
	  cout << "Il y a 50" << endl;
	  return 1;
	}	
    } //on sort de la boucle si la condition t[i] == 50 n'est pas satisfaite, alors la ligne ci-dessous ne repete pas plusieurs fois
  cout << "Pas de 50" << endl;
}
*/



/*
int main()
{
  cout << "Entrez N : " ;
  int N;
  int somme = 0; //il faut indiquer la valeur debutante de somme sinon elle va prendre n'importe quelle valeur
  cin >> N;
  for ( int i = 1 ; i <= N ; i++)
    {
      somme += i;
    }
  cout << "La somme est = " << somme << endl;
}
*/




/*
int main()
{
  cout << "Entrez N : " ;
  int i,N;
  int somme = 0; 
  cin >> N;
  while ( i <= N )
    {
      somme += i;
      i++;
    }
  cout << "La somme est = " << somme << endl;
}
*/


/* ---CALCULER PI---

  int main()
  {
  double Ax = 1.0/2.0,Ay = sqrt(3.0)/2.0,Hx,Hy,h,AB,aire,pi; //elles sont tout variables dans la boucle, meme si elles ont deja une valeur (Ax,Ay)
  int Bx = 1, By = 0; //Bx et By sont invariables
  int N=6;
  int n;
  cout << "Combien de tour ? " ;
  cin >> n;
  for ( int i = 0; i < n ; i++ )
  {
  Hx = 0.5*(Ax + 1.0); //il vaut mieux utiliser les valuers de type float, EX : 1.0, 23.0 
  Hy = 0.5*Ay;
  h = sqrt(Hx*Hx + Hy*Hy);
  AB = sqrt ((Ax - 1.0)*(Ax - 1.0) + Ay*Ay);
  aire = (h*AB)/2.0;
  pi = N*aire;
  cout << "pi est " << pi << endl;
  Ax = (1.0/h)*Hx; //il faut les placer a la fin car apres calculer pi la valeur de Ax et Ay VONT CHANGER
  Ay = (1.0/h)*Hy;
  N *= 2; // N = N * 2
  }
  }
*/




/* ---CALCULER LE PRODUIT DES NOMBRES ENTIERS CONSECUTIFS---
  
  int fact(int n)
  {
  if (n<=0) return 1;
  int p = 1; //il faut tout d'abord determiner la valeur du produit !
  for (int i = 1; i <= n ; i++) //il faut i <= n car I COMMENCE A 1
  p *= i;
  return p; //pour attribuer la valuer de p a fact(n)
  }

  int main()
  {
  int n;
  for (int n = 1; n <= 10; n ++)
  cout << "fact(" << n << ") = " << fact(n) << endl; 
  }
*/




/* ---FONCTION RECURSIVE : CALCULER SELON LA FORMULE : X = X(X-1) + X(X -2)---

  int fib(int n) //FONCTION RECURSIVE, il faut 1 condition au debut
  {
  if (n <= 1) return 1;
  else
  return fib(n - 1) + fib(n - 2);
  }


  int main()
  {
  int N;
  cout << "N = " ; cin >> N;
  for (int n = 2; n <= N ; n++)
  cout << "fib(" << n << ")" << fib(n) << endl;
  }*/



/* ---FAIRE LE TRI DES NOMBRES---

#define taille 10


void echange_case (int t[],int i, int j)
{
  int x = t[j];
  t[j] = t[i];
  t[i] = x;
}


int main()
{
  int t[taille];

  for (int i = 0 ; i < taille ; i++)
    {
      cout << "t[" << i << "] = " ;
      cin >> t[i];
    }

  cout << "t : { " ;
  for (int i = 0 ; i < taille - 1 ; i++)
    cout << t[i] << " ," ;
  cout << t[taille - 1] << "}" << endl;

  for (int i = 0 ; i < taille - 1 ; i++)
    {
      for (int j = i+1 ; j < taille ; j++)
	if (t[i] > t[j])
	  echange_case (t,i,j);
    }

			

  cout << "t : { " ;
  for (int i = 0 ; i < taille - 1 ; i++)
    cout << t[i] << " ," ;
  cout << t[taille - 1] << "}" << endl;
} 
*/






/*  
int main()
{
  while(1)
    {system ("stty raw");
      char c = getchar();
      system ("stty cooked");

      switch (c) 
	{
	case 'a':
	  cout << "AVANCE" << endl;
	  break;
	case 'r':
	  cout << "RECULE" << endl;
	  break;
	case 13:
	  cout << "Au revoir" << endl;
	  exit(0);
	default:
	  cout << "Touche inconnue" << endl;
	  break;
	}
    }
}
*/


/*
int main()
{
  int nb;
  int cpt = 0;

  cin >> nb;

  while (nb != 0)
    {
      cpt++;
      cout << "Entrez un entier" ;
      cin >> nb; 
      cout << cpt << endl; }
  return EXIT_SUCCESS;
}
*/


/*
int main()
{
  int nb;
  int val = 0;
  
  cin >> nb;

  while (nb != 0)
    {
      val += nb;
      cout << "Entrez un entier = " << endl;
      cin >> nb;
    }

  cout << "La somme des entiers est " << val << endl;
  return EXIT_SUCCESS;
}
*/

/*
int main()
{
  int nb;
  int val = 0;
  int nb_saisies = 0;
  double avg = 0.0;
  
  cout << "Entrez 1 entier (0 pour arreter) = " ;
  cin >> nb;

  while (nb != 0)
    {
      nb_saisies ++;
      val += nb;
      cout << "Entrez 1 entier = " ;
      cin >> nb; 
    }

  cout << "La somme des entiers est = " << val << endl;
  cout << "Nombre de saisies = " << nb_saisies << endl;
  avg = 1.0 * val/nb_saisies;
  cout << avg << endl;

  return EXIT_SUCCESS;
}
*/


/*
int main()
{
  int nb;
  int gap = 0;
  cout << "Entrez 1 entier (0 pour arreter) = " ;
  cin >> nb ;
  
  while (nb != 0)
    {
      if (nb > gap)
	gap = nb;
      cout << "Entrez 1 entier (0 pour arreter) = " ;
      cin >> nb;
    }
  cout << "gap = " << gap << endl;
  return EXIT_SUCCESS;
}
*/
