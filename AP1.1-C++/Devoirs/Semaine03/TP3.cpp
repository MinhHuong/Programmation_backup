#include <iostream>
#include <math.h>
#include <cstdlib>
#include <unistd.h>
using namespace std;

/**********************************************----- EXERCICE 1 -----**********************************************/

//ECRIRE 1 PROGRAMME QUI DEMANDE A L'UTILISATEUR D'ENTRER 1 ENTIER & QUI AFFICHE SI CET ENTIER EST PAIR OU IMPAIR

/*
int main() {
  int nb;
  bool run = true;

  while (run) {
    cout << "Entrez 1 nombre entier : ";
    cin >> nb;

    if (nb % 2 == 0)
      cout << nb << " est pair" << endl;
    else
      cout << nb << " est impair" << endl;
  }
}
*/
  
/**********************************************----- EXERCICE 2 -----**********************************************/

//ECRIRE 1 FONCTION QUI DEMANDE A L'UTILISATEUR D'ENTRER 1 ENTIER TANT QUE CE DERNIER EST DIFFERENT DE 0 & QU'ILE AFFICHE LA SOMME & LA MOYENNE DE CES ENTIERS ENTRES

/*
void SommeMoyenne(int n) {
  float somme, moyenne;
  int fois = -1; //fois = -1 si l'on ne compte pas 0 comme un entier a ajouter dans la somme

  while (n != 0) {
    cout << "Entrez 1 nombre entier (different de 0) : ";
    cin >> n;

    fois += 1;
    somme += n;
  }

  cout << "La somme = " << somme << endl;
  
  moyenne = somme/fois;
  cout << "La moyenne = " << moyenne << endl;
}  
 


int main() {
  int nb; 

  SommeMoyenne(nb);
}
*/

/**********************************************----- EXERCICE 3 -----**********************************************/

//ECRIRE 1 ACTION QUI DEMANDE A L'UTILISATEUR D'ENTRER 1 ENTIER POSITIF TANT QUE CELUI-CI EST PLUS GRAND QUE LE DERNIER NOMBRE ENTRE


void SuiteCroissante(int n) {
  int temp;
  bool run = true;
  int start = 0;

  while (run) {
    if (start == 0) {    
    cout << "Entrez 1 nombre entier positif : ";
    cin >> n;
    }

    if (n > 0) {
      temp = n;
      cout << "Entrez 1 nombre entier positif : ";
      cin >> n;
      if (n < temp) {
	cout << "Erreur saisie !" << endl;
	run = false;
      }
      start = 1;
    }

    else {
      cout << "Erreur saisie ! Entrez 1 nombre positif !" << endl;
      continue;
    }
  }
}

int main() {
  int nb;
  
  SuiteCroissante(nb);
}



/**********************************************----- EXERCICE 4 -----**********************************************/

/*
void Maximum(int n) {
  int max = -99999;

  while (n != 0) {
    cout << "Entrez 1 nombre entier (!= 0): ";
    cin >> n;
      
    if (n > max)
      max = n;
  }

  cout << "Le nombre maximum est : " << max << endl;
}

int main() {
  int nb;
  Maximum(nb);
}
*/

/**********************************************----- EXERCICE 5 -----**********************************************/
 
/* 
void echangeInt(int & a, int & b) {
  int t = a;
  a = b;
  b = t;
}

void echangeSansInt(int & a, int & b) { 
  a = a + b; //a' = a  + b
  b = a - b; //b' = a' - b  = (a + b) - b = a --> b = a
  a = a - b; //a  = a' - b' = (a + b) - a = b --> a = b
}

int main() {
  int x, y;
  cout << "Entrez x : "; cin >> x;
  cout << "Entrez y : "; cin >> y;
  cout << "Avant l'echange : x = " << x << " et y = " << y << endl;

  cout << "1er echange : " << endl;
  echangeInt(x, y);
  cout << "x = " << x << " et y = " << y << endl;

  cout << "2e echange : " << endl;
  echangeSansInt(x, y);
  cout << "x = " << x << " et y = " << y << endl;
}
*/

/**********************************************----- EXERCICE 6 -----**********************************************/

/*
void Minimum2() {
  int a, b;
  cout << "Entrez a = " ; cin >> a;
  cout << "Entrez b = " ; cin >> b;

  int min;

  if (a > b)
    min = b;
  else
    min = a;

  cout << "Le minimum = " << min << endl;
}


void Minimum4() {
  int a, b, c, d;
  cout << "Entrez a = " ; cin >> a;
  cout << "Entrez b = " ; cin >> b;
  cout << "Entrez c = " ; cin >> c;
  cout << "Entrez d = " ; cin >> d;

  int min;

  min = (a < b ? a : b);
  min = (min < c ? min : c);
  min = (min < d ? min : d);

  cout << "Le minimum = " << min << endl;
}


int main() {
  Minimum2();
  Minimum4();
}
*/

/**********************************************----- EXERCICE 7 -----**********************************************/

/*
void Temperatures() {
  int n;
  cout << "Entrez n (le nombre des temperatures saisies) = ";
  cin >> n;

  if (n <= 0) {
    cout << "Erreur saisie !" << endl;
    exit(0);
  }
  
  else {
    int temp, tempMax = -999, tempMin = 999, tempSom = 0;
    int fois = 0;

    for (int i = 0 ; i < n ; i++) {
      cout << "Entrez la temperature : ";
      cin >> temp;
    
      if (temp > tempMax) 
	tempMax = temp;
      if (temp < tempMin)
	tempMin = temp;

      tempSom += temp;

      fois += 1;
    }

    cout << "La temperature maximale est : " << tempMax << endl;
    cout << "La temperature minimale est : " << tempMin << endl;
    cout << "La temperature moyenne est : "  << (float) tempSom/fois << endl;
  }
} 
 

int main() {
  Temperatures();
}
*/

/**********************************************----- EXERCICE 8 -----**********************************************/

/*
void premierDegre(float a, float b) {
  if (a != 0) 
    cout << "L'equation a 1 seule solution : x = " << (-b)/a << endl;
  else {
    if (b == 0) 
      cout << "L'equation a un ensemble infini de solutions" << endl;
    else
      cout << "L'equation n'a pas de solutions" << endl;
  }
}


void secondDegre(float a, float b, float c) {
  int delta;

  if (a == 0) 
    premierDegre(b, c);
  else {
    delta = b*b - 4*a*c;
    if (delta > 0) 
      cout << "L'equation a 2 solutions distinctes : x1 = " << (-b + sqrt(delta))/(2*a)
	   << " et x2 = "                                   << (-b - sqrt(delta))/(2*a) 
	   << endl;  
    else if (delta == 0)
      cout << "L'equation a 1 seule solution : x = " << -b/(2*a) << endl;
    else
      cout << "L'equation n'a pas de solution" << endl;
  }
}

int main() {
  float a, b;
  cout << "Entrez a = " ; cin >> a;
  cout << "Entrez b = " ; cin >> b;
  
  premierDegre(a, b);

  float a1, b1, c1;
  cout << "Entrez a1 = " ; cin >> a1;
  cout << "Entrez b1 = " ; cin >> b1;
  cout << "Entrez c1 = " ; cin >> c1;
  secondDegre(a1, b1, c1);
}
*/  
