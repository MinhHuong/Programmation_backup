#include <iostream>
#include <cstdlib>
#include <unistd.h>
#include <math.h>
#include <stdio.h>
#include <termios.h>
using namespace std;


/*
int main()
{
  int N;
  cout << "Entrez N = " ; cin >> N;
  
  if (N % 2 == 0)
    cout << "N est pair" << endl ;
  else
    cout << "N est impair" << endl;
}
*/


/*
int main()
{
  int nb;
  double somme = 0.0, test = 0.0;
  double moyenne; 
  cout << "Entrez 1 nombre = " ; cin >> nb;

  while (nb != 0)
    {
      test += 1.0;
      somme += nb;
      cout << "Entrez 1 nombre = " ; cin >> nb;
    }
  
  cout << "La somme = " << somme << endl;
  moyenne = somme/test;
  cout << "La moyenne = " << moyenne << endl;
}
*/



int main()
{
  int N;
  int temp;
  bool test = true;


  while(test)
    {
      cout << "Entrez N = " ; cin >> N;

      if (N > 0)     
	{ temp = N;
	  cout << "Entrez N = " ; cin >> N;
	  if (N < temp)
	    test = false; }	    

      else 
	{ cout << "Entrez 1 nombre positif !" << endl;
	  continue; }
    }
}



/*
int main()
{
  int N, max;
  bool test = true;

  while (test)
    {
      cout << "Entrez N = " ; cin >> N;
      
      if (N > 0)
	{ if (N > max)
	    max = N;
	  cout << "max = " << max << endl; }
      else
	{ cout << "Entrez 1 nombre entier positif !" << endl;
	  continue; }
    }
}
*/



/*
int main()
{
  int a,b,temp;
  cout << "Entrez a = " ; cin >> a ;
  cout << "Entrez b = " ; cin >> b ;
  
  temp = a;
  a = b ;
  b = temp;
  
  cout << "a = " << a << " et b = " << b << endl;
}
*/


/*
int main()
{
  int a,b;
  cout << "Entrez a = " ; cin >> a;
  cout << "Entrez b = " ; cin >> b;

  a += b;
  b = a - b;
  a = a - b;
  
  cout << "a = " << a << " et b = " << b << endl;
}
*/



/*
int main()
{
  int a,b,c,d,min;
  cout << "Entrez a = " ; cin >> a;
  cout << "Entrez b = " ; cin >> b;
  cout << "Entrez c = " ; cin >> c;
  cout << "Entrez d = " ; cin >> d;

  min = a < b ? a : b;
  min = min < c ? min : c;
  min = min < d ? min : d;

  cout << "Min = " << min << endl;
}
*/



// EQUATION DU PREMIER DEGRE : AX + B = 0

/*
void premier_degre (float a, float b);


int main()
{
  float a,b;
  cout << "Entrez a = " ; cin >> a;
  cout << "Entrez b = " ; cin >> b;
  premier_degre(a,b);
}
*/


/*
void premier_degre (float b, float c)
{
  if (b != 0) 
    cout << "L'equation a 1 une seule solution = " << -c/b << endl;
  else
    { if (c == 0)
	cout << "L'equation accepte n'importe quelle solution" << endl;
      else
	cout << "L'equation n'a pas de solution" << endl; }
}


void second_degre (float a, float b, float c, float delta)
{
  delta = b*b - 4*a*c;

  if (delta == 0)
    cout << "L'equation a 1 seule solution x = " << -b/(2*a) << endl;
  else if (delta != 0)
    { if (delta > 0)
	cout << "L'equation a 2 solutions x1 = " << (-b + sqrt(delta))/(2*a) << 
	  " et x2 = " << (-b - sqrt(delta))/(2*a) << endl;
      else
	cout << "L'equation n'a pas de solution" << endl; }
}


int main()
{
  float a,b,c,delta;
 
  cout << "Entrez a = " ; cin >> a;
  cout << "Entrez b = " ; cin >> b;
  cout << "Entrez c = " ; cin >> c;
  
  if (a != 0)
    second_degre (a,b,c,delta);
  else
    premier_degre (b,c);
}
*/


/*
int main()
{
  int N;
  cout << "Entrez N = " ; cin >> N;
  

  float temp, min = 99.0, max = -99.0, somme = 0.0, moyenne;

  for (int i = 0 ; i < N ; i++)
    {
      cout << "Entrez la temperature = " ; cin >> temp;
      
      if (temp < min)
	min = temp;

      if (temp > max)
	max = temp;

      somme += temp;
    }

  cout << "La temperature minimale = " << min << endl;
  cout << "La temperature maximale = " << max << endl;
  cout << "La temperature moyenne = " << somme/N << endl;
}
*/	  

/*****************************************************************************************************************/
/********************************************* --- 4/11/2013 --- *************************************************/
/*****************************************************************************************************************/

/* MENTION DES NOTES

int main() {
  int note;
  cout << "Entrez la note : " ; cin >> note;
 
  switch (note) {
  case 11:
  case 12:
    cout << "Passable" << endl;
    break;

  case 13 :
  case 14 :
    cout << "Assez bien" << endl;
    break;

  case 15 :
  case 16 :
    cout << "Bien" << endl;
    break;
    
  case 17 :
  case 18 :
  case 19 :
  case 20 :
    cout << "Tres bien" << endl;
    break;


  default :
    cout << "Ajourne" << endl;
    break;
  }
}
*/

/*****************************************************************************************************************/

// EXERCICE 2 : DIDACTICIEL DE CALCUL
  
/*void devinerResultat (int resultat, int deviner) 
{
  if (resultat == deviner)
    cout << "Bravo" << endl << endl;
  else 
    cout << "Perdu" << endl << endl;
}

int main() {
  system("clear");

  char operateur;
  int a, b, resultat;
  
  cout << "1. Exercice sur l'addition" << endl 
       << "2. Exercice sur la soustraction" << endl
       << "3. Exercice sur la multiplication" << endl;
  
  double max;
  cout << endl << "Entrez le maximum des operandes : " ;
  cin >> max;

  srand(time(NULL));
  a = (int) (max * rand() / RAND_MAX);
  b = (int) (max * rand() / RAND_MAX);

  srand(time(NULL));

 here :

  char choix;
  cout << endl << "Votre choix : " ; 
  cin >> choix;

  switch (choix) {
  case '1' :
    operateur = '+';
    resultat = a + b;
    break;

  case '2' :
    operateur = '-';
    resultat = a - b;
    break;

  case '3' :
    operateur = 'x';
    resultat = a * b;
    break;

  default :
    cout << endl << "Entree incorrecte. Re-essayez encore une fois." << endl;
    goto here;
    break;
  }

  int deviner;
  cout << endl << "Devinez-vous le resultat : " ;
  cin >> deviner;

  cout << endl << "a " << operateur << " b = " << resultat << endl << endl;

  devinerResultat (resultat, deviner);
}
  
/*****************************************************************************************************************/

//TABLEAU : TROUVER 2 NOMBRES MINIMAUX D'UN TABLEAU SAISI

/*
#define TAILLE 20

int Minimum (int Tab[], int nb, int & min1, int & min2) {
  if (Tab[0] > Tab[1]) { 
    min1 = Tab[0];
    min2 = Tab[1];
  }
  else {
    min1 = Tab[1];
    min2 = Tab[0];
  }
    
  for (int j = 2 ; j < nb ; j++) {
    if (Tab[j] < min1) {
      min2 = min1;
      min1 = Tab[j]; 
    }
    else if (Tab[j] < min2)
      min2 = Tab[j]; //en cas ou min1 est le plus minimal nombre dans le tableau, alors il faut verifier min2
  }

  cout << "min1 = " << min1 << endl;
  cout << "min2 = " << min2 << endl;
}

int main() {
  int nb, tab[nb], min1, min2;
  
  cout << "Entrez la taille du tableau (<= 20) : " ;
  cin >> nb;

  cout << "Entrez les nombres : " ;

  for (int i = 0 ; i < nb ; i++) 
    cin >> tab[i];
    
  for (int i = 0 ; i < nb ; i++) 
    cout << "tab[" << i << "] = " << tab[i] << endl;

  Minimum (tab, nb, min1, min2);
}
*/

/*****************************************************************************************************************/

//EXERCICE : TROUVER K NOMBRES MINIMAUX DANS 1 TABLEAU

/*
#define TAILLE 5

int Minimum (int tab[], int min[], int k) {
  min[0] = -999999;
  for (int i = 1 ; i <= k ; i++) {
    min[i] = 999999;
    for (int j = 0 ; j < TAILLE ; j++) {
      if (min[i - 1] < tab[j] && min[i] > tab[j])
	min[i] = tab[j];
    }
    cout << "min[" << i <<"] = " << min[i] << endl;
  }
}


int main() {
  int tab[TAILLE];
  int min[TAILLE];
  
  cout << "Entrez les nombres : " << endl;

  for (int i = 0 ; i < TAILLE ; i++) 
    cin >> tab[i];
    
  for (int i = 0 ; i < TAILLE ; i++) 
    cout << "tab[" << i << "] = " << tab[i] << endl;

  int k;
  cout << "Entrez le nombre des nombres minimaux : " ;
  cin >> k;

  Minimum (tab, min, k);
}
*/

/*****************************************************************************************************************/

#define COMPTEUR 21

void saisirTableau(int tab[], int taille) {
  for (int i = 0 ; i < taille ; i++) {
    cout << "Entrez le nombre : " ;
    cin >> tab[i];
  }
}

void afficherTableau(int tab[], int taille) {
  for (int i = 0 ; i < taille ; i++)
    cout << "tab[" << i << "] = " << tab[i] << endl;
}

int indiceMax(int tab[], int taille) {
  int a;
  int max = tab[0];
  
  for (int i = 1 ; i < taille ; i++) 
    if (tab[i] > max) {
      max = tab[i];
      a = i;
    }

  cout << "max = " << max << " et l'indice du max dans le tableau est max[" << a << "]" << endl; 
}


/*
void indiceMax2(int tab[], int taille, int & max) {
  int a;
  max = tab[0];

  for (int i = 1 ; i < taille ; i++) 
    if (tab[i] > max) {
      max = tab[i];
      a = i;
    }

  cout << "max = " << max << " et l'indice du max dan le tableau est max[" << a << "]" << endl;
}
*/

/*
void Compte (int tab[], int taille, int compteur[], int taille_cpt) {
  int j;
  j = taille;
  cout << j << endl;
}



int main() {

  int taille;
  cout << "Entrez la taille du tableau : ";
  cin >> taille; 
    
  while (taille > 20 || taille <= 0) {
    cout << "Entrez 1 autre taille : ";
    cin >> taille;
  }
    
  int tab[taille];
    
  saisirTableau(tab,taille);
  afficherTableau(tab,taille);
    
  indiceMax(tab,taille);
    
  int compteur[COMPTEUR];
  int taille_cpt;
  Compte (tab,taille,compteur,taille_cpt);
    
  return EXIT_SUCCESS;
} 
*/
