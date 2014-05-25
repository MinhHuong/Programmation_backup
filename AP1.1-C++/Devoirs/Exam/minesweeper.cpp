#include <time.h>
#include <stdlib.h>
#include <iostream>
// Définition de la taille de la grille
const int TAILLE = 10;

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

TGrille grille, grille1; // Déclaration de ma gille de morpion


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
/* Action d'initialisation des mines    */
/* On affecte la valeur -1 à chaque case */
/****************************************/
void creerMines(TGrille grille, int nbMines)
{
  srand(time(NULL));
  int x,y;
  //int r = rand()*10/RAND_MAX;
  //cout << r;
  for (int i = 0 ; i < nbMines ; i++){
    x = rand()*TAILLE/RAND_MAX;
    y = rand()*TAILLE/RAND_MAX;
    grille[x][y] = -1;
  }      
}


/****************************************/
/* Action d'initialisation des mines    */
/* On affecte la valeur -1 à chaque case */
/****************************************/
void updateTableau(TGrille grille)
{
  srand(time(NULL));
  int x,y;
  //int r = rand()*10/RAND_MAX;
  //cout << r;
  for (int i = 0 ; i < TAILLE ; i++)
    for (int j = 0 ; j < TAILLE ; j++){
      if (grille[i][j] == -1) continue;
      if ((i>0)&&(grille[i-1][j] == -1)) grille[i][j]++;
      if ((j>0)&&(grille[i][j-1] == -1)) grille[i][j]++;
      if ((i<TAILLE-1)&&(grille[i+1][j] == -1)) grille[i][j]++;
      if ((j<TAILLE-1)&&(grille[i][j+1] == -1)) grille[i][j]++;
      if ((i>0)&&(j>0)&&(grille[i-1][j-1] == -1)) grille[i][j]++;
      if ((i<TAILLE-1)&&(j>0)&&(grille[i+1][j-1] == -1)) grille[i][j]++;
      if ((i<TAILLE-1)&&(j<TAILLE-1)&&(grille[i+1][j+1] == -1)) grille[i][j]++;
      if ((i>0)&&(j<TAILLE-1)&&(grille[i-1][j+1] == -1)) grille[i][j]++;
    }      
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
        case 10 : cout << " X "; break;
	    case -1 : cout << "bom"; break;
	    //case 11 : cout << "bom"; break;
        case 0 : cout << "   "; break;	    
        default : cout << " " << grille[i][j] << " "; 
	    }
	  cout << "|";
	}

      cout << endl << "\t-";
      for (int j = 0 ; j < TAILLE ; j++)
           cout << "---+" ;
      cout << endl;
    }

}

/*******************************************/
/* Action de verifier de la grille vide    */
/* Grille vide: la valeur 0 à chaque case  */
/*******************************************/
bool estVide(TGrille grille)
{
     for (int i = 0 ; i < TAILLE ; i++){
        for (int j = 0 ; j < TAILLE ; j++){
	        if (grille[i][j]!= 0)
    	       return false;
        }
     }
     return true;
}

/*******************************************/
/* Action de verifier de la grille vide    */
/* Grille vide: la valeur 0 à chaque case  */
/*******************************************/
bool entranceValide(int x, int y, TGrille grille)
{
     if (grille[x][y]==-1) return false;
     return true;
}

/*******************************************/
/* Action de verifier de la grille vide    */
/* Grille vide: la valeur 0 à chaque case  */
/*******************************************/
bool decouvrir(int x, int y)
{ 
     //cout << "decouvrir (" << x+1 << " ; " << y+1 << ")" << endl;
     if (grille1[x][y]==-1) return false;
     else{
        grille[x][y]=grille1[x][y];
        if (grille[x][y]==0) grille[x][y]=10;
        grille[x+1][y]=grille1[x+1][y];
        if (grille[x+1][y]==0) grille[x+1][y]=10;
        grille[x][y-1]=grille1[x][y-1];
        if (grille[x][y-1]==0) grille[x][y-1]=10;
        grille[x+1][y+1]=grille1[x+1][y+1];
        if (grille[x+1][y+1]==0) grille[x+1][y+1]=10;
        
        if ((x>0)&&(grille1[x-1][y] == 0) && (grille[x-1][y] != 10)) {decouvrir(x-1,y);}
        if ((y>0)&&(grille1[x][y-1] == 0) && (grille[x][y-1] != 10)) {decouvrir(x,y-1);}
        if ((x<TAILLE-1)&&(grille1[x+1][y] == 0)&& (grille[x+1][y] != 10)){decouvrir(x+1,y);}
        if ((y<TAILLE-1)&&(grille1[x][y+1] == 0)&& (grille[x][y+1] != 10)) {decouvrir(x,y+1);}
     }
     return true;
}

/*******************************************/
/* Main                                    */
/*******************************************/

int main()
{  
  initGrille(grille);
  initGrille(grille1);
  creerMines(grille1,10);
  updateTableau(grille1);
  int x,y;
  bool c;
  do{
     afficherGrille(grille1);
     afficherGrille(grille);
     do{
        cout << "Entrez (x,y) de joueur ";
        cout << " : (quittez si valeur donnee n'est pas positive)";
        cin >> x >> y;
        x--; y--;
        c= entranceValide(x,y,grille1);
        if (!c) cout << "Vous etes mort !!!" << endl;
        else decouvrir(x,y);
     }while(!c && (x>=0) && (y>=0));
     system("cls");
  }while((x>=0)&&(y>=0));
}
