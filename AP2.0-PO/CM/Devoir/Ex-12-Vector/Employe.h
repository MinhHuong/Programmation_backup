#ifndef EMPLOYE_H
#define EMPLOYE_H
#include <string>
#include <iostream>
using namespace std;

class Employe {
 private:
  string nom_emp;
  int age_emp;
  
 public:
  Employe();
  Employe(string, int);
  ~Employe();
  virtual string get_type() const;
};

#endif
