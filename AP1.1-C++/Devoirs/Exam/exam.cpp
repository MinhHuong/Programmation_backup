#include <iostream>
#include <cstdlib>
#include <math.h>
using namespace std;

const int TAILLE = 15;
const int N_BOMBE = 10;


typedef struct {
  int x;
  int y;
} element;


int grille[TAILLE][TAILLE];
element bomb[N_BOMBE];


void initGrille () {
  for (int i = 0 ; i < TAILLE ; i++)
    for (int j = 0 ; j < TAILLE ; j++)
      grille[i][j] = 0;
}


void afficherGrille()
{
  cout << endl << "\t-";
  for (int j = 0 ; j < TAILLE ; j++)
    cout << "---+" ;
  cout << endl;
      
  for (int i = 0 ; i < TAILLE ; i++)
    {
      cout << i + 1 << "\t|";
      
      for (int j = 0 ; j < TAILLE ; j++) {
	switch (grille[i][j]) {
	case 0 : 
	  cout << "   "; 
	  break; 
	case 1 : 
	  cout << "LOL"; 
	  break;
	case 2 : 
	  cout << " 1 "; 
	  break;
	case 3 :
	  cout << " 2 ";
	  break;
	}
	cout << "|";
      }
      
      cout << endl << "\t-";
      for (int j = 0 ; j < TAILLE ; j++)
	cout << "---+" ;
      cout << endl;
    }
}


void testBomb() {
  srand(time(NULL));
  
  for (int i = 0 ; i < N_BOMBE ; i++) {  
    bomb[i].x = rand() % TAILLE;
    bomb[i].y = rand() % TAILLE;
    grille[bomb[i].x][bomb[i].y] = 1;

    if (bomb[i].x == 0) {
      if (bomb[i].y == 0) {
	grille[bomb[i].x][bomb[i].y + 1] = 2;
	grille[bomb[i].x + 1][bomb[i].y] = 2;
	grille[bomb[i].x + 1][bomb[i].y + 1] = 2;
      }
      else if (bomb[i].y == TAILLE - 1) {
	grille[bomb[i].x][bomb[i].y - 1] = 2;
	grille[bomb[i].x + 1][bomb[i].y] = 2;
	grille[bomb[i].x + 1][bomb[i].y - 1] = 2;
      }
      else {
	grille[bomb[i].x][bomb[i].y + 1] = 2;
	grille[bomb[i].x][bomb[i].y - 1] = 2;
	grille[bomb[i].x + 1][bomb[i].y - 1] = 2;
	grille[bomb[i].x + 1][bomb[i].y + 1] = 2;
	grille[bomb[i].x + 1][bomb[i].y] = 2;
      }
    }

    else if (bomb[i].x == TAILLE - 1) {
      if (bomb[i].y == 0) {
	grille[bomb[i].x - 1][bomb[i].y] = 2;
	grille[bomb[i].x - 1][bomb[i].y + 1] = 2;
	grille[bomb[i].x][bomb[i].y + 1] = 2;
      }
      else if (bomb[i].y == TAILLE - 1) {
	grille[bomb[i].x - 1][bomb[i].y - 1] = 2;
	grille[bomb[i].x - 1][bomb[i].y] = 2;
	grille[bomb[i].x][bomb[i].y - 1] = 2;
      }
      else {
	grille[bomb[i].x][bomb[i].y + 1] = 2;
	grille[bomb[i].x][bomb[i].y - 1] = 2;
	grille[bomb[i].x - 1][bomb[i].y - 1] = 2;
	grille[bomb[i].x - 1][bomb[i].y + 1] = 2;
	grille[bomb[i].x - 1][bomb[i].y] = 2;
      }
    }

    else if (bomb[i].y == 0) { 
      if (bomb[i].x == 0) {
	grille[bomb[i].x][bomb[i].y + 1] = 2;
	grille[bomb[i].x + 1][bomb[i].y] = 2;
	grille[bomb[i].x + 1][bomb[i].y + 1] = 2;
      }
      else if (bomb[i].x == TAILLE - 1) {
	grille[bomb[i].x - 1][bomb[i].y] = 2;
	grille[bomb[i].x - 1][bomb[i].y + 1] = 2;
	grille[bomb[i].x][bomb[i].y + 1] = 2;
      }
      else {
	grille[bomb[i].x - 1][bomb[i].y] = 2;
	grille[bomb[i].x + 1][bomb[i].y] = 2;
	grille[bomb[i].x + 1][bomb[i].y + 1] = 2;
	grille[bomb[i].x - 1][bomb[i].y + 1] = 2;
	grille[bomb[i].x][bomb[i].y + 1] = 2;
      }
    }

    else if (bomb[i].y == TAILLE - 1) {
      grille[bomb[i].x - 1][bomb[i].y - 1] = 2;
      grille[bomb[i].x - 1][bomb[i].y] = 2;
      grille[bomb[i].x][bomb[i].y - 1] = 2;
      grille[bomb[i].x + 1][bomb[i].y - 1] = 2;
      grille[bomb[i].x + 1][bomb[i].y] = 2;  
    }

    else {
      grille[bomb[i].x][bomb[i].y + 1] = 2;
      grille[bomb[i].x][bomb[i].y - 1] = 2;
      grille[bomb[i].x + 1][bomb[i].y + 1] = 2;
      grille[bomb[i].x + 1][bomb[i].y] = 2;
      grille[bomb[i].x + 1][bomb[i].y - 1] = 2;
      grille[bomb[i].x - 1][bomb[i].y - 1] = 2;
      grille[bomb[i].x - 1][bomb[i].y] = 2;
      grille[bomb[i].x - 1][bomb[i].y + 1] = 2;
    } 
  }
}
 

int main() {
  initGrille();
  afficherGrille();
  
  testBomb();
  bool play = true;

  while (play) {
    int ligne, colonne;
    cout << "Entrez la ligne : "; cin >> ligne;
    cout << "Entrez la colonne : "; cin >> colonne;
    afficherGrille();  
  }
}
