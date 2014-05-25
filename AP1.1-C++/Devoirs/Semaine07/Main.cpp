#include <iostream>
#include <cstdlib>
#include "Tableau.h"

using namespace std;


void
afficherMenu()
{
  cout << endl
       << " 0. Sortir" << endl
       << " 1. Saisie d'un tableau quelconque" << endl
       << " 2. Saisie d'un tableau en le triant" << endl
       << "11. Recherche sequentielle d'un element" << endl
       << "12. Supression d'un element" << endl
       << "13. Ajout d'un element" << endl
       << "21. Recherche sequentielle d'un element dans un tableau trie" << endl
       << "22. Recherche dichotomique d'un element" << endl
       << "23. Suppression d'un element dans un tableau trie" << endl
       << "24. Ajout d'un element dans un tableau trie" << endl
       << endl
       << "Votre choix : ";
}

void
traiterRechercheSeq(int tab[], int taille)
{
  int element, pos;

  cout << endl << "Element a rechercher dans le tableau : ";
  cin >> element;
  pos = cherchePosSeq(tab, taille, element);
  if (pos != -1)
    cout << "L'element " << element << " est a la position " << pos << endl;
  else
    cout << "L'element " << element << " n'est pas present" << endl;
}

void
traiterAjoutNonTrie(int tab[], int & taille, int max)
{
  int element;

  if (taille == max)
    cout << "Impossible : tableau plein" << endl;
  else
    {
      cout << endl << "Element a ajouter dans le tableau : ";
      cin >> element;
      ajouterNonTrie(tab, taille, element);
    }
}

void
traiterSupNonTrie(int tab[], int & taille) {
  int element;

  if (taille == 0)
    cout << "Rien d'autre element a supprimer stop bitch. " << endl;

  cout << endl << "Element a supprimer dans le tableau : ";
  cin >> element;
  supprimerNonTrie(tab, taille, element);
}

void
traiterRechercheDicho(int tab[], int taille)
{
  int element, pos;

  cout << endl << "Element a rechercher dans le tableau : ";
  cin >> element;
  pos = cherchePosDicho(tab, taille, element);
  if (pos != -1)
    cout << "L'element " << element << " est a la position " << pos << endl;
  else
    cout << "L'element " << element << " n'est pas present" << endl;
}

void
traiterAjoutTrie(int tab[], int & taille, int max)
{
  int element;

  if (taille == max)
    cout << "Impossible : tableau plein" << endl;
  else
    {
      cout << endl << "Element a ajouter dans le tableau trie : ";
      cin >> element;
      ajouterTrie(tab, taille, element);
    }
}

int
main()
{
  const int TAILLEMAX = 100;
  int tabl[TAILLEMAX];
  int taille, choix;

  // Le tableau est vide au début
  taille = 0; 

  do 
    {
      cout << endl << "Contenu du tableau :" << endl;
      afficherTableau(tabl, taille);

      afficherMenu();
      cin >> choix;
      switch (choix)
	{
	case  0 : // sortir
	  break;
	case  1 : // saisie tableau quelconque
	  saisirTableau(tabl, taille, TAILLEMAX);
	  break;
	case  2 : // saisie tableau en le triant
	  saisirTableauTrie(tabl, taille, TAILLEMAX);
	  break;
	case 11 : // recherche seq
	  traiterRechercheSeq(tabl, taille);
	  break;
	case 12 : // suppression
	  traiterSupNonTrie(tabl, taille);
	  break;
	case 13 : // ajout
	  traiterAjoutNonTrie(tabl, taille, TAILLEMAX);
	  break;
	case 21 : // recherche seq trié
	  traiterRechercheSeq(tabl, taille);
	  break;
	case 22 : // recherche dicho
	  traiterRechercheDicho(tabl, taille);
	  break;
	case 23 : // suppression trié
	  traiterSupNonTrie(tabl, taille);
	  break;
	case 24 : // ajout trié
	  traiterAjoutTrie(tabl, taille, TAILLEMAX);
	  break;
	default :
	  cout << "Erreur de saisie" << endl;
	  break;
	}
      
    } while (choix != 0);
 
  cout << "Fin de programme" << endl; 

  return EXIT_SUCCESS;
}
