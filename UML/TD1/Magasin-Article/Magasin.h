#ifndef MAGASIN_H
#define MAGASIN_H
#include <iostream>
#include <string>
#include <vector>
#include <typeinfo>
#include "Employe.h"
#include "Article.h"
#include "PrixArticle.h"
using namespace std;

class Employe;
class PrixArticle;

class Magasin {
 private:
  int numMag;
  static int nombreMagasins;
  string nomMag;
  string adrMag;
  Employe * dirigeant;
  vector <Employe*> v_E;
  vector <PrixArticle*> v_A;

 public:
  Magasin(string, string);
};

#endif
