#ifndef DATE_H
#define DATE_H
#include <iostream>
using namespace std;

class Date {
 private:
  int *jour;
  int *mois;
  int *annee;

 public:
  Date();
  Date(int j, int m, int a);
  Date(const Date &d);

  ~Date();

  void setDate(int j, int m, int a);
  void afficherDate();
  int getJour();
  int getMois();
  int getAnnee();
};

#endif
