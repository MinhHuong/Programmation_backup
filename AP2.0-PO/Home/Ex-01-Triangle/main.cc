#include "Triangle.h"
#include <cstdlib>
using namespace std;

int main() {
  Triangle tri;
  tri.saisir();
  if (tri.verifier())
    cout << "Ce triangle est constructible" << endl;
  else {
    cout << "On ne peut pas construire ce triangle" << endl;
    exit(-1);
  }
  tri.afficher();
  tri.classifier();
  cout << "Perimetre = " << tri.Perimetre() << endl;
  cout << "Aire = " << tri.Aire() << endl;
  

  return 0;
}
