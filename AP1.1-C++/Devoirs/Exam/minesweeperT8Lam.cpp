
#include <time.h>
#include <stdlib.h>
#include <iostream>
// Definition de la taille de la grille
const int TAILLE = 10;

// Definition du type TGrille
typedef int TGrille[TAILLE][TAILLE];

using namespace std;

TGrille grille, grille1; // Declaration de ma gille de morpion

void initGrille(TGrille grille)
{
  for (int i = 0 ; i < TAILLE ; i++)
    for (int j = 0 ; j < TAILLE ; j++)
      grille[i][j] = 0;
}

void creerMines(TGrille grille, int nbMines)
{
  srand(time(NULL));
  int x,y;
  //int r = rand()*10/RAND_MAX;
  //cout << r;
  for (int i = 0 ; i < nbMines ; i++){
    x = rand()%TAILLE+1;
    y = rand()%TAILLE+1;
    grille[x][y] = -1;
    //cout << "bomb ("<<x<<","<<y<<")"<< endl;
  }      
}

void updateTableau(TGrille grille)
{
  srand(time(NULL));
  int x,y;
  //int r = rand()*10/RAND_MAX;
  //cout << r;
  for (int i = 0 ; i < TAILLE ; i++)
    for (int j = 0 ; j < TAILLE ; j++){
      if (grille[i][j] == -1) continue;
      if ((i>0) && (grille[i-1][j] == -1)) grille[i][j]++;
      if ((j>0) && (grille[i][j-1] == -1)) grille[i][j]++;
      if ((i<TAILLE-1) && (grille[i+1][j] == -1)) grille[i][j]++;
      if ((j<TAILLE-1) && (grille[i][j+1] == -1)) grille[i][j]++;
      if ((i>0)&&(j>0) && (grille[i-1][j-1] == -1)) grille[i][j]++;
      if ((i<TAILLE-1) && (j>0)&&(grille[i+1][j-1] == -1)) grille[i][j]++;
      if ((i<TAILLE-1) && (j<TAILLE-1) && (grille[i+1][j+1] == -1)) grille[i][j]++;
      if ((i>0) && (j<TAILLE-1) && (grille[i-1][j+1] == -1)) grille[i][j]++;
    }      
}

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
	    //cout << " " << grille[i][j] << " "; 
	  cout << "|";
	}

      cout << endl << "\t-";
      for (int j = 0 ; j < TAILLE ; j++)
           cout << "---+" ;
      cout << endl;
    }

}

/*bool estVide(TGrille grille)
{
     for (int i = 0 ; i < TAILLE ; i++){
        for (int j = 0 ; j < TAILLE ; j++){
	        if (grille[i][j]!= 0)
    	       return false;
        }
     }
     return true;
}*/

bool entranceValide(int x, int y, TGrille grille)
{
     if (grille[x][y]==-1) return false;
     return true;
}

bool decouvrir(int x, int y)
{ 
     //cout << "decouvrir (" << x+1 << " ; " << y+1 << ")" << endl;
     if (grille1[x][y]==-1) return false;
     else{
        grille[x][y]=grille1[x][y];
        if (grille[x][y]==0) grille[x][y]=10;
        
	grille[x+1][y]=grille1[x+1][y];
        if (grille[x+1][y]==0) grille[x+1][y]=10;
        
	grille[x-1][y]=grille1[x-1][y];
        if (grille[x-1][y]==0) grille[x-1][y]=10;

	grille[x][y-1]=grille1[x][y-1];
        if (grille[x][y-1]==0) grille[x][y-1]=10;
        
	grille[x][y+1]=grille1[x][y+1];
        if (grille[x][y+1]==0) grille[x][y+1]=10;
        
        if ((x>0) &&(grille1[x-2][y] == 0) && (grille[x-2][y] != 10)) {decouvrir(x-1,y);}
        if ((y>0)&&(grille1[x][y-1] == 0) && (grille[x][y-1] != 10)) {decouvrir(x,y-1);}
        if ((x<TAILLE-1)&&(grille1[x+1][y] == 0)&& (grille[x+1][y] != 10)){decouvrir(x+1,y);}
        if ((y<TAILLE-1)&&(grille1[x][y+1] == 0)&& (grille[x][y+1] != 10)) {decouvrir(x,y+1);}
     }
     return true;
}

int main()
{  
  initGrille(grille);
  initGrille(grille1);
  creerMines(grille1,25);
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
     system("clear");
  }while((x>=0)&&(y>=0));
}
