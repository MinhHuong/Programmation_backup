#ifndef OPERATION_H
#define OPERATION_H
#include <iostream>
using namespace std;

class Entier {
 private:
  int nb_1;
  int nb_2;

 public:
  Entier();
  Entier(int, int);
  void init(int op1, int op2);
  void plus();
  void moins();
  void fois();
  void diviser();
  Entier operator+(const Entier &e);
  int getValue_1();
  int getValue_2();
};

#endif

