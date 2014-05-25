#include <iostream>
#include <ctime>
#include <cstdlib>
#include <math.h>
#include <vector>
#include <map>
#include <sstream>
#include <string>
// Définition de la taille de la grille
const int TAILLE = 15;

// Définition du type TGrille
typedef int TGrille[TAILLE][TAILLE];

using namespace std;


/*****************************************/
/* Remarque : la constante TAILLE est    */
/* déclarée dans le fichier en-tête      */
/* morpion.h   Elle est donc connue dans */
/* tout le fichier                       */
/* (grâce au include "morpion.h")        */
/* c'est une constante globale           */
/*****************************************/

TGrille grille; // Déclaration de ma gille de morpion


/****************************************/
/* Action d'initialisation de la grille */
/* On affecte la valeur 0 à chaque case */
/****************************************/

void initGrille(TGrille grille)
{
  for (int i = 0 ; i < TAILLE ; i++)
    for (int j = 0 ; j < TAILLE ; j++)
      grille[i][j] = 0;
}

/****************************************/
/* Action d'affichage de la grille */
/* On affecte la valeur 0 à chaque case */
/****************************************/
void afficherGrille(TGrille grille)
{
  cout << endl << "\t-";
  for (int j = 0 ; j < TAILLE ; j++)
      cout << "---+" ;
  cout << endl;
      
  for (int i = 0 ; i < TAILLE ; i++)
    {
      cout << i+1 << "\t|";
      for (int j = 0 ; j < TAILLE ; j++)
	{
	  switch (grille[i][j])
	    {
	    case 0 : cout << "   "; break;
	    case 100 : cout << "bom"; break;
	    case 1 : cout << " 1 "; break;
	    case 2 : cout << " 2 "; break;
	    case 3 : cout << " 3 "; break;
	    case 4 : cout << " 4 "; break;
	    case 5 : cout << " 5 "; break;
	    case 6 : cout << " 6 "; break;
	    case 7 : cout << " 7 "; break;
	    case 8 : cout << " 8 "; break;
	    
	    default : cout << "***";
	    }
	  cout << "|";
	}

      cout << endl << "\t-";
      for (int j = 0 ; j < TAILLE ; j++)
           cout << "---+" ;
      cout << endl;
    }

}

int main()
{  
  initGrille(grille);
  int boom=12;
  int x,y;
  bool c, v, joueur =true;
  srand(time(NULL));
  while (boom>0)
  {
    x=rand()%15+1;
    y=rand()%15+1;
    if (grille[x][y]==0)
    {grille[x][y]=100;
	    boom--;}
  }
  for (int i =0; i <15; i++)
    for (int j=0; j<15; j++)
      if(grille[i][j]==0)
      for (int h = i-1; h<i+2; h++)
	for (int k=j-1; k<j+2; k++)
	   if(grille[h][k]==100)
	      grille[i][j]+=1;
  afficherGrille(grille);
}
