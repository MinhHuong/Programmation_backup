#include "Bureau.h"
#include <iostream>
#include <string>
using namespace std;

Bureau::Bureau() {
  my_temps = 0.0;
}

void Bureau::saisir() {
  Employe::saisir();
  
  float t;
  cout << "Le temps de travailler (en mois) : ";
  cin >> t;
  my_temps = t;
}

void Bureau::afficher() {
  Employe::afficher();
  cout << "J'ai travaille depuis " << my_temps << " mois" << endl;
}

float Bureau::bonus() {
  if (my_temps < 6)
    return 100000;
  else
    return (200000 + my_salaire*0.1*my_temps/6);
}
