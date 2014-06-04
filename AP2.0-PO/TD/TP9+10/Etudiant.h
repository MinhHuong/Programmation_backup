#ifndef ETUDIANT_H
#define ETUDIANT_H

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <ctype.h>

using namespace std;

class Etudiant
{
 private:
  float m_note;
  string m_nom;

 public:
  Etudiant();
  ~Etudiant();
  Etudiant(string nom, float note);
  Etudiant(const Etudiant &etud);
  Etudiant &operator= (const Etudiant &etud);
  
  string nom() const;
  float note() const;

  void saisie();

  void lireFlux( fstream & f );
  void ecrireFlux( fstream & f );
};

ostream & operator<<(ostream &os, const Etudiant &e);

#endif

