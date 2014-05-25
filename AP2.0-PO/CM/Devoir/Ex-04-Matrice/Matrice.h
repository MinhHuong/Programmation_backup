#ifndef MATRICE_H
#define MATRICE_H
#include <iostream>
using namespace std;

class Matrice {
 private:
  unsigned rows_, cols_;
  double *data_;

 public:
  Matrice(unsigned rows, unsigned cols);
  double operator() (const unsigned row, const unsigned col);
  double operator() (const unsigned row, const unsigned col) const;
  ~Matrice();
  Matrice(const Matrice &m);
  Matrice& operator=(const Matrice& m);
};

#endif
