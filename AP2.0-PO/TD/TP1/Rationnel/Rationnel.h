#ifndef RATIONEL_H
#define RATIONEL_H
#include <iostream>
#include <string>
//#include <sstream>
#include "util.h"
using namespace std;

class Rationnel {
 private:
  int my_num;
  int my_deno;

 public:
  Rationnel();
  Rationnel(int num, int deno);

  void affiche();
  void setNum(int num);
  void setDeno(int deno);

  void inverse();
  bool egal(Rationnel r) const;

  void plus(const Rationnel & r, Rationnel & s) const;
  void moins(const Rationnel & r, Rationnel & d) const;
  void fois(const Rationnel & r, Rationnel & p) const;
  void diviser(const Rationnel & r, Rationnel & q) const;

  int getNum() const;
  int getDeno() const;

  void reduit();
  string toString_reduit();
  string toString_normal() const;
  
};

#endif
