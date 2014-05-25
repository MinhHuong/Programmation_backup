#include <iostream>
#include <cstdlib>
#include <math.h>
using namespace std;

/******************************************* DECLARATION DES VARIABLES *********************************************/

const int MAX = 100;
const int taille_cpt = 21;
const int EXCEPT = 9999;

int tab[MAX];
int compteur[taille_cpt];
int replace[MAX];
int valeur[MAX];

/*************************************************** PROTOTYPES ****************************************************/

void saisirTab(int tab[], int taille);
void afficherTab(int tab[], int taille);

int indiceMax(int tab[], int taille);
void indiceMax2(int tab[], int taille, int & imax);

void replaceTab(int tab[], int taille, int replace[]);
void compteOccurrences(int tab[], int taille, int compteur[], int replace[]);
void Compte2(int tab[], int taille, int compteur[], int valeur[]);

void echangerCase(int tab[], int i, int j);
void trierTab(int tab[], int taille);
int Mediane(int tab[], int taille);

/****************************************************** MAIN *******************************************************/

int main() {
  int taille;
  cout << "Entrez la taille du tab : "; cin >> taille;
  saisirTab(tab, taille);
  afficherTab(tab, taille);


  cout << "En utilisant la fonction retournant une valeur : " << endl;
  cout << "L'indice du max est : " << indiceMax(tab, taille) << endl;
  cout << endl << "En utilisant la fonction void : " << endl;
  int imax = 0;
  indiceMax2(tab, taille, imax);


  replaceTab(tab, taille, replace);
  cout << "\nLe nombre de fois que les elements pareils apparaissent : " << endl;
  compteOccurrences(tab, taille, compteur, replace);
  //Compte2(tab, taille, compteur, valeur);


  int mediane;
  cout << "Le tableau apres le tri : " << endl;
  trierTab(tab, taille);
  afficherTab(tab, taille);
  cout << "La mediane du tab = " << Mediane(tab, taille) << endl;
}
  
/************************************************** FONCTIONS ******************************************************/

void saisirTab(int tab[], int taille) {
  for (int i = 0 ; i < taille ; i++) {
    cout << "Entrez le nombre : ";
    cin >> tab[i];
    if (tab[i] < 0 || tab[i] > 20) {
      cout << "Erreur saisie ! Entrez 1 autre note !" << endl;
      i -= 1;      
    }
  }
}


void afficherTab(int tab[], int taille) {
  cout << endl << "tab : ";
  for (int i = 0 ; i < taille ; i++) 
    cout << tab[i] << " ";
  cout << endl;
}

/*-----------------------------------------------------------------------------------------------------------------*/

int indiceMax(int tab[], int taille) {
  int max = tab[0];
  int indice = 0;
  
  for (int i = 1 ; i < taille ; i++) {
    if (max < tab[i]) {
      max = tab[i];
      indice = i;
    }
  }

  cout << "Max = " << max << endl;
  
  return indice;
}


void indiceMax2(int tab[], int taille, int & imax) {
  int max = tab[0];
  
  for (int i = 0 ; i < taille ; i++) {
    if (max < tab[i]) {
      max = tab[i];
      imax = i;
    }
  }

  cout << "Max = " << max << endl;
  cout << "L'indice de max = " << imax << endl;
}

/*-----------------------------------------------------------------------------------------------------------------*/

void replaceTab(int tab[], int taille, int replace[]) {
  for (int i = 0 ; i < taille ; i++)
    replace[i] = tab[i];

  for (int i = 0 ; i < taille - 1; i++)
    for (int j = i + 1 ; j < taille ; j++)
      if (replace[i] == replace[j])
	replace[j] = EXCEPT;
}
	

void compteOccurrences(int tab[], int taille, int compteur[], int replace[]) {
  for (int i = 0 ; i < taille_cpt ; i++)
    compteur[i] = 0;
  
  for (int i = 0 ; i < taille ; i++)
    compteur[tab[i]] += 1;

  for (int i = 0 ; i < taille ; i++) {
    if (replace[i] != EXCEPT)
      cout << "compteur[" << replace[i] << "] = " << compteur[replace[i]] << endl;
  }
}


void Compte2(int tab[], int taille, int compteur[], int valeur[]) {
  bool pareil = false;
  int j = 0;

  for (int i = 0 ; i < taille ; i++) {
    for (int k = 0 ; k <= j ; k++) 
      if (compteur[k] == tab[i]) {
	pareil = true;
	valeur[k]++;
      }
      
    if (pareil == false) {
      compteur[j] = tab[i];
      valeur[j] = 1;
      j++;
    }
    else 
      pareil = false;
  }

  for (int i = 0 ; i < j ; i++)
    cout << "compteur[" << compteur[i] << "] = " << valeur[i] << endl;
}

/*-----------------------------------------------------------------------------------------------------------------*/

void echangerCase(int tab[], int i, int j) {
  int temp = tab[i];
  tab[i] = tab[j];
  tab[j] = temp;
}


void trierTab(int tab[], int taille) {
  for (int i = 0 ; i < taille - 1 ; i++)
    for (int j = i + 1 ; j < taille ; j++)
      if (tab[i] > tab[j])
	echangerCase(tab, i, j);
}


int Mediane(int tab[], int taille) {
  int mediane;
  int milieu;
  milieu = (taille - 1)/2;
  
  if (taille % 2 == 0)
    mediane = tab[milieu + 1];
  else
    mediane = tab[milieu];

  return mediane;
}
