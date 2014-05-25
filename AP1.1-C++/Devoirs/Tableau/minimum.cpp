#include <iostream>
#include <cstdlib>
#include <unistd.h>
#include <math.h>
#include <stdio.h>
#include <termios.h>
using namespace std;

/*****************************************************************************************************************/

//TABLEAU : TROUVER 2 NOMBRES MINIMAUX D'UN TABLEAU SAISI

/*
#define TAILLE 20

int Minimum (int Tab[], int nb, int & min1, int & min2) {
  if (Tab[0] > Tab[1]) { 
    min1 = Tab[0];
    min2 = Tab[1];
  }
  else {
    min1 = Tab[1];
    min2 = Tab[0];
  }
    
  for (int j = 2 ; j < nb ; j++) {
    if (Tab[j] < min1) {
      min2 = min1;
      min1 = Tab[j]; 
    }
    else if (Tab[j] < min2)
      min2 = Tab[j]; //en cas ou min1 est le plus minimal nombre dans le tableau, alors il faut verifier min2
  }

  cout << "min1 = " << min1 << endl;
  cout << "min2 = " << min2 << endl;
}

int main() {
  int nb, tab[nb], min1, min2;
  
  cout << "Entrez la taille du tableau (<= 20) : " ;
  cin >> nb;

  cout << "Entrez les nombres : " ;

  for (int i = 0 ; i < nb ; i++) 
    cin >> tab[i];
    
  for (int i = 0 ; i < nb ; i++) 
    cout << "tab[" << i << "] = " << tab[i] << endl;

  Minimum (tab, nb, min1, min2);
}
*/

/*****************************************************************************************************************/

//EXERCICE : TROUVER K NOMBRES MINIMAUX DANS 1 TABLEAU (METHODE 1)


#define TAILLE 5

int Minimum (int tab[], int min[], int k) {
  min[0] = -999999;
  for (int i = 1 ; i <= k ; i++) {
    min[i] = 999999;
    for (int j = 0 ; j < TAILLE ; j++) {
      if (min[i - 1] < tab[j] && min[i] > tab[j]) //min[i - 1] < tab[j] < min[i]
	min[i] = tab[j];
    }
    cout << "min[" << i <<"] = " << min[i] << endl;
  }
}


int main() {
  int tab[TAILLE];
  int min[TAILLE];
  
  cout << "Entrez les nombres : " << endl;

  for (int i = 0 ; i < TAILLE ; i++) 
    cin >> tab[i];
    
  for (int i = 0 ; i < TAILLE ; i++) 
    cout << "tab[" << i << "] = " << tab[i] << endl;

  int k;
  cout << "Entrez le nombre des nombres minimaux : " ;
  cin >> k;

  Minimum (tab, min, k);
}


/*****************************************************************************************************************/

//EXERCICE : TROUVER K NOMBRES MINIMAUX DANS 1 TABLEAU (METHODE 2)

/*
#define TAILLE 5

void affichageTab(int tab[]);
void echanger_case(int tab[], int x, int y);
void minimum(int tab[]);

int main() {
  int tab[TAILLE];
    
  for (int i = 0 ; i < TAILLE ; i++) {
    cout << "Entrez les nombres : " ;
    cin >> tab[i];
  }
      
  affichageTab(tab);
  
  minimum(tab);

  int k;
  cout << "Entrez le nombre des minimaux : ";
  cin >> k;
  
  for (int i = 0 ; i < k ; i++)
    cout << "min[" << i << "] = " << tab[i] << endl;
}


void affichageTab(int tab[]) {
  cout << "tab : { " ;
  for (int i = 0 ; i < TAILLE - 1; i++) 
    cout << tab[i] << ", " ;
  cout << tab[TAILLE - 1] << " }" << endl;
}

void echanger_case (int tab[], int x, int y) {
  int temp = tab[x];
  tab[x] = tab[y];
  tab[y] = temp;
}

void minimum(int tab[]) {
  for (int i = 0 ; i < TAILLE - 1; i++)
    for (int j = i + 1 ; j < TAILLE ; j++)
      if (tab[i] > tab[j])
	echanger_case(tab,i,j);
}
*/

/*****************************************************************************************************************/

/*
#define TAILLE 10

void affichageTab(int tab[]);
int minimum(int tab[], int min[], int k);


int main() {
  int tab[TAILLE];
  int min[TAILLE];
  
  for (int i = 0; i < TAILLE ; i++) {
    cout << "Entrez les nombres : " ;
    cin >> tab[i];
  }

  int k;
  cout << "Entrez le nombre des minimaux : ";
  cin >> k;

  affichageTab(tab);

  minimum(tab, min, k);
  
  for (int i = 0 ; i < k ; i++)
    cout << "min[" << i << "] = " << min[i] << endl;  
}

void affichageTab(int tab[]) {
  cout << "tab : { " ;
  for (int i = 0 ; i < TAILLE - 1 ; i++)
    cout << tab[i] << ", " ;
  cout << tab[TAILLE - 1] << " }" << endl ;
}

int minimum(int tab[], int min[], int k) {
  int a;

  for (int i = 0 ; i < k ; i++) {
    min[i] = 99999;
    for (int j = 0 ; j < TAILLE ; j++) {
      if (min[i] > tab[j]) {
	min[i] = tab[j];
	a = j;
      }      
    }
    tab[a] = 99999;
  }
}
*/
