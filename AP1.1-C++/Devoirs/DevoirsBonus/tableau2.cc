#include<iostream>
#include<cstdlib>
using namespace std;

const int TAILLE = 5;
typedef int TTabInt[TAILLE];

void saisirTableau(TTabInt tab, int taille)
{
  int i;
  for( i = 0 ; i < taille ; i++ )
    cin >> tab[i];
}

void afficherTableau(TTabInt tab, int taille)
{
  int i;
  for( i = 0 ; i < taille ; i++ )
    cout << tab[i] << " ";
  cout << endl;
}

int main()
{
  TTabInt tabl;
 
  saisirTableau(tabl, TAILLE);
  afficherTableau(tabl, TAILLE);

  return EXIT_SUCCESS;
}


