// Tableau.cc

#include<iostream>
#include "Tableau.h"

using namespace std;


/**********************************************
 FONCTIONS DE SAISIES ET AFFICHAGES
 **********************************************/

// Fonction "locale" utilis�e pour les saisies
// Force la saisie d'un entier entre 1 et n
int
nombreValide(int n)
{
  int i;

  do {
    cin >> i;
  }while (i < 1 || i > n);

  return i;
}

// Permet de saisir un tableau quelconque (taille et �l�ments)
void
saisirTableau(int tab[], int & taille, int max)
{
  int i;

  cout << "Entrez la taille (entre 1 et " << max << ") :" << endl;
  taille = nombreValide(max);

  cout << "Entrez les elements :" << endl;
  for(i = 0 ; i < taille ; i++)
    cin >> tab[i];
}

// Permet de saisir un tableau (taille et �l�ments) en le triant
void
saisirTableauTrie(int tab[], int & taille, int max)
{
  int i, val;

  cout << "Entrez la taille (entre 1 et " << max << ") :" << endl;
  taille = nombreValide(max);

  cout << "Entrez les elements :" << endl;
  for( i = 0 ; i < taille; )
  {
    cin >> val;
    ajouterTrie(tab, i, val); //(tab, i, val)
  }
}

// Permet d'afficher les �l�ments d'un tableau
void
afficherTableau(int tab[], int taille)
{
  int i;
  for( i = 0 ; i < taille ; i++)
    cout << tab[i] << " ";
  cout << endl;
}


/**********************************************
 FONCTIONS DE RECHERCHE (POSITION ELEM)
 **********************************************/

// NON TRIE
// Recherche s�quentielle
// Retourne la position de elem dans tab, -1 si elem est absent
int
cherchePosSeq(int tab[], int taille, int elem)
{
  int pos = 0;
  bool trouve = false;
  
  while (!trouve && pos < taille)
    if (elem == tab[pos])
      trouve = true;
    else
      pos++;
  
  if (!trouve)
    pos = -1;
 
  return pos;
}

// TRIE
// Recherche dichotomique
// Retourne la position de elem dans tab, -1 si elem est absent
int
cherchePosDicho(int tab[], int taille, int elem)
{
  int gauche, droite, milieu;
  bool trouve;
  
  gauche = 0;
  droite = taille-1;
  trouve = false;

  /*
  while (!trouve && gauche <= droite)
    {
      milieu = (gauche + droite)/2;
      if (elem == tab[milieu])
	trouve = true;
      else
       	if (elem < tab[milieu])
	  droite = milieu;
	else
	  if (milieu == taille - 2) {
	    if (elem == tab[milieu])
	      trouve = true;
	    else
	      milieu = taille - 1;
	  }
	  gauche = milieu;
    }
  */ 

  while (!trouve && gauche <= droite) {
    milieu = (gauche + droite)/2;
    if (elem == tab[milieu])
      trouve = true;
    else {
      if (elem < tab[milieu])
	droite = milieu - 1;
      else 
	gauche = milieu + 1;
    }
  }
   
  if (!trouve)
    milieu = -1;
  
  return milieu;
}


/**********************************************
 FONCTIONS DE SUPPRESSION
 **********************************************/

void decalageGauche(int tab[], int & taille, int indice) {
  for (int i = indice ; i < taille - 1 ; i++)
    tab[i] = tab[i + 1];
  
  taille--;
}


void supprimerNonTrie(int tab[], int & taille, int element) {
  for (int i = 0 ; i < taille ; i++)
    if (tab[i] == element)
      decalageGauche(tab,taille,i);
}

/**********************************************
 FONCTIONS D'AJOUT
 **********************************************/

// NON TRIE
// Ajout d'un �l�ment dans un tableau non tri�
// suppose que le tableau n'est pas plein
void
ajouterNonTrie(int tab[], int & taille, int elem)
{
  tab[taille] = elem;
  taille++;
}


// Fonction "locale" utilis�e par ajouterTrie
// Retourne la position � laquelle Elem peut �tre ajout� dans tab
// (bas�e sur une recherche s�quentielle)
int
cherchePosAjout(int tab[], int taille, int elem)
{ 
  /*int pos = 0;
  bool trouve = false;

  while (!trouve && pos < taille)
    if (elem <= tab[pos])
      trouve = true;
    else
      pos++;
  
      return pos;*/

  int pos;

  for (pos = 0; pos < taille ; pos++) {
    if (elem <= tab[pos])
      break;
  }

  return pos;
  

  /*
  bool trouve = false;

  int gauche, droite, milieu;
  gauche = 0;
  droite = taille;

  while (!trouve && gauche <= droite) {
    milieu = (gauche + droite)/2;
    if (droite - gauche == 1 || droite - gauche == -1) {
      milieu = droite;
      trouve = true;
    }
    else if (milieu <= tab[0])
      milieu = 0;
    else
      if (elem >= tab[milieu])
	gauche = milieu;
      else 
	droite = milieu;
  }
  
  return milieu;
  */

}


// Fonction "locale" utilis�e par ajouterTrie
// D�cale vers la droite tous les �l�ments de tab � partir de la position indice
void
decalageDroite(int tab[], int & taille, int indice)
{
  int i;

  for (i = taille; i > indice ; i--)
    tab[i] = tab[i - 1];

  taille++;
}


// TRIE
// Ajout d'un �l�ment dans un tableau tri�
// suppose que le tableau n'est pas plein
void
ajouterTrie(int tab[], int & taille, int elem)
{
  int pos;
  pos = cherchePosAjout(tab, taille, elem);
  decalageDroite(tab, taille, pos);
  tab[pos] = elem;
}

