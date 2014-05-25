#include <time.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

/************************ --- DECLARATION DES ELEMENTS (CONSTANTS, VARIABLES, TABLEAUX...) --- *********************/

const int TAILLE = 100;
typedef int TGrille[TAILLE][TAILLE];

TGrille grilleJouer, grilleSolution, condition;
//grilleJouer : la grille sur laquelle le joueur joue (ouvrir les positions, marquer les bombes,...)
//grilleSolution : la grille ayant toutes les bombes et les numeros 1, 2, 3...autour des bombes
//condition : un tableau servant a examiner les conditions... (utilise dans la fonction "decouvrir")

/*********************************************** --- PROTOTYPES --- ************************************************/

void initGrille(TGrille grille, int nbColonnes, int nbLignes);
void creerMines(TGrille grille, int nbMines, int nbColonnes, int nbLignes);
void updateTableau(TGrille grille, int nbColonnes, int nbLignes);
void afficherGrille(TGrille grille, int nbColonnes, int nbLignes);
bool decouvrir(int x, int y, int nbColonnes, int nbLignes);
void tickBomb(int x, int y, int & nbMines);
void victoire(int nbColonnes, int nbLignes, int nbMines);  

/************************************************** --- MAIN --- ***************************************************/

int main() {
  int nbMines , nbColonnes, nbLignes;
  int x, y;
  bool play = true, game = true, answer = false;
  
  cout <<"Entrez le nombre de lignes : "; cin >> nbLignes;
  cout <<"Entrez le nombre de colonnes : "; cin >> nbColonnes;
  cout <<"Entrez le nombre de bombes : "; cin >> nbMines;

  initGrille(grilleJouer,    nbColonnes, nbLignes);
  initGrille(grilleSolution, nbColonnes, nbLignes);
  initGrille(condition,      nbColonnes, nbLignes);

  creerMines(grilleSolution, nbMines, nbColonnes, nbLignes);
  updateTableau(grilleSolution, nbColonnes, nbLignes);
 
  do {
    if (game == false && answer == true)   afficherGrille(grilleSolution, nbColonnes, nbLignes);
    if (game == true && answer == false)   afficherGrille(grilleJouer,    nbColonnes, nbLignes);

    do {
      cout << "Le nombre de bombes a decouvrir :  " << nbMines << endl << endl;
      cout << "Entrez le numero '1' : choisir la position a ouvrir sur la grille" << endl
	   << "Entrez le numero '2' : marquer/retirer la bombe" << endl
	   << "Entrez le numero '3' : afficher/eteindre la solution" << endl;
      cout << endl << "Votre choix : ";

      int choix;
      cin >> choix;
      switch (choix) {
      case 1:
	cout << "Entrez (x, y) du joueur (x, y > 0) : ";
	cin >> x >> y;
	x--; y--;        		
	play = decouvrir(x,y, nbColonnes, nbLignes);        		
	break;
      case 2:
	cout << "Entrez (x,y) de la bombe (x, y > 0) : ";
	cin >> x >> y;
	x--; y--;
	tickBomb(x, y, nbMines);
	break;
      case 3:
	if (game) {
	  game = false; 
	  answer = true;
	}	
	else {
	  game = true;
	  answer = false;
	}	
	x = 0, y = 0;
	break;
      }
    } while(x < 0 || x > nbLignes-1 || y < 0 || y > nbColonnes-1);

    system("cls"); 
    //system("clear"); pour Linux

    victoire(nbColonnes, nbLignes, nbMines);

  } while (play);

  if (!play) 
    cout << "BOOM ! Vous etes mort !" << endl;
}

/*********************************************** --- FONCTIONS --- *************************************************/

//affecter la valeur initiale (= 0) a tous les elements du tableau "grille"
void initGrille(TGrille grille, int nbColonnes, int nbLignes)
{
  for (int i = 0 ; i < nbLignes ; i++)
    for (int j = 0 ; j < nbColonnes ; j++)
      grille[i][j] = 0;	      
}


//choisir la position aleatoire des bombes dans la grille
void creerMines(TGrille grille, int nbMines, int nbColonnes, int nbLignes)
{
  srand(time(NULL));
  int x, y;
  
  while (nbMines > 0) {
    x = rand() % nbLignes;
    y = rand() % nbColonnes;

    if (grille[x][y] == 0)
      {
    	grille[x][y] = -1;
    	nbMines--;
      }
  }      
}


//examiner les 8 positions autour de grille[x][y]
void updateTableau(TGrille grille, int nbColonnes, int nbLignes)
{
  srand(time(NULL));
  int x, y;
  
  for (int i = 0 ; i < nbLignes ; i++)
    for (int j = 0 ; j < nbColonnes ; j++) {
      if (grille[i][j] == -1) continue;       
      if ((i > 0) && (grille[i-1][j] == -1)) grille[i][j]++;
      if ((j > 0) && (grille[i][j-1] == -1)) grille[i][j]++;
      if ((i < nbLignes-1) && (grille[i+1][j] == -1)) grille[i][j]++;
      if ((j < nbColonnes-1) && (grille[i][j+1] == -1)) grille[i][j]++;
      if ((i > 0) && (j>0) && (grille[i-1][j-1] == -1)) grille[i][j]++;
      if ((i < nbLignes-1) && (j>0) && (grille[i+1][j-1] == -1)) grille[i][j]++;
      if ((i < nbLignes-1) && (j < nbColonnes-1) && (grille[i+1][j+1] == -1)) grille[i][j]++;
      if ((i > 0) && (j < nbColonnes-1) && (grille[i-1][j+1] == -1)) grille[i][j]++;
    }      
}


//afficher la grille 
void afficherGrille(TGrille grille, int nbColonnes, int nbLignes)
{
  cout << "\n\n\n\t";
  for (int j = 0 ; j < nbColonnes ; j++)
    {
      if (j <= 9) cout << "  " << j+1 <<" ";
      else cout << " " << j+1 <<" ";
    }
  cout << endl;
  cout << endl << "\t-";
  for (int j = 0 ; j < nbColonnes ; j++)
    cout << "---+" ;
  cout << endl;
      
  for (int i = 0 ; i < nbLignes ; i++)
    {
      cout << i+1 << "\t|";
      for (int j = 0 ; j < nbColonnes ; j++)
	{
	  switch (grille[i][j])
	    {
	    case 10 : cout << ":::"; break; //la position vide
	    case -1 : cout << "BOM"; break; //la bombe
	    case 0 : cout << "   "; break;  //l'etat initial, le joueur n'ouvre pas encore cette position
	    default : cout << " " << grille[i][j] << " "; //les numeros 1, 2, 3... autour de la bombe
	    }
	  cout << "|";
	}

      cout << endl << "\t-";
      for (int j = 0 ; j < nbColonnes ; j++)
	cout << "---+" ;
      cout << endl;
    }
}


//decouvrir les bombes, la fonction la plus importante 
bool decouvrir(int x, int y, int nbColonnes, int nbLignes)
{ 
  int a[nbColonnes];
  for (int i = 0; i < nbColonnes; i++) //Sua loi: Neu chon so bom thap, sau lan chay ham de quy dau tien thi dong dau
    a[i] = grilleSolution[0][i];                //cua grilleSolution co vai o thay doi gia tri
  
  int b;
  if (y == nbColonnes-1) //Sua loi: Moi khi mo 1 o cot cuoi dong i, thi o dong i+2 cot dau tien hien ket qua
    if (x+2 < nbLignes-1)
      b = grilleJouer[x+2][0];

  if (grilleSolution[x][y] == -1 && condition[x][y] == 0) return false; //ici c'est la bombe, BOOOOMMMMM you die
  
  else if (grilleSolution[x][y] == 0)
    {
      grilleJouer[x][y] = 10;
      condition[x][y] = 1;
      
      if (x < nbLignes -1) {
	grilleJouer[x+1][y] = grilleSolution[x+1][y];
	if (grilleJouer [x+1][y] == 0) grilleJouer [x+1][y] = 10;
	else condition[x+1][y] = 1;
      }        	
      
      if (x > 0) {	
	grilleJouer[x-1][y] = grilleSolution[x-1][y];
	if (grilleJouer [x-1][y] == 0) grilleJouer [x-1][y] = 10;
	else condition[x-1][y] = 1;
	
      }		
      if (y > 0){
	grilleJouer[x][y-1] = grilleSolution[x][y-1];
	if (grilleJouer [x][y-1] == 0) grilleJouer [x][y-1] = 10;
	else condition[x][y-1] = 1;
      }			
      
      if (y < nbColonnes-1) {
	grilleJouer[x][y+1] = grilleSolution[x][y+1];
	if (grilleJouer[x][y+1] == 0) grilleJouer[x][y+1] = 10;
	else condition[x][y+1] = 1;
      }
      
      if (x > 0 && y > 0) {
	grilleJouer[x-1][y-1] = grilleSolution[x-1][y-1];
	if (grilleJouer[x-1][y-1] == 0) grilleJouer[x-1][y-1] = 10;
	else condition[x-1][y-1] = 1;
      }
      
      if (x > 0 && y < nbColonnes-1) {
	grilleJouer[x-1][y+1] = grilleSolution[x-1][y+1];
	if (grilleJouer[x-1][y+1] == 0) grilleJouer[x-1][y+1] = 10;
	else condition[x-1][y+1] = 1;
      }

      if (x < nbLignes-1 && y > 0) {
	grilleJouer[x+1][y-1] = grilleSolution[x+1][y-1];
	if (grilleJouer[x+1][y-1] == 0) grilleJouer[x+1][y-1] = 10;
	else condition[x+1][y-1] = 1;
      }

      if (x < nbLignes && y < nbColonnes) {
	grilleJouer[x+1][y+1] = grilleSolution[x+1][y+1];
	if (grilleJouer[x+1][y+1] == 0) grilleJouer[x+1][y+1] = 10;
	else condition[x+1][y+1] = 1;
      }		
      
      if ((x > 0) && (grilleSolution[x-1][y] == 0) && (condition[x-1][y] == 0)) 
	decouvrir(x-1, y, nbColonnes, nbLignes);

      if ((x < nbLignes-2) && (grilleSolution[x+1][y] == 0) && (condition[x+1][y] == 0))
	decouvrir(x+1,y, nbColonnes, nbLignes);
 
      if ((y > 0) && (grilleSolution[x][y-1] == 0) && (condition[x][y-1] == 0)) 
	decouvrir(x, y-1, nbColonnes, nbLignes);
      
      if ((y < nbColonnes-2) && (grilleSolution[x][y+1] == 0) && (condition[x][y+1] == 0)) 
	decouvrir(x, y+1, nbColonnes, nbLignes);     
    }
  
  else {
    grilleJouer[x][y] = grilleSolution[x][y]; 
    condition[x][y] = 1;
  }
  
  for (int i = 0 ; i < nbColonnes; i++) //sua van de grilleSolution bi thay doi gia tri
    grilleSolution[0][i] = a[i];

  if(y == nbColonnes-1) //sua van de cu moi khi mo 1 o cot cuoi dong i, thi o dong i+2 cot dau tien hien ket qua
    if(x+2 < nbLignes-1)
      grilleJouer[x+2][0] = b;
  
  return true;
}


//marquer les bombes
void tickBomb(int x, int y, int & nbMines) {
  if (condition[x][y] == 0) {
    grilleJouer[x][y]= -1;
    condition[x][y] = 1;
    nbMines--;
  }
  
  else {
    grilleJouer[x][y] = 0;
    condition[x][y] = 0;
    nbMines++;
  }
}


//calculer & annoncer le resultat
void victoire(int nbColonnes, int nbLignes, int nbMines)
{
  int check = 0, checkBomb = 0;

  for (int i = 0 ; i < nbLignes ; i++)
    for (int j = 0 ; j < nbColonnes ; j++)
      if (grilleJouer[i][j] != 0)
	check++;
  
  for (int i = 0 ; i < nbLignes ; i++)
    for (int j = 0 ; j < nbColonnes ; j++)
      if (grilleJouer[i][j] != 0 && grilleSolution[i][j] != -1)
	checkBomb++;
  
  if (check == nbLignes*nbColonnes || checkBomb == nbLignes*nbColonnes - nbMines) {
    afficherGrille(grilleSolution, nbColonnes, nbLignes);
    cout << "Bravo, vous avez gagne !" << endl;
    exit(0);
  }
}
