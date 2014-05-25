#include <iostream>
#include <math.h>
using namespace std;

#define taille 10

void saisie_tab (int t[]);
void affichage_tab (int t[]);
void echanger_case (int t[],int i,int j);
void trier_methode_1 (int t[]);
void trier_methode_2 (int t[]);

//utilise VOID afin de rendre le MAIN plus propre et plus facile a verifier

int main()
{ int t[taille];
  
  saisie_tab (t);
  affichage_tab (t);
  trier_methode_1(t);
  affichage_tab (t); }



void saisie_tab (int t[])
{ 
  for (int i = 0 ; i < taille ; i++)
    { cout << "t[" << i << "] = ";
      cin >> t[i]; }
}
 

void affichage_tab (int t[])
{
  cout << "tab : { " ;
  for (int i = 0 ; i < taille - 1 ; i++)
    { cout << t[i] << ", ";}
  cout << t[taille - 1] << " } " << endl;
}
		    
	
void echanger_case(int t[],int i, int j)
{
  int x = t[j]; //alors x a la valeur de t[j], il faut prendre une variable intermediare pour ne pas perdre t[j]
  t[j] = t[i]; // t[j] a maintenant la valeur de t[i]
  t[i] = x; // t[i] perd sa valeur precedente et a maintenant la valeur de x, c'e-a-d de t[j]
}

	
void trier_methode_1 (int t[]) //chercher le minimum : on prend tout d'abord le premier nombre (t[0]) et puis comparer avec les 9 nombres qui restent pour chercher le minimum de ce tableau, puis on prend le 2e nombre (t[i]) et repete la procedure
{
  for (int i = 0 ; i < taille - 1 ; i++) //i < taille - 1 car on ne prend pas le dernier nombre de t[i] pour comparer
    { 
      for (int j = i + 1 ; j < taille ; j++) //j = i + 1 signifie on commence en prenant le nombre t[j] a cote de t[i] (par ex : on compare t[0] de i et t[1] de j), c'est pourquoi j < taille car on ne prend pas le 1er nombre, pourtant il faut prendre le dernier du tableau pour comparer a t[i]
	{ if (t[i] > t[j])
	    echanger_case (t,i,j); }
    }
}
	  

void trier_methode_2 (int t[])
{
  bool trier;
  do
    { trier = true;
      for (int i = 0 ; i < taille - 1 ; i++)
	{ if (t[i] > t[i + 1])
	    { echanger_case (t,i,i + 1); 
	      trier = false ; }
	}       	
    }
  while (!trier); //si le programme arrive a tout trier, le IF n'est plus satisfait, alors "trier" n'attribue pas "false", et (!trier) devient desormais false, enfin on sort de la boucle "do...while" et le programme termine
} 
    
	     
	  
