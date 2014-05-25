#ifndef SECRETAIRE_H
#define SECRETAIRE_H
#include <string>
#include <iostream>
#include "Employe.h"

class Secretaire : public Employe {
 private:
  double salaire_sec;
  
 public:
  Secretaire();
  Secretaire(string,int);
  ~Secretaire();

  void set_salaire(double);
  virtual std::string get_type() const;
};

#endif
