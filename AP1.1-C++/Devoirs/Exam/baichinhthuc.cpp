#include <iostream>
#include <fstream>
#include<string>
#include<cstdlib>
#include<math.h>
#include <vector>
#include <ctime>
#include <sstream>
#include <map>
using namespace std;

void afficher_matrice(int matrice[][9])
{
  for(int i=0;i<8;i++)
    {
      for(int j=0;j<8;j++)
	cout<<matrice[i][j]<<" ";
      cout<<endl;
    }
}
void entrer_matrice(ifstream &f, int matrice[][9])
{
  
  for(int i=0;i<8;i++)
    for(int j=0;j<8;j++)
      f>>matrice[i][j];
}
void entrer_valeur(int matrice[9][9], int i, int j)
{
  while(1){ 
    afficher_matrice(matrice);
    cout<<"Veuillez entrer les coordonnees i et j"<<endl;
    cout << "i=";cin >> i; cout << "j="; cin >> j;
    cout<<"la valeur choisie"<<endl;
    cin>>matrice[i][j];
    system("clear");
  }
}
int main()
{
  int i, j;
  int matrice[9][9];
  ifstream f("sodoku.txt");
  entrer_matrice(f,matrice);
  entrer_valeur(matrice,i,j);
  
  
}

  for ( int a=0; a<=9; a++)
    {
      for (int b=0; b<=9; b++)
	{
	  if (matrice[i][j]==0)
	    cout << "0";
	  else cout << "a";
	}
    }
 
    }*/

/*const int TAILLE = 9 ;

typedef int TGrille[TAILLE][TAILLE];

using namespace std;

int lireFichier()
{
  string line;
  string fichier;
  cout << "Enter the name of the file for the student data to be read for input" << endl;
  cout << " (Note: The file and path cannot contain spaces)" << endl;
  cout << endl;
  cin >> fichier;
   fstream f;
  f.open(fichier.c_str(), ios::in );
  if( f.fail() ) {
    cerr << "ouverture en lecture impossible" << endl;
    exit(EXIT_FAILURE);
  }  
 
  if (f.is_open())
  {
    while ( getline (f,line) )
    {
      cout << line << '\n';
    }
    f.close();
  }

  else cout << "Unable to open file"; 

}


TGrille grille; 


void initGrille(TGrille grille)
{
  for (int i = 0 ; i < TAILLE ; i++)
    for (int j = 0 ; j < TAILLE ; j++)
      grille[0][1] = 1;
  grille[0][4] = 2;
  grille[0][6] = 3;
  grille[1][1] = 2;
  grille[1][3] = 4;
  grille[1][5] = 5;
  grille[2][0] = 6;
  grille[2][3] = 7;
  grille[2][5] = 1;
  grille[2][7] = 8;
  grille[2][8] = 5;
  grille[3][0] = 5;
  grille[3][2] = 4;
  grille[3][5] = 2;
  grille[3][7] = 7;
  grille[4][2] = 6;
  grille[4][6] = 1;
  grille[5][1] = 8;
  grille[5][3] = 6;
  grille[5][6] = 4;
  grille[5][8] = 9;
  grille[6][0] = 9;
  grille[6][1] = 3;
  grille[6][3] = 5;
  grille[6][5] = 8;
  grille[6][8] = 4;
  grille[7][3] = 1;
  grille[7][5] = 9;
  grille[7][7] = 2;
  grille[8][2] = 7;
  grille[8][4] = 4;
  grille[8][7] = 6;
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
	    case 0 : cout << "   "; break;
	    case 1 : cout << " 1 "; break;
	    case 2 : cout << " 2 "; break;
	    case 3: cout << " 3 ";break;
	    case 4: cout << " 4 ";break;
	    case 5: cout << " 5 ";break;
	    case 6: cout << " 6 ";break;
	    case 7: cout << " 7 ";break;
	    case 8: cout << " 8 ";break;
	    case 9: cout << " 9 ";break;
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
int main( int argc, char* argv[] )
{
  string mot, s;
  int n; int a;
  
  lireFichier();
  cin >> a;
  initGrille(grille);
  afficherGrille(grille);
  int i, j;
  for ( int a=0; a<=9; a++)
    {
      for (int b=0; b<=9; b++)
	{
	  if (grille[i][j]==" ")
	    cout << "a";
	}
    }
  
  return EXIT_SUCCESS;
}
*/
