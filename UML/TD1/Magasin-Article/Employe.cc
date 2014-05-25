#include "Employe.h"
using namespace std;

int Employe::ID = 0;

Employe::Employe() {
  ID++;
  numEmpl = ID;
  lieu = NULL;
  nomEmpl = adrEmpl = telEmpl = emailEmpl = "";
}

bool Employe::estDirigeant() {
 
}
