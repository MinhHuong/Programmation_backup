#include <iostream>
#include <cstdlib>
#include <unistd.h>
#include <math.h>
#include <stdio.h>
#include <termios.h>
using namespace std;

/*****************************************************************************************************************/

void saisirTab(int t[], int n);
void afficherTab(int t[], int n);
void echangerCase(int t[], int x, int y);
void saisirCroissant(int t[], int n);

/*****************************************************************************************************************/

int main() {
  int taille1;
  cout << "Entrez la taille du tableau 1 : ";
  cin >> taille1;
  int tab1[taille1];
  saisirTab(tab1,taille1);
  afficherTab(tab1,taille1);

  int taille2;
  cout << "Entrez la taille du tableau 2 : ";
  cin >> taille2;
  int tab2[taille2];
  saisirTab(tab2,taille2);
  afficherTab(tab2,taille2);

  int taille;
  taille = taille1 + taille2;
  int tab[taille];
  for (int i = 0 ; i < taille ; i++) {
    if (i >= 0 && i <= taille1 - 1)
      tab[i] = tab1[i];
    else if (i >= taille1 && i <= taille - 1)
      tab[i] = tab2[i - taille1];
  }

  afficherTab(tab,taille);
  saisirCroissant(tab,taille);
  afficherTab(tab,taille); 
}

/*****************************************************************************************************************/

void saisirTab(int t[], int n) {
  for (int i = 0 ; i < n ; i++) {
    cout << "tab[" << i << "] = ";
    cin >> t[i];
  }
}


void afficherTab(int t[], int n) {
  cout << "t = { " ;
  for (int i = 0 ; i < n - 1 ; i++) 
    cout << t[i] << ", ";
  cout << t[n - 1] << " }" << endl;
}


void echangerCase(int t[], int x, int y) {
  int temp = t[x];
  t[x] = t[y];
  t[y] = temp;
}


void saisirCroissant(int t[], int n) {
  for (int i = 0 ; i < n - 1 ; i++)
    for (int j = i + 1 ; j < n ; j++)
      if (t[i] > t[j])
	echangerCase(t,i,j);
}
