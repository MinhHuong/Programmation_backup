#include<iostream>
#include<cstdlib>
using namespace std;

void saisie( int* ptr_deb, int* ptr_fin )
{
  // tant qu'on n'a pas passe la derniere case.
  while ( ptr_deb != ptr_fin )
    {
      cin >> (*ptr_deb);  // saisie de la valeur
      ptr_deb++;          // on passe a la case suivante
    }
}

void metAZero( int tbl[], int n )
{
  int* ptr_deb = tbl;
  int* ptr_fin = tbl + n;
  // tant qu'on n'a pas passe la derniere case.
  while ( ptr_deb != ptr_fin )
    {
      *ptr_deb = 0;  // valeur a 0
      ptr_deb++;     // on passe a la case suivante
    }
}

int main()
{
  int t[ 5 ];
  int* p1 = t;     // Equivalent a int* p1 = &t[ 0 ]
  int* p2 = t + 5; // Equivalent a int* p1 = &t[ 5 ]
  saisie( p1, p2 );
  // I) Ecrire la fonction qui affiche le contenu du tableau
  // affiche( p1, p2 );
  // II) Ecrire la fonction qui somme les elements du tableau
  // cout << somme( p1, p2 ) << endl;
  // III) Verifiez ensuite que l'on aurait aussi pu ecrire :
  // affiche( t, p2 );
  // car la valeur de p1 est t. Ou encore :
  // affiche( t, t + 5 );
  // IV) Verifiez apres que l'adresse d'un tableau n'est pas modifiable :
  // t++;  // interdit
  // p1++; // autorise
  // V) Verifiez enfin qu'un tableau n'est pas recopie lorsque passe en
  // parametre.
  // metAZero( t, 5 ); affiche( t, t + 5 );
  return EXIT_SUCCESS;
}
