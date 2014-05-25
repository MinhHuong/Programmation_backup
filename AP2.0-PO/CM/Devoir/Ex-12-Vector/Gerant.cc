#include "Gerant.h"
using namespace std;

Gerant::Gerant() {
  lieu_diriger = "";
}

Gerant::Gerant(string nom, int age)
  : Employe(nom,age) { }

Gerant::~Gerant() { }

void Gerant::set_lieu(string lieu) {
  lieu_diriger = lieu;
}

string Gerant::get_type() const {
  return "Gerant";
}
