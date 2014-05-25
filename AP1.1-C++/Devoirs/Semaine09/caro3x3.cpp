#include <iostream>
#include <cstdlib>
#include <unistd.h>
#include <math.h>
#include <stdio.h>
#include <termios.h>
using namespace std;

/******************************************************************************************************************/

#define COLONNE 11
#define LIGNE 5
#define TAILLE 3


char grille[LIGNE][COLONNE];
int caro[TAILLE][TAILLE];


void affichageGrille() {
  for (int i = 0 ; i < LIGNE ; i++) {
    for (int j = 0 ; j < COLONNE ; j++) {
      if (i == 1 || i == 3) {
	if (j == 3 || j == 7) 
	  grille[i][j] = '+' ;
	else 
	  grille[i][j] = '-' ;
      }

      if (i == 0 || i == 2 || i == 4) {
	if (j == 3 || j == 7)
	  grille[i][j] = '|';
	else 
	  grille[i][j] = ' ';
      }
    }
  }      
}


void affichageEcran() {
  for (int i = 0 ; i < LIGNE ; i++) {
    for (int j = 0 ; j < COLONNE ; j++)
      cout << grille[i][j];
    cout << endl;
  }
}
   

void testPosition(int joueur, int & ligne1, int & colonne1, int & ligne2, int & colonne2) {
  while (ligne1 == ligne2 && colonne1 == colonne2) {
    cout << endl << "Erreur de position. Entrez-en une autre : " << endl;
    if (joueur == 1) {
      cout << "Entrez la ligne : "; cin >> ligne1;
      cout << "Entrez la colonne : "; cin >> colonne1;
    }
    else if (joueur == 2) {
      cout << "Entrez la ligne : "; cin >> ligne2;
      cout << "Entrez la colonne : "; cin >> colonne2;
    }
  }
}


void saisirPosition(string tour, int & joueur, int & ligne, int & colonne) {
  cout << tour << endl;
  cout << "Entrez la ligne : "; cin >> ligne;
  cout << "Entrez la colonne : "; cin >> colonne;
  
  if (tour == "JOUEUR 1")  
    joueur = 1;
  else 
    joueur = 2;
}


void testResultat(int joueur, bool resultat) {
  for (int i = 0 ; i < TAILLE ; i++) {

    //horizontal
    if (caro[i][0] == joueur && caro[i][1] == joueur && caro[i][2] == joueur) {
      cout << endl << "JOUEUR " << joueur << " a gagne" << endl << endl;
      exit(0);
    } 

    //vertical
    if (caro[0][i] == joueur && caro[1][i] == joueur && caro[2][i] == joueur) {
      cout << endl << "JOUEUR " << joueur << " a gagne" << endl << endl;
      exit(0);
    }
  }
  
  //diagonal
  if (caro[0][0] == joueur && caro[1][1] == joueur && caro[2][2] == joueur) {
    cout << endl << "JOUEUR " << joueur << " a gagne" << endl << endl;
    exit(0);
  } 
}
 
 
int main() {
  int ligne1, colonne1, ligne2, colonne2;
  bool resultat = true;
  int joueur;
  string tour;
  
  affichageGrille();
  affichageEcran();
  cout << endl;

  while (resultat) {

    saisirPosition("JOUEUR 1", joueur, ligne1, colonne1);
    testPosition(joueur, ligne1, colonne1, ligne2, colonne2);
    grille[2*ligne1][4*colonne1 + 1] = 'X';
    caro[ligne1][colonne1] = 1;
    affichageEcran();
    testResultat(joueur, resultat);

    cout << "----------------------------" << endl;

    saisirPosition("JOUEUR 2", joueur, ligne2, colonne2);
    testPosition(joueur, ligne1, colonne1, ligne2, colonne2);
    grille[2*ligne2][4*colonne2 + 1] = 'O';
    caro[ligne2][colonne2] = 2;
    affichageEcran();
    testResultat(joueur, resultat);
    
  }
}

/******************************************************************************************************************/
 
 
 
