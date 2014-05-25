#include <iostream>
#include <stdexcept>
#include <string>
using namespace std;

double fonction1(double x, double y) 
  throw (logic_error)
{
  if (x == y) {
    logic_error description("Division par zero");
    throw description;
  }
  return ((x+y)/(x-y));
}

void fonction2() {
  char c;
  int x,y;
  bool arret = false;
  while (!arret) {
    cout << "Entrez les valeurs x et y : "; cin >> x >> y;
    try {
      cout << fonction1(x,y) << endl;
    }
    catch (logic_error & e) {
      cout << "Erreur : " << e.what() << endl;
    }
    cout << "Voulez-vous continuer ? : ";
    cin >> c;
    arret = (c != 'o');
  }
}

int main() {
  fonction2();
}
