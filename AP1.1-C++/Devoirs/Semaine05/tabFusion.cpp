#include <iostream>
#include <cstdlib>
using namespace std;

/********************************************** DECLARER DES VARIABLES *********************************************/

const int MAX = 100;

int tab1[MAX];
int tab2[MAX];

/*************************************************** PROTOTYPES ****************************************************/

void saisirTab(int tab[], int taille);
void afficherTab(int tab[], int taille);
void declarerTab(int tab[], int & taille, int nb);

void fusionnerTab(int tab1[], int taille1, int tab2[], int taille2, int & tailleSum);

void echangerCase(int tab[], int i, int j);
void saisirCroissant(int tab[], int taille);

/****************************************************** MAIN *******************************************************/

int main() {
  int nb, taille1, taille2;
  declarerTab(tab1, taille1, 1);
  declarerTab(tab2, taille2, 2);

  int tailleSum;
  fusionnerTab(tab1, taille1, tab2, taille2, tailleSum);
  saisirCroissant(tab1, tailleSum);
  afficherTab(tab1, tailleSum);
}

/**************************************************** FONCTIONS ****************************************************/

void saisirTab(int tab[], int taille) {
  for (int i = 0 ; i < taille ; i++) {
    cout << "Entrez le nombre : " ;
    cin >> tab[i];
  }
}


void afficherTab(int tab[], int taille) {
  cout << "Tab : " ;
  for (int i = 0 ; i < taille ; i++)
    cout << tab[i] << " ";
  cout << endl;
}

void declarerTab(int tab[], int & taille, int nb) {
  cout << "TAB " << nb << endl;
  cout << "La taille : "; cin >> taille;
  saisirTab(tab, taille);
  afficherTab(tab, taille);
  cout << endl;
}

void fusionnerTab(int tab1[], int taille1, int tab2[], int taille2, int & tailleSum) {
  tailleSum = taille1 + taille2;
  
  int j = 0;
  for (int i = taille1 ; i < tailleSum ; i++) {
    tab1[i] = tab2[j];
    j++;
  }
  
  cout << "Tab apres la fusion : ";
  for (int i = 0 ; i < tailleSum ; i++)
    cout << tab1[i] << " ";
  cout << endl;
}


void echangerCase(int tab[], int i, int j) {
  int temp = tab[i];
  tab[i] = tab[j];
  tab[j] = temp;
}


void saisirCroissant(int tab[], int taille) {
  for (int i = 0 ; i < taille - 1 ; i++)
    for (int j = i + 1 ; j < taille ; j++)
      if (tab[i] > tab[j])
	echangerCase(tab, i, j);
}


