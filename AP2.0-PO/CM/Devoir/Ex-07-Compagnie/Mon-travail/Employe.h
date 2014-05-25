#ifndef EMPLOYE_H
#define EMPLOYE_H
#include <iostream>
#include <string>
using namespace std;

class Employe {
 private:
  string my_nom;
  int my_age;
  string my_poste;

 public:
  Employe();
  Employe(string, int, string);
  ~Employe();

  void setEmploye(string, int, string);
  void travailler();
};

#endif
