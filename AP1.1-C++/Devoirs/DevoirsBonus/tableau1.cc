#include<iostream>
#include<cstdlib>
using namespace std;

void saisirTableau(int tab[], int taille)
{
  int i;
  for( i = 0 ; i < taille ; i++ )
    cin >> tab[i];
}

void afficherTableau(int tab[], int taille)
{
  int i;
  for( i = 0 ; i < taille ; i++)
    cout << tab[i] << " ";
  cout << endl;
}


int main()
{
  const int TAILLE = 5;
  int tabl[TAILLE];

  saisirTableau(tabl, TAILLE);
  afficherTableau(tabl, TAILLE);

  return EXIT_SUCCESS;
}
