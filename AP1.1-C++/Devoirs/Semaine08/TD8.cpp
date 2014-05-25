#include <iostream>
#include <cstdlib>
#include <string>
#include <math.h>
using namespace std;

/**********************************************----- QUESTION 1 -----**********************************************/

/*
void backToSchool(int tab1[], int tab2[], int tab3[], int taille) {
  for (int i = 0 ; i < taille ; i++)
    tab3[i] = tab1[i] + tab2[i];
  
  for (int i = taille - 1 ; i > 0 ; i--) 
    if (tab3[i] > 9) {
      tab3[i] -= 10;
      tab3[i - 1] += 1;
    }
}


void afficher(int tab[], int taille) {
  for (int i = 0 ; i < taille ; i++) {
    if (i != 0 && (taille - i) % 3 == 0) 
      cout << '.';
    cout << tab[i];
  }

  cout << endl;
}


int main() {
  const int TMAX = 12;
  int tab1[TMAX] = {9, 9, 8, 0, 5, 8, 3, 1, 7, 2, 9, 3};
  int tab2[TMAX] = {3, 2, 0, 2, 3, 4, 7, 0, 5, 1, 0, 5};
  int tab3[TMAX];

  backToSchool(tab1, tab2, tab3, TMAX);
  afficher(tab3, TMAX);

  return EXIT_SUCCESS;
}
*/

/**********************************************----- QUESTION 2 -----**********************************************/
      
/*
float fonction1(float x) {
  float resultat;
  resultat = 1/(1 - x);
  
  return resultat;
}


float fonction2(float x) {
  float resultat;
  resultat = 1/(1 + x);

  return resultat;
}


int main() {
  float x = 0.5;
  cout << fonction1(x) << endl;
  cout << fonction2(x) << endl;

  return EXIT_SUCCESS;
}
*/

/******************************************----- QUESTION 3 + 4 + 5-----*******************************************/

float fonction1(float x) {
  float resultat;
  resultat = 1/(1 - x);
  
  return resultat;
}


float fonction2(float x) {
  float resultat;
  resultat = 1/(1 + x);

  return resultat;
}


float g1(float x, int n) {
  if (n == 0)
    return 1;
  else if (n == 1)
    return 1 + x;
  else
    return 1 + g1(x, n - 1)*x;
}


float g2(float x, int n) {
  if (n == 0)
    return 1;
  else if (n == 1)
    return 1 - x;
  else
    return 1 - g2(x, n - 1)*x;
}


int trouverPetit(float x, float e) {
  float a, b;
  a = fonction1(x);

  int i = 0;
  
  for ( ; ; i++) {
    b = g1(x, i);
    if ( a - b <= e )
      break;
  }

  return i;
}


int main() {
  float x;
  cout << "Entrez x : ";
  cin >> x;
  
  int ordre;
  
  float e;
  cout << "Entrez l'erreur e : ";
  cin >> e;
  
  char choix;
  cout << "Deux methodes 1 faire : " << endl
       << "1. Utiliser la formule de la suite des nombres : " << endl
       << "2. Une facon plus intelligente" << endl
       << "Votre choix : ";
  cin >> choix;

  switch(choix) {
  case '1' :
    goto methode1;
    break;
  case '2' :
    goto methode2;
    break;
  default :
    cout << "Erreur" << endl;
    break;
  }



 methode1:
  float gInf, gSup;

  gInf = fonction1(x) - e;
  gSup = fonction1(x) + e;

  cout << "La limite de g1(x, n) : " << gInf << " < g1(x,n) < " << gSup << endl;
  
  if (gSup == 1 || gInf == 1)
    cout << "n = 0" << endl;
  else if (gSup == 1 + x || gInf == 1 + x)
    cout << "n = 1" << endl;
  else {
    ordre = log(1 - gInf*(1 - x))/log(x) - 1;
    cout << "n = " << ordre << endl;
  }
  exit(0);
  


 methode2:
  cout << "n = " << trouverPetit(x,e) << endl;


  return EXIT_SUCCESS;
}


/******************************************----- QUESTION 6 + 7 + 8 -----******************************************/

/*
void saisirTab(int tab[], int taille) {
  cout << "Entrez les elements : " << endl;
  for (int i = 0 ; i < taille ; i++)
    cin >> tab[i];
}


void afficherTab(int tab[], int taille) {
  cout << "tab : ";
  for (int i = 0 ; i < taille ; i++)
    cout << tab[i] << "  ";
  cout << endl;
}

 
void remplacerDoublon(int tab[], int taille) {
  for (int i = 0 ; i < taille - 1 ; i++)
    for (int j = i + 1 ; j < taille ; j++)
      if (tab[i] == tab[j])
	tab[j] = -1;
}


void decalerGauche(int tab[], int & taille, int pos) {
  for (int i = pos ; i < taille - 1 ; i++)
    tab[i] = tab[i + 1];

  taille--;
}


void supprimerElem(int tab[], int & taille, int elem) {
  for (int i = 0 ; i < taille ; i++)
    if (tab[i] == elem) {
      decalerGauche(tab, taille, i);
      i = 0;
    }
}


int main() {
  const int MAX = 100;
  int tab[MAX];
  
  int taille;
  cout << "Entrez la taille n : ";
  cin >> taille;

  saisirTab(tab, taille);
  afficherTab(tab, taille);

  remplacerDoublon(tab, taille);
 
  int x = -1;
  
  supprimerElem(tab, taille, x);
  afficherTab(tab, taille);
  cout << "Le nombre d'elements restants : " << taille << endl;

}
*/

/**********************************************----- QUESTION 9 -----**********************************************/

/*
const int MAX = 20;
char mot[MAX];
char sousMot[MAX];
char motif[MAX];


void saisirChar(char tab[], int taille) {
  cout << "Entrez le mot/le sous-mot : ";
  for (int i = 0 ; i < taille ; i++)
    cin >> tab[i];
}


void testSousMot(char tab1[], char tab2[], int taille1, int taille2) {
  for (int j = 0 ; j < taille1 - taille2 + 1; j++)
    if (tab1[j] == tab2[0]) {
      if (taille2 > 1)
	for (int f = j + 1, k = 1; k < taille2 ; k++, f++) {
	  if (tab1[f] != tab2[k])
	    break;
	  else
	    if (k == taille2 - 1)
	      cout << "sous-mot" << endl;
	}
      else
	cout << "sous-mot" << endl;
    }
}  


void testMotif(char tab1[], char tab2[], int taille1, int taille2) {
  int chk = 0;
  
    for (int j = 0 ; j < taille1 ; j++) {
      if (tab1[j] == tab2[chk])
	chk++;
      if (chk == taille2 - 1) {
	cout << "motif" << endl;
	break;
      }
    }   
}


int main() {
  int tm;
  cout << "Entrez le nombre de caracteres de ce mot : ";
  cin >> tm;
  saisirChar(mot, tm);

  char choix;

  do {

    int ts;
    cout << "Entrez le nombre de caracteres de ce sous-mot : ";
    cin >> ts;
    saisirChar(sousMot, ts);  
    testSousMot(mot, sousMot, tm, ts);


    int tmo;
    cout << "Entrez le nombre de caracteres de ce motif : ";
    cin >> tmo;
    saisirChar(motif, tmo);
    testMotif(mot, motif, tm, tmo);

    
    cout << "Continue ? (y/n) : ";
    cin >> choix;
        
  } while (choix == 'y');
}
*/
