#include "Employe.h"
using namespace std;

Employe::Employe() {
  nom_emp = "";
  age_emp = -1;
}

Employe::Employe(string nom, int age) {
  nom_emp = nom;
  age_emp = age;
}

Employe::~Employe() { }

string Employe::get_type() const {
  return "Employe";
}
