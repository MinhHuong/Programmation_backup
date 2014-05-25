#ifndef GERANT_H
#define GERANT_H
#include <string>
#include <iostream>
#include "Employe.h"

class Gerant : public Employe {
 private:
  string lieu_diriger;
  
 public:
  Gerant();
  Gerant(string,int);
  ~Gerant();

  void set_lieu(string);
  virtual string get_type() const;
};

#endif
