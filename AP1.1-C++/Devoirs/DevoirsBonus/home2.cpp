#include <iostream>
#include <cstdlib>
#include <unistd.h>
#include <math.h>
#include <stdio.h>
#include <termios.h>
using namespace std;

/*****************************************************************************************************************/

/* ============================================= DE EXALGO A C++ =============================================== */

/*****************************************************************************************************************/

/* ECRIRE 1 FONCTION CALCULANT LA SOMME D'UNE SUITE D'ENTIERS TERMINEE PAR ZERO, PUIS ECRIRE 1 ACTION PRINCIPALE 

int Somme () {
  int nombre;
  cout << "Entrez 1 nombre = " ; cin >> nombre;
  
  int somme = 0;
  while (nombre != 0) {
    somme += nombre;
    cout << "Entrez 1 autre nombre (entrez 0 pour terminer) = "; 
    cin >> nombre;
  }

  return somme;
}


int main() {
  int somme;
  cout << "La somme = " << Somme() << endl;
}
*/
    
/*****************************************************************************************************************/

/* 1 PROGRAMME  QUI ETANT DONNE 1 ENTIER N DEMANDE A L'UTILISATEUR DE SAISIR N ENTIERS & RETOURNE LA SOMME 

int SommeWhile (int n) {
  int nombre, somme = 0;

  int i = 1;
  while (i <= n) {
    cout << "Entrez le nombre : "; 
    cin >> nombre;
    somme += nombre;
    i++;
  }

  return somme;
}


int main() {
  int nb;
  cout << "Entrez le nombre des entiers saisis : " ; cin >> nb;
  
  cout << "La somme de ces nombres = " << SommeWhile(nb) << endl;
} 
*/
   
/*****************************************************************************************************************/

/* 1  PROGRAMME  QUI ETANT DONNE 1 ENTIER N DEMANDE A L'UTILISATEUR DE SAISIR N ENTIERS & RETOURNE LA SOMME 

int SommeFor (int n) {
  int nombre;
  int somme = 0;
  
  for (int i = 1 ; i <= n ; i++) {
    cout << "Entrez 1 nombre : " ; 
    cin >> nombre;
    somme += nombre;
  }

  return somme;
}


int main() {
  int nb;
  cout << "Entrez le nombre des entiers saisis : " ; 
  cin >> nb;
  
  cout << "La somme des entiers = " << SommeFor(nb) << endl;
}
*/

/*****************************************************************************************************************/

/* ECRIRE 1 PROGRAMME QUI FAIT AFFICHER DES ALUMETTES 

void Affichage (int n) {
  for (int i = 1 ; i <= n ; i++)
    cout << '|' ;
  cout << endl;
}


int main() {
  int nb;
  cout << "Entrez le nombre des alumettes : " ; cin >> nb;
  Affichage(nb);
}
*/

/*****************************************************************************************************************/

/* ECRIRE 1 PROGRAMME QUI CALCULE LA PUISSANCE X^N SANS UTILISER POW(X,N) 

double Puissance (double x, double n) {
  double puissance = 1;

  if (n > 0) {   
    for (int i = 1 ; i <= n ; i++)
      puissance *= x;
  }

  else {
    for (int i = -1 ; i >= n ; i--)
      puissance *= (1/x);
  }
 
  return puissance;
}


int main() {
  double x, n;
  cout << "Entrez x (> 0) : " ; cin >> x;
  cout << "Entrez n : " ; cin >> n;

  double resultat;
  cout << "Le resultat = " << Puissance(x,n) << endl;
}
*/

/*****************************************************************************************************************/

/* 1 PROGRAMME CALCULANT LA SOMME DES PUISSANCES 1 + X^1 + X^2 + ... X^N 

double SommePuissance (double x, double n) {
  double sommeP = 1;
  double puissance = 1;

  for (int i = 1 ; i <= n ; i++) {
    puissance *= x;
    sommeP += puissance;
  }

  return sommeP;
}

int main() {
  double x, n;
  cout << "Entrez x (> 0) : " ; cin >> x;
  cout << "Entrez n (> 0) : " ; cin >> n;
  
  cout << "Le resultat = " << SommePuissance(x,n) << endl;
}
*/

/*****************************************************************************************************************/

/* MEME EXERCICE MAIS ON UTILISE LA FORMULE DE HORNER

double Horner (double x, double n) {
  int sommeP = 0;
  
  for (int i = 1 ; i <= n ; i++)
    sommeP = (sommeP*x) + 1;

  return sommeP;
}


int main() {
  double x, n;
  cout << "Entrez x (> 0) : " ; cin >> x;
  cout << "Entrez n (> 0) : " ; cin >> n;

  cout << "Le resultat = " << Horner(x,n) << endl;
}
*/

/*****************************************************************************************************************/
/*****************************************************************************************************************/
/*****************************************************************************************************************/

/* ========================================= KY THUAT LAP TRINH ================================================ */

/* COMPARER L'AIRE DU CARRE & L'AIRE DU CERCLE, SI BIEN QUE LE RESULTAT AFFICHE SUR L'ECRAN SOIT VRAI OU FAUX 

int main() {
  double cote, rayon, aCarre, aCercle;

  cout << "Entrez le cote & le rayon pour que l'aire du Carre soit superieure ou egale a l'aire du Cercle" << endl;
  cout << "Entrez le cote : "  ; cin >> cote;
  cout << "Entrez le rayon : " ; cin >> rayon;

  aCarre = cote * cote;
  aCercle = rayon * rayon * 3.14;

  bool comparer = true; // aCarre >= aCercle
  
  if (aCarre < aCercle)
    comparer = false;

  /*if (comparer == true)
    cout << "Vrai" << endl;
  else if (comparer == false)
  cout << "Faux" << endl;

  switch (comparer) {
  case true :
    cout << "Vrai" << endl;
    break;
  case false :
    cout << "Faux" << endl;
    break;
  }
}
*/

/*****************************************************************************************************************/

/* CALCULER LA FACTORIELLE 
int main() {
  int fact = 1, N;
  cout << "Entrez N = " ; cin >> N;
  
  for (int i = 1 ; i <= N ; i++)
    fact *= i;

  cout << "Le resultat fact(" << N << ") = " << fact << endl;
}
*/

/*****************************************************************************************************************/

/* GIAI THUAT EUCLID TIM UOC SO CHUNG NHO NHAT & BOI SO CHUNG LON NHAT 

int USCLN (int x, int y) {
  int r;  

  if (x % y == 0) 
    r = y;
  else 
    r = USCLN (y, x % y);

  return r;
}

 
int main() {
  int a, b;
  cout << "Entrez a = " ; cin >> a;
  cout << "Entrez b = " ; cin >> b;

  if (a > b) { 
    cout << "USCLN = " << USCLN(a,b) << endl;
    cout << "BSCNN = " << a*b/USCLN(a,b) << endl; 
  }
  else {
    cout << "USCLN = " << USCLN(b,a) << endl;
    cout << "BSCLN = " << a*b/USCLN(b,a) << endl;
  }
}
*/

/*****************************************************************************************************************/

/*
int main() {
  int N, max, min;
  cout << "Entrez le nombre des entiers : " ; cin >> N;
  int t[N];

  for (int i = 1 ; i <= N ; i++) {
    cout << "t[" << i << "] = " ;
    cin >> t[i];

    max = min = t[1];
    
    for (int j = 2 ; j <= N ; j++) {
      if (max < t[j])
	max = t[j];
      if (min > t[j])
	min = t[j];
    }
  }
  cout << "max = " << max << endl;
  cout << "min = " << min << endl;
}
*/

/*****************************************************************************************************************/

/*int main() {
  double x0, y0, xA, yA, R;
  double OA;

  cout << "Entrez les coordonnees du centre 0 du cercle & le rayon : " ; cin >> x0 >> y0 >> R;
  cout << "Entrez les coordonnees du point A : " ; cin >> xA >> yA;
  
  OA = sqrt(pow(x0 - xA,2) + pow(y0 - yA,2));

  if (OA == R)
    cout << "A est sur le cercle" << endl;
  else if (OA > R)
    cout << "A est a l'exterieur du cercle" << endl;
  else
    cout << "A est a l'interieur du cercle" << endl;
}
*/

/*****************************************************************************************************************/

/*
int Test (int & num) { //parametre par valeur (tham so gia tri)
  num = 0;
  cout << "num = " << num << endl;
}

int main() {
  int x = 10;
  Test(x); //num est 1 variable par valeur alors elle n'affecte pas a x dans le main();
  cout << "x = " << x << endl;
}
*/

/*****************************************************************************************************************/

/*
int x = 2;

int Test (int x) { //x o day la THAM SO
  x = 10;
  return x;
}

int main() {
  Test(x); //x o day la DOI SO
  cout << x << endl;
}
*/

/*****************************************************************************************************************/

/*
int Fact(int n) {
  return n == 0 ? 1 : n * Fact(n - 1);
}

int Fib(int n) {
  return (n == 0 || n == 1) ? 1 : Fib(n - 1) + Fib(n - 2);
}

int main() {
  int N;
  cout << "Entrez N : ";
  cin >> N;
  cout << "fact(" << N << ") = " << Fact(N) << endl;
  cout << "fib(" << N << ") = " << Fib(N) << endl;
}
*/

/*****************************************************************************************************************/

/*
int Test (int a = 0) { //doi so MAC DINH
  cout << "a = " << a << endl;
  return a;
}

int main() {
  int x = 0;
  cout << Test(x) << endl;
  cout << Test(3) << endl;
}
*/

/*****************************************************************************************************************/

/*int main() {
  int a;
  cin >> a;
  cout << "a = " << a << " et l'adresse de a = " << &a << endl;
}
*/

/*
int main() {
  int t = 9;
  cout << sizeof(t) << endl;
  char a='o';
  cout << sizeof(a) << endl;
}
*/

/*
int main() {
  cout << "sizeof(char) = " << sizeof(char) << endl
       << "sizeof(int) = " << sizeof(int) << endl
       << "sizeof(short) = " << sizeof(short) << endl
       << "sizeof(float) = " << sizeof(float) << endl
       << "sizeof(double) = " << sizeof(double) << endl
       << "sizeof(long int) = " << sizeof(long int) << endl;
}
*/

/*
int main() {
  float nb = 100.2;
  int NB;
  NB = int(nb);
  cout << "nb = " << nb << "\nNB = " << NB << endl;
}
*/

/*
int main() {
  char name[] = "Elise";
  char *adrName;
  adrName = &name[0];

  cout << "The string is : " << endl;
  while (*adrName != '\0') {
    cout << *adrName << ' ';
    adrName++;
  }
  cout << endl;
}
*/

/*****************************************************************************************************************/

//KARAOKE yeah phac du

/*
float Calculer (int debut, int fin) {
  float depense, bonus = 0.0;
  int duree;
  
  duree = fin-debut;
  if (duree <= 3) 
    depense = 30.0*duree;
  else {
    for (int i = 1 ; i <= duree-3; i++)
      bonus = bonus + 30*pow(0.7,i); 
    depense = 30.0*3.0 + bonus;
  }
  
  if (debut >= 8 && fin <= 17)
    depense *= 0.9;
  
  return depense;
}

int main() {
  int heureDeb, heureFin;
  bool check = false;
  while (check == false) {
    cout << "Heure du debut et a la fin : " ; cin >> heureDeb >> heureFin;
    if (heureDeb < 8 || heureFin > 24) 
      cout << "Erreur saisie, veuillez verifier l'heure du debut/a la fin" << endl;
    else
      check = true;
  }
  
  cout << "La somme = " << Calculer(heureDeb, heureFin)*10E2 << endl;
  return EXIT_SUCCESS;
}
*/

/******************************************************************************************************************/

//RESOUDRE UNE EQUATION DU SECOND DEGRE EN UTILISANT LE POINTEUR

/*
int resoudre (float a, float b, float c, float *x1, float *x2) {
  float delta;

  if (a == 0) return 0;

  delta = b*b-4*a*c;  
  if (delta < 0) return -1;

  *x1 = (-b + sqrt(delta))/2*a;
  *x2 = (-b - sqrt(delta))/2*a;
  return 1;
}


int main() {
  float a, b, c, x1, x2;
  cout << "Entrez a, b, c : "; cin >> a >> b >> c;
  
  int check;
  check = resoudre(a, b, c, &x1, &x2);
  if (check == 0)
    cout << "a = 0, ce n'est pas une equation du second degre \n";
  else if (check == -1)
    cout << "Delta < 0, alors cette equation n'a pas de solution \n";
  else {
    cout << "x1 = " << x1 << endl
	 << "x2 = " << x2 << endl;
  }
}
*/


/*
int main() {
  int tab[5] = {5, 6, 7, 8, 9};
  
  cout << *(tab+4) << endl;
}
*/

void saisirTab(int *deb, int *fin) {
  cout << "Entrez 5 nombres : \n";
  while (deb != fin) {
    cin >> *deb;
    deb++;
  }
}

void afficherTab(int *deb, int *fin) {
  cout << "Tab : ";
  while (deb != fin) {
    cout << *deb << ' ';
    deb++;
  }
  cout << endl;
}

int main() {
  int tab[5];
  int *adrDeb = tab, *adrFin = tab+5;

  //saisirTab(adrDeb, adrFin);
  //afficherTab(adrDeb, adrFin);

  saisirTab(tab, tab+5);
  afficherTab(tab, tab+5);
}
