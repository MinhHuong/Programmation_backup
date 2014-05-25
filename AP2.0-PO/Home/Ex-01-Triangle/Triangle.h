#ifndef TRIANGLE_H
#define TRIANGLE_H
#include <iostream>

class Triangle {
 private:
  float a,b,c;
  
 public:
  Triangle();
  void saisir();
  void afficher();
  bool verifier();
  void classifier();
  float Perimetre() const;
  float Aire() const;
};

#endif
