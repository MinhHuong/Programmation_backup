#include "Gerant.h"
#include "Employe.h"

int main() {
  Employe e1("Bee",1500);
  Gerant g1("Cecil",2000);
  cout << g1.getNbEmploye() << endl;
  g1.ajouter();
  cout << g1.getNbEmploye() << endl;

  cout << e1.getSalaire() << endl;
  cout << g1.getSalaire() << endl;
  cout << g1.getNom() << endl;
m
  return 0;
}
