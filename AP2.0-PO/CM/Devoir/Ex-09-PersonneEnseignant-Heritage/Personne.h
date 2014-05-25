#ifndef PERSONNE_H
#define PERSONNE_H
#include <iostream>
#include <string>
using namespace std;

class Personne {
 protected:
  string my_nom;
  string my_prenom;
  int my_age;

 public:
  Personne(); 
  Personne(string nom, string prenom, int age);
  Personne(const Personne &p);

  void setAge(int age);
  void setPrenom(string prenom);
  void setNom(string nom);
  int getAge() const;
  string getPrenom() const;
  string getNom() const;
  virtual void quiSuisJe() const;
};

#endif
