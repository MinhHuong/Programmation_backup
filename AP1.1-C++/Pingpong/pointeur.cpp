#include <iostream>
#include <cstdlib>
#include <unistd.h>
#include <math.h>
#include <stdio.h>
//#include <termios.h>
using namespace std;

/******************************************************************************************************************/

/*
int main() {
  int j = 10;
  int k = 20;
  
  int* adr1 = &j;
  int* adr2;
  adr2 = &k;

  *adr1 = 5;

  cout << *adr1 << " = " << j << endl;
  
  if (adr1 == adr2)
    cerr << "Erreur : 2 variables differentes ne peuvent pas avoir la meme adresse" << endl;

  adr2 = adr1;

  if (adr1 == adr2)
    cerr << "Ces 2 pointeurs pointent sur une meme adresse" << endl;

  if (&adr1 == &adr2)
    cerr << "Ces 2 pointeurs ne peuvent pas avoir la meme adresse" << endl;
  
  if (*adr1 == *adr2)
    cerr << "Ces 2 pointeurs ont une valeur identique" << endl;

  adr2++;

  cout << "La variable j a pour adresse : " << adr1 << endl
       << "La case suivante a pour adresse : " << adr2 << endl;

  if ((adr1 + 1) == adr2)
    cerr << "Ces 2 pointeurs pointent sur 1 meme adresse" << endl;
}
*/

/******************************************************************************************************************/

/*
void echanger1(int & i, int & j) {
  int t = i;
  i = j;
  j = t;
}


void echanger2(int* i, int* j) {
  int t = *i;
  *i = *j;
  *j = t;
}


int main() {
  int a, b;
  cout << "a = "; cin >> a;
  cout << "b = "; cin >> b;

  cout << endl;
  
  echanger1(a, b);
  cout << "a = " << a << endl
       << "b = " << b << endl;

  cout << endl;

  echanger2(&a, &b);
  cout << "a = " << a << endl
       << "b = " << b << endl;
}
*/

/******************************************************************************************************************/

/*
int main() {
  int tab[5] = {0, 1, 2, 3, 4};
  tab[0] = 5;
  tab[1] = 10;

  int* adr1 = tab;
  int* adr2 = tab + 4;

  cout << *adr1 << endl
       << *adr2 << endl
       << adr1 << endl
       << adr2 << endl
       << *(adr1 + 4) << endl;
}
*/

/******************************************************************************************************************/

/*
void saisir(int* deb, int* fin) {
  cout << "Entrez les nombres : " << endl;
  while (deb != fin) {
    cin >> *deb;
    deb++; 
  }
}


void afficher(int* deb, int* fin) {
  cout << "tab : ";
  while (deb != fin) {
    cout << *deb << " ";
    deb++;
  }
  cout << endl;
}


int* Minimum(int t[], int taille, int* min) {
  min = t;
  
  for (int i = 1 ; i < taille ; i++)
    if (*min > t[i])
      min = &t[i];

  return min;
}


int* Maximum(int t[], int taille, int* max) {
  max = t;
  
  for (int i = 1 ; i < taille ; i++)
    if (*max < t[i])
      max = &t[i];

  return max;
}


void MaxMin(int t[], int taille, int* & min, int* & max) {
  min = t;
  max = t;
  
  for (int i = 1 ; i < taille ; i++) {
    if (*min > t[i])
      min = &t[i];
    if (*max < t[i])
      max = &t[i];
  }
}


int main() {
  const int MAX = 5;
  int tab[MAX];

  int* adr1 = tab;
  int* adr2 = tab + MAX;

  saisir  (adr1, adr2);
  afficher(adr1, adr2);

  int* tmin;
  tmin = Minimum(tab, MAX, tmin);
  cout << "min = " << *tmin << endl;

  int* tmax;
  tmax = Maximum(tab, MAX, tmax);
  cout << "max = " << *tmax << endl;

  int* Tmax;
  int* Tmin;
  MaxMin(tab, MAX, Tmin, Tmax);
  cout << "min = " << *Tmin << endl
       << "max = " << *Tmax << endl;
}
*/

/******************************************************************************************************************/
/******************************************************************************************************************/

/************************************************----- TP13 -----**************************************************/

//EXERCICE 1 : EXO-1 (POINTEUR & TABLEAU)

/*
void Saisir(int* p1, int* p2) {
  cout << "Entrez les nombres : " << endl;
  while (p1 != p2) {
    cin >> *p1;
    p1++;
  }
}


void Afficher(int* p1, int* p2) {
  cout << "tab : ";
  while (p1 != p2) {
    cout << *p1 << " ";
    p1++;
  }
  cout << endl;
}


int Somme(int* p1, int* p2) {
  int somme = 0;
  while (p1 != p2) {
    somme += *p1;
    p1++;
  }
  
  return somme;
} 

int main() {
  const int TAILLE = 5;
  int tab[TAILLE];

  int* debut = tab;
  int* fin   = tab + TAILLE;

  Saisir  (debut, fin);
  Afficher(debut, fin);

  cout << "La somme = " << Somme(debut, fin) << endl;

  int* adr = tab;
  
  cout << "L'adresse initiale adr contient la valeur : " << *adr << endl;

  adr++;
  cout << adr << " est different de " << &tab[0] << endl;

  cout << "L'adresse adr maintenant contient la valeur de " << *adr << endl;
}
*/

/******************************************************************************************************************/

//EXERCICE 2 : PASSAGE PAR REFERENCE & PAR VALEUR

/*
int sqrValeur(int a, int b) {
  for (int i = 0 ; i < a ; i++) 
    if (a == i*i) {
      b = i;
      break;
    }
  
  int *adr1 = &a;
  int *adr2 = &b;

  cout << "L'adresse de " << a << " = " << adr1 << endl;
  cout << "L'adresse de " << b << " = " << adr2 << endl;
  
  return b;
}


void sqrReference(int & a, int & b) {
  for (int i = 0 ; i < a ; i++)
    if (a == i*i) {
      b = i;
      break;
    }

  int *adr1 = &a;
  int *adr2 = &b;
  
  cout << "L'adresse de " << a << " = " << adr1 << endl;
  cout << "L'adresse de " << b << " = " << adr2 << endl;
}


int main() {
  int x, y;
  cout << "Entrez le nombre : " ; cin >> x;

  cout << "En utilisant le passage par valeur : " << endl;
  cout << "Le racine carre de " << x << " = " << sqrValeur(x,y) << endl;

  int *p1 = &x;
  int *p2 = &y;
  
  cout << "L'adresse de x = " << p1 << endl;
  cout << "L'adresse de y = " << p2 << endl;

  cout << endl << "En utilisant le passage par reference : " << endl;
  sqrReference(x,y);
  cout << "Le racine carre de ce nombre = " << y << endl;
  cout << "L'adresse de x = " << p1 << endl;
  cout << "L'adresse de y = " << p2 << endl;
  
  
  //les 2 adresses dans la fonction sqr & dans int main() sont differentes --> passage en valeur : copier la valeur de cette variable a 1 autre adresse

  //passage par reference : les parametres appeles dans int main() sont de memes adresses que ceux dans la fonction sqr (

  return EXIT_SUCCESS;
}
*/

/******************************************************************************************************************/

//EXERCICE 3 : PASSAGE PAR ADRESSE

/*
#include<iostream>
#include<cstdlib>
using namespace std;

// passage par reference
void echange1( int & a, int & b ) {
  int t = a;
  a = b;
  b = t;

  cout << "(Fonction) L'adresse de " << a << " : " << &a << endl;
  cout << "(Fonction) L'adresse de " << b << " : " << &b << endl;
}


// utilisation des adresses explicitement (pointeurs)
void echange2( int* pa, int* pb ) {
  int t = *pa;
  *pa = *pb;
  *pb = t;
}


int main() {
  int i = 1, j = 2 ;
  cout << "avant echange1 : "
       << " i = " << i
       << " j = " << j << endl;

  cout << "(Main) Adresse de " << i << " : " << &i << endl;
  cout << "(Main) Adresse de " << j << " : " << &j << endl;

  // passage des variables (par reference implicitement)
  echange1(i, j);
  cout << "apres echange1 : "
       << " i = " << i
       << " j = " << j << endl;

  // passage des adresses des variables explicitement
  echange2(&i, &j);
  cout << "apres echange2 : "
       << " i = " << i
       << " j = " << j << endl;

  return EXIT_SUCCESS;
}
*/
 
/******************************************************************************************************************/

//EXERCICE 4 : TROUVER LE MIN - MAX

/*
int *Minimum(int tab[], int taille) {
  int *min = tab;

  for (int i = 1 ; i < taille ; i++) 
    if (*min > tab[i])
      min = &tab[i];

  return min;
}


void MinMax(int tab[], int taille, int* & max, int* & min) {
  max = tab;
  min = tab;
  
  for (int i = 1 ; i < taille ; i++) {
    if (*max < tab[i])
      max = &tab[i];
    if (*min > tab[i])
      min = &tab[i];
  }
}


int main() {
  const int MAX = 10;
  
  int t[MAX] = {3, 7, 4, 1, 6};
  int taille = 5;
  
  int *ptrmin;
  ptrmin = Minimum(t, taille);
  
  cout << "Min = " << *ptrmin << endl;
  cout << "L'adresse de min = " << ptrmin << endl;

  
  int *tmin;
  int *tmax;
  
  MinMax(t, taille, tmax, tmin);
  cout << "Min = " << *tmin << endl
       << "Max = " << *tmax << endl;
  cout << "Adresse de Min = " << tmin << endl
       << "Adresse de Max = " << tmax << endl;  
}
*/

/******************************************************************************************************************/

//EXERCICE 5 : TRI PAR INDIRECTION

void saisirTab(int *deb, int *fin) {
  cout << "Entrez les nombres : " << endl;
  while (deb != fin) {
    cin >> *deb;
    deb++;
  }
}


void afficherTab(int *deb, int *fin) {
  cout << "Tab : ";
  while (deb != fin) { 
    cout << *deb << " ";
    deb++;
  }
  cout << endl;
}


void ComparerTri(int tab[], int taille, int pos[], int a[]) {
  int tampon = 0;
  int tamp = 0;
  int count = 0;

  for (int i = 0 ; i < taille ; i++) {
    if (a[i] > tampon) {
      pos[0] = i;
      tampon = a[i];
    }
    
    if (a[i] = tampon) {
      pos[1] = i;
      count++;
    }
  }
  
  for (int j = 1 + count ; j < taille ; j++)
    for (int i = 0 ; i < taille ; i++) {
      tamp = 0;
      if (a[i] < pos[i - 1] && a[i] > tamp) {
	pos[j] = i;
	tamp = a[i];
      }
    }

  cout << "Tab apres le tri (2) : " ;
  for (int i = 0 ; i < taille ; i++)
    cout << tab[pos[i]] << " ";
  cout << endl;
}
   

void echanger(int t[], int i, int j) {
  int x = t[i];
  t[i] = t[j];
  t[j] = x;
}


/*void Comparer(int tab[], int taille, int pos[]) {
  for (int g = 0 ; g < taille ; g++)
    pos[g] = 0;

  cout << "Indices avant le tri : ";
  afficherTab(pos, pos + taille);

  for (int i = 0 ; i < taille ; i++)
    for (int j = 0 ; j < taille ; j++)
      if (tab[i] > tab[j]) 
      pos[i]+=1;
      
	
  cout << "Indices apres le tri : ";
  afficherTab(pos, pos + taille);

  cout << "Tab apres le tri : ";
  for (int k = 0 ; k < taille ; k++)
    for (int h= 0; h<taille; h++)
      if (pos[h] == k)
      cout << tab[h] << " ";
  cout << endl;
  
  */
 /* void Comparer(int tab[], int taille, int  pos[]) {
  int m=0;

  for (int i = 0 ; i < taille ; i++)
  {for (int j = 0 ; j < taille ; j++)
      if (tab[i] > tab[j]) 
      m++;
  pos[m]=i;
  m=0;}
	
  cout << "Indices apres le tri : ";
  afficherTab(pos, pos + taille);

  cout << "Tab apres le tri : ";
  for (int k = 0 ; k < taille ; k++)
    cout << tab[pos[k]] << " ";
  cout << endl;

}*/
  void Comparer(int tab[], int taille, int  pos[]) {
  int m=0, n=0;
  int * ptr[taille] ;

  for (int i = 0 ; i < taille ; i++)
  {
    for (int j = 0 ; j < taille ; j++)
    {
      if (tab[i] > tab[j]) 
	m++;
      if (tab[i] == tab [j])
	n++;
    }
    n--;
    for (int h=0;h<=n;h++)
      ptr[m+h]=tab+i;
    m=0;
    n=0;
  }
	
   cout << "Tab apres le tri : ";
  for (int k = 0 ; k < taille ; k++)
    cout << *ptr[k] << " ";
  cout << endl;

}


int main() {
  const int MAX = 5;

  int t[MAX];

  saisirTab(t, t + MAX);
  afficherTab(t, t + MAX);

  int  indice[MAX];
  Comparer(t, MAX, indice);
}
