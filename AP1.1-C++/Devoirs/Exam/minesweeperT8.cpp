#include <time.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

// Definition de la taille de la grille
const int MAX = 100;

// Definition du type TGrille
typedef int TGrille[MAX][MAX];
TGrille grille, grilleOther;

int ligne, colonne, nbMines;



/****************************************/
/* Action d'initialisation de la grille */
/* On affecte la valeur 0 a chaque case */
/****************************************/

void saisirDonnees() {
  cout << "Entrez le nombre de lignes : "; cin >> ligne;
  cout << "Entrez le nombre de colonnes : "; cin >> colonne;
  cout << "Entrez le nombre de mines : "; cin >> nbMines;
}


void initGrille(TGrille grille)
{
  for (int i = 0 ; i < ligne ; i++)
    for (int j = 0 ; j < colonne ; j++)
      grille[i][j] = 0;
}

/****************************************/
/* Action d'initialisation des mines    */
/* On affecte la valeur -1 a chaque case */
/****************************************/

void creerMines(TGrille grille)
{
  srand(time(NULL));
  int x,y;
  //int r = rand()*10/RAND_MAX;
  //cout << r;
  for (int i = 0 ; i < nbMines ; i++) { 
    x = rand() % ligne;
    y = rand() % colonne;
    grille[x][y] = -1;
  }      
}


void updateTableau(TGrille grille)
{
  srand(time(NULL));
  int x,y;

  for (int i = 0 ; i < ligne ; i++)
    for (int j = 0 ; j < colonne ; j++){
      if (grille[i][j] == -1) 
	continue;

      if ((i > 0) && (grille[i - 1][j] == -1)) 
	grille[i][j]++;

      if ((j > 0) && (grille[i][j - 1] == -1)) 
	grille[i][j]++;

      if ((i < ligne - 1) && (grille[i + 1][j] == -1)) 
	grille[i][j]++;

      if ((j < colonne - 1) && (grille[i][j + 1] == -1)) 
	grille[i][j]++;

      if ((i > 0) && (j > 0) && (grille[i - 1][j - 1] == -1)) 
	grille[i][j]++;

      if ((i < ligne - 1) && (j > 0) && (grille[i + 1][j - 1] == -1)) 
	grille[i][j]++;

      if ((i < ligne - 1) && (j < colonne - 1) && (grille[i + 1][j + 1] == -1)) 
	grille[i][j]++;

      if ((i > 0) && (j < colonne - 1) && (grille[i - 1][j + 1] == -1)) 
	grille[i][j]++;
    }      
}

/****************************************/
/* Action d'affichage de la grille */
/* On affecte la valeur 0 a chaque case */
/****************************************/

void afficherGrille(TGrille grille)
{
  cout << endl << "\t-";
  for (int j = 0 ; j < colonne ; j++)
    cout << "---+" ;
  cout << endl;
      
  for (int i = 0 ; i < ligne ; i++)
    {
      cout << i+1 << "\t|";
      for (int j = 0 ; j < colonne ; j++)
	{
	  switch (grille[i][j])
	    {
	    case 10 : cout << " X "; break;
	    case -1 : cout << "bom"; break;
	      //case 11 : cout << "bom"; break;
	    case 0 : cout << "   "; break;	    
	    default : cout << " " << grille[i][j] << " "; break;
	    } 
	  cout << "|";
	}

      cout << endl << "\t-";
      for (int j = 0 ; j < colonne ; j++)
	cout << "---+" ;
      cout << endl;
    }

}

/*******************************************/
/* Action de verifier de la grille vide    */
/* Grille vide: la valeur 0 a chaque case  */
/*******************************************/

bool entranceValide(int x, int y, TGrille grille)
{
  if (grille[x][y] == -1) return false;
  return true;
}

/*******************************************/
/* Ham lan truyen                          */
/* Nothing fun about it. No. Not at all.   */
/*******************************************/

bool decouvrir(int x, int y)
{ 
  //cout << "decouvrir (" << x+1 << " ; " << y+1 << ")" << endl;

  if (grilleOther[x][y] == -1) return false;
  
  else {

    if (grilleOther[x][y] == 0) 
      grille[x][y] = 10;
        
    if (grilleOther[x + 1][y] == 0) 
      grille[x + 1][y] = 10;
        
    if (grilleOther[x - 1][y] == 0) 
      grille[x - 1][y] = 10;

    if (grilleOther[x][y - 1] == 0) 
      grille[x][y - 1] = 10;
        
    if (grilleOther[x][y + 1] == 0) 
      grille[x][y + 1] = 10;
    
    if ((x > 0) && (grilleOther[x - 2][y] == 0) && (grille[x - 2][y] != 10)) 
      decouvrir(x - 1, y);
      
    if ((y > 0) && (grilleOther[x][y - 1] == 0) && (grille[x][y - 1] != 10)) 
      decouvrir(x, y - 1);
    
    if ((x < ligne - 1) && (grilleOther[x + 1][y] == 0) && (grille[x + 1][y] != 10)) 
      decouvrir(x + 1, y);
      
    if ((y < colonne - 1) && (grilleOther[x][y + 1] == 0) && (grille[x][y + 1] != 10)) 
      decouvrir(x, y + 1);
  }
  return true;
}

/*******************************************/
/* Main                                    */
/*******************************************/

int main()
{  
  saisirDonnees();
  initGrille(grille);
  initGrille(grilleOther);
  creerMines(grilleOther);
  updateTableau(grilleOther);

  int x, y;
  bool c;
 
  do {
    afficherGrille(grilleOther);
    afficherGrille(grille);

    do {
      cout << "Entrez (x,y) de joueur (x, y > 0) : "; cin >> x >> y;
      x--; y--;
      c = entranceValide(x, y, grilleOther);

      if (!c) 
	cout << "Vous etes mort !!!" << endl;
      else 
	decouvrir(x, y);
    } while (!c && (x >= 0) && (y >= 0));

    system("clear");
  } while((x >= 0) && (y >= 0));
}
