#include <iostream>
#include <math.h>
#include <cstdlib>
#include <unistd.h>
using namespace std;

/******************************************** DIDACTICIEL DE CALCUL ************************************************/

/*
void afficherMenu() {
  cout << "MENU A EXECUTER : \n \n"
       << "1. Exercice sur l'addition" << endl
       << "2. Exercice sur la soustraction" << endl
       << "3. Exercice sur la multiplication" << endl
       << "4. Exercice sur la division \n \n";
}


void genOperande(int & a, int & b) {
  srand(time(NULL));
  a = (int) (20.0 * rand() / RAND_MAX);
  b = (int) (20.0 * rand() / RAND_MAX);
}


void devinerResultat(int result) {
  int resultat;

  cout << "Quel est le resultat : ";
  cin >> resultat;

  if (result == resultat) 
    cout << "Gagne" << endl;
  else {
    cout << "Perdu" << endl;
    cout << "Le resultat est : " << result << endl;
  }
}
  

int main() {
  afficherMenu();

  int a, b;
  genOperande(a, b);

  char choix;
  cout << "Votre choix : ";
  cin >> choix;  

  int result;

  switch (choix) {
  case '1' :
    result = a + b;
    break;
  case '2' :
    result = a - b;
    break;
  case '3' :
    result = a * b;
    break;
  case'4' :
    if (b != 0)
      result = a / b;
    else {
      cout << "b = 0, impossible d'effectuer la dividion" << endl;
      exit(0);
    }
    break;
  default :
    cout << "Erreur saisie" << endl;
    exit(0);
  }

  devinerResultat(result);
}
*/


/********************************** TIM UOC CHUNG LON NHAT & BOI CHUNG NHO NHAT ************************************/

/*
int UCLN(int x, int y) {
  int r;
  
  if (x % y == 0)
    r = y;
  else
    r = UCLN(y, x % y);

  return r;
}


int main() {
  int a, b;
  cout << "Entrez a = "; cin >> a;
  cout << "Entrez b = "; cin >> b;

  if (a > b) {
    cout << "Uoc chung lon nhat = " << UCLN(a, b) << endl;
    cout << "Boi chung nho nhat = " << a*b/UCLN(a, b) << endl;
  }
  else {
    cout << "Uoc chung lon nhat = " << UCLN(b, a) << endl;
    cout << "Boi chung nho nhat = " << a*b/UCLN(b, a) << endl;
  }
}
*/

/***************************************** AFFICHER N PREMIERS ENTIERS  ********************************************/

void afficher(int n) {
  int i = 0;

  while (i <= n) {
    cout << i << endl;
    i++;
  }
}


int main() {
  int N;
  cout << "Entrez N = "; cin >> N;
  afficher(N);
}
  


  


