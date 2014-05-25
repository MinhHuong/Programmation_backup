#ifndef DATE_H
#define DATE_H
#include <iostream>
using namespace std;

class Date {
 private:
  int * jour;
  int * mois;
  int * annee;

 public:
  Date();
  Date(int, int, int);
  ~Date();

  void setDate(int, int, int);
  void afficherDate();
};

#endif
