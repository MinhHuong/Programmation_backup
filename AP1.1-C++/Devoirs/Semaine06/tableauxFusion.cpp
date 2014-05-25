#include <iostream>
#include <cstdlib>
#include <unistd.h>
#include <math.h>
#include <stdio.h>
#include <termios.h>
using namespace std;

#define SAUF -99999

/********************************************* --- PROTOTYPES --- *************************************************/

void saisirTab(int tab[], int taille);
void afficherTab(int tab[], int taille);
int indiceMax(int tab[], int taille);
int selectTab(int tab[], int taille, int select[],int & fois);
void Compte1(int tab[], int taille, int compteur[], int select[]);  
void Compte2(int tab[], int taille, int compteur[]);
void echanger_case(int tab, int x, int y);
void saisirCroissant(int iTab[], int taille);
void Mediane(int select[], int taille, int fois);

/************************************************ --- MAIN --- ****************************************************/

int main() {
  int taille;
  cout << endl << "Entrez la taille du tableau : ";
  cin >> taille;

  while (taille <= 0 || taille > 20) {
    cout << "Entrez 1 autre valeur de taille : ";
    cin >> taille;
  }
    
  int tab[taille];
  int select[taille];

  saisirTab(tab,taille);
  afficherTab(tab,taille);

  cout << endl;
  indiceMax(tab,taille);

  int compteur[20];
  int fois = 0;

  cout << endl;
  selectTab(tab,taille,select,fois);

  cout << endl;
  char repondre;
  cout << "On a 2 methodes pour compter les nombres : " << endl;
  cout << "1) Utiliser le tableau select[] : les nombres pareils ne disparaissent pas vraiment" << endl;
  cout << "2) Pas besoin du tableau select[] : 1 autre table qui ne se compose que des nombres differents" << endl;
  cout << "Quelle methode voulez-vous pour compter des nombres ? : ";
  cin >> repondre;
 
  cout << endl;
  if (repondre == '1') 
    Compte1(tab,taille,compteur,select);
  else if (repondre == '2') 
    Compte2(tab,taille,compteur);

  cout << endl;
  Mediane(select,taille,fois);
 
}

/************************************************ --- FONCTIONS --- ***********************************************/
    
void saisirTab(int tab[], int taille) {
  for (int i = 0 ; i < taille ; i++) {
    cout << "tab[" << i << "] = ";
    cin >> tab[i];
  }
}


void afficherTab(int tab[], int taille) {
  cout << "tab = { ";
  for (int i = 0 ; i < taille - 1 ; i++)
    cout << tab[i] << ", ";
  cout << tab[taille - 1] << " }" << endl;
}


int indiceMax(int tab[], int taille) {
  int max = tab[0];
  int a = 0;

  for (int i = 1 ; i < taille ; i++) 
    if (tab[i] > max) {
      max = tab[i];
      a = i;
    }

  cout << "Max = " << max << " et l'indice du max dans le tableau est tab[" << a << "]" << endl;
}


int selectTab(int tab[], int taille, int select[], int & fois) {
  for (int i = 0 ; i < taille ; i++) 
    select[i] = tab[i];

  for (int i = 0 ; i < taille - 1; i++)
    for (int j = i + 1 ; j < taille ; j++)
      if (select[j] == select[i]) {
	select[j] = SAUF;
	if (select[i] != SAUF)
	  fois++;
      }
      
  cout << "Les nombres differents dans le tableau : " << endl;
  for (int i = 0 ; i < taille ; i++)
    if (select[i] != SAUF)
      cout << "select = " << select[i] << endl;
}

 
void Compte1(int tab[], int taille, int compteur[], int select[]) {
  for (int i = 0 ; i < taille ; i++)
    compteur[tab[i]] = 0;

  for (int i = 0 ; i < taille ; i++) 
    compteur[tab[i]] += 1;

  for (int i = 0 ; i < taille ; i++)
    if (select[i] != SAUF)
      cout << "compteur[" << select[i] << "] = " << compteur[tab[i]] << endl;
} 


void Compte2(int tab[], int taille, int compteur[]) {
  int valeur[taille];
  int j = 0;
  bool a = true;
  
  for (int i = 0 ; i < taille ; i++) {
    for (int k = 0 ; k <= j ; k++) {
      if (tab[i] == compteur[k]) {
	a = false;
	valeur[k]++;
      }
    }
    if (a) {
      compteur[j] = tab[i];
      valeur[j] = 1;
      j++;
    }
    else
      a = true;
  }

  for (int i = 0 ; i < j ; i++)
    cout << "compteur[" << compteur[i] << "] = " << valeur[i] << endl; 
}


void echangerCase(int tab[], int x, int y) {
  if (tab[x] > tab[y]) {
    int temp = tab[x];
    tab[x] = tab[y];
    tab[y] = temp;
  }
}


void saisirCroissant(int iTab[], int taille) {
  for (int k = 0 ; k < taille ; k++)
      for (int i = 0 ; i < taille - 1; i++)
	for (int j = i + 1 ; j < taille ; j++)
	  if (iTab[i] > iTab[j])
	    echangerCase(iTab,i,j);
}


void Mediane(int select[], int taille, int fois) {
  saisirCroissant(select,taille);

  cout << "En ordre croissant : " << endl;
  for (int k = 0 ; k < taille ; k++)
    if (select[k] != SAUF)
      cout << "select = " << select[k] << endl;

  cout << endl;
  if ((taille - fois) % 2 == 1)
    cout << "La mediane du tableau est : " << select[taille - (taille - fois + 1)/2] << endl;
  else
    cout << "La mediane du tableau se situe entre " << select[taille - (taille - fois)/2 - 1] 
	 << " et " << select[taille - (taille - fois)/2] << endl;   
}
