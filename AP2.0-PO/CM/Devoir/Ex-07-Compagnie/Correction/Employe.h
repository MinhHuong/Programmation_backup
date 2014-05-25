#ifndef EMPLOYE_H
#define EMPLOYE_H
#include <iostream>
#include <string>
using namespace std;

class Employe {
 private:
  string nom_;

 public:
  Employe();
  Employe(string);
  ~Employe();

  void setNom(string);
  void travailler() const;
};

#endif
