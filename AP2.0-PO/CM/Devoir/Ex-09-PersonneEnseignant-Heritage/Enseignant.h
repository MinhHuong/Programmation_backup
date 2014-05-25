#ifndef ENSEIGNANT_H
#define ENSEIGNANT_H
#include <iostream>
#include <string>
#include "Personne.h"
using namespace std;

class Enseignant : public Personne {
 private:
  string my_matiere;
  string my_groupe;

 public:
  Enseignant();
  Enseignant(string, string, string, string, int);
  Enseignant(const Enseignant &);
  
  void setMatiere(string);
  void setGroupe(string);

  string getMatiere() const;
  string getGroupe() const;

  virtual void quiSuisJe() const;
};

#endif
