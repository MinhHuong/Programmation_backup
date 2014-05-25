#include <iostream>
#include <cstdlib>
#include <unistd.h>
#include <math.h>
#include <stdio.h>
#include <termios.h>
#include <string>
using namespace std;

/******************************************************************************************************************/

const int MAX = 100;

/******************************************************************************************************************/

void afficher(string & chaine, int & taille) {
  int n = 0;
  chaine[taille] = '\0';

  while (chaine[n] != '\0') {
    cout << chaine[n];
    n++;
  }

  cout << endl;
}

/*----------------------------------------------------------------------------*/  

int Longueur(string chaine) {
  int i = 0;
  
  while (chaine[i] != '\0') 
    i = i + 1;
  
  return i;
}

/*----------------------------------------------------------------------------*/  

void Copier(string chaine1, string chaine2, int taille) {
  for (int i = 0 ; i <= taille ; i++)
    chaine2[i] = chaine1[i];

  cout << "Chaine copiee : ";
  afficher(chaine2, taille);
}  

/*----------------------------------------------------------------------------*/  

void Concatener(string chaine1, string chaine2) {
  int taille1, taille2;
  taille1 = Longueur(chaine1);
  taille2 = Longueur(chaine2);

  int tailleSum;
  tailleSum = taille1 + taille2;

  /*
  chaine1[tailleSum] = '\0';
  chaine1[taille1] = 'a'; //tao dieu kien chaine1[taille1] != '\0' de chay duoc vong while

  int i = taille1;
  int j = 0;

  while (chaine1[i] != '\0') { //khong vao duoc vong while ?
    chaine1[i] = chaine2[j];
    i++;
    j++;
  }
  */

  int j = 0;
  for (int i = taille1 ; i < tailleSum ; i++) {
    chaine1[i] = chaine2[j];
    j++;
  }
    
  cout << "Chaine concatenee : ";
  afficher(chaine1, tailleSum);
}

/*----------------------------------------------------------------------------*/  

int ComparerChar(char a, char b) {
  if (a < b)
    return -1;
  else if (a == b)
    return 0;
  else 
    return 1;
}
 
/*----------------------------------------------------------------------------*/  

int Comparer(string chaine1, string chaine2) {
  int taille1, taille2;
  taille1 = Longueur(chaine1);
  taille2 = Longueur(chaine2);

  int i = 0;
  while (i < taille1 && i < taille2 && ComparerChar(chaine1[i], chaine2[i]) == 0)
    i++;
  
  int result;

  if (i == taille1 || i == taille2) {
    if (i < taille1)
      result = 1;
    else {
      if (i < taille2)
	result = -1;
      else 
	result = 0;
    }
  }
  else
    result = ComparerChar(chaine1[i], chaine2[i]);

  return result;  
}

/*----------------------------------------------------------------------------*/  

void ResultatComparer(string chaine1, string chaine2) {
  if (Comparer(chaine1, chaine2) == -1) 
    cout << chaine1 << " est strictement plus petite que " << chaine2 << endl;

  if (Comparer(chaine1, chaine2) == 0)
    cout << "Les 2 chaines " << chaine1 << " et " << chaine2 << " sont egales" << endl;

  if (Comparer(chaine1, chaine2) == 1)
    cout << chaine1 << " est strictement plus grande que " << chaine2 << endl;
}

/*----------------------------------------------------------------------------*/  

void MultiDecalageGauche(string chaine, int pos, int longueur) {
  int taille;
  taille = Longueur(chaine);

  /*
  chaine[taille - longueur] = '\0';

  int j = pos; 
  int i = 0;

  while (i < longueur) {
    while (chaine[j] != '\0') {
      chaine[j] = chaine[j + 1];
      j++;
    }
    taille--;
    i++;
    }
  */

  for (int i = 0 ; i < longueur ; i++) {
    for (int j = pos ; j < taille - 1 ; j++)
      chaine[j] = chaine[j + 1];
    taille--;
    }
  
  cout << "Chaine coupee : ";
  afficher(chaine, taille);
}

/*----------------------------------------------------------------------------*/  

void MultiDecalageDroite(string chaine, int pos, int longueur) {
  int taille;
  taille = Longueur(chaine);

  for (int i = 0 ; i < longueur ; i++) {
    for (int j = taille ; j > pos; j--) 
      chaine[j - 1] = chaine[j];
    taille++;
  }
}

/*----------------------------------------------------------------------------*/  

void Inserer(string chaine, int pos, string ajouter) {
  int taille;
  taille = Longueur(chaine);

  int longueur;
  longueur = Longueur(ajouter);

  int taille2;
  taille2 = taille + longueur;

  int j = 0;
  for (int i = pos ; i < taille2 ; i++) {
    MultiDecalageDroite(chaine, pos, longueur);
    chaine[i] = ajouter[j];
    j++;
  }

  cout << "Chaine ajoutee : ";
  afficher(chaine, taille2);
}

/******************************************************************************************************************/

int main() {
  string src;
  cout << "Entrez la chaine : ";
  cin >> src;


  int Lsrc;
  Lsrc = Longueur(src);
  cout << "La longueur de la chaine saisie : " << Lsrc << endl;


  string dest;
  Copier(src, dest, Lsrc);


  string src1, src2;
  cout << "Entrez la chaine 1 : "; cin >> src1;
  cout << "Entrez la chaine 2 : "; cin >> src2;
  Concatener(src1, src2);  


  string mot1, mot2;
  cout << "Entrez le premier mot : "; cin >> mot1;
  cout << "Entrez le second mot  : "; cin >> mot2;
  ResultatComparer(mot1, mot2);
  
 
  string mot;
  cout << "Entrez 1 nouveau mot : "; cin >> mot;  
  int indice, longueur;
  cout << "Entrez l'indice : "; cin >> indice;
  cout << "Entrez la longueur a effacer : "; cin >> longueur;
  MultiDecalageGauche(mot, indice, longueur);


  string org;
  cout << "Entrez la chaine originale : "; cin >> org;
  string ajouter;
  cout << "Entrez la chaine a ajouter : "; cin >> ajouter;
  cout << "Entrez l'indice : "; cin >> indice;
  Inserer(org, indice, ajouter);
}


  
