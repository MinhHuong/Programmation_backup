#include "Employe.h"
#include "Vendeur.h"
#include "Bureau.h"
#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
using namespace std;

int main() {
  vector<Employe*> emp;
  
  Employe* e1 = new Vendeur;
  emp.push_back(e1);

  Employe* e2 = new Bureau;
  emp.push_back(e2);

  for (int i = 0 ; i < emp.size() ; i++) {
    emp[i]->saisir();
    emp[i]->afficher();
    cout << endl;
  }
  

  return 0;
}


