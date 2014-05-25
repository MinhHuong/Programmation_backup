#ifndef EMPLOYE_H
#define EMPLOYE_H
#include <iostream>
#include <string>
#include <vector>
#include "Magasin.h"
using namespace std;

class Magasin;

class Employe {
 private:
  int numEmpl;
  string nomEmpl;
  string adrEmpl;
  string telEmpl;
  string emailEmpl;
  Magasin * lieu;
  static int ID;

 public:
  Employe();
  bool estDirigeant();
};

#endif
