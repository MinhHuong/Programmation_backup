#ifndef PERSONNE_H
#define PERSONNE_H
#include <iostream>
#include <string>
using namespace std;

class Personne {
 private:
  string my_nom;
  string my_prenom;
  int *my_age;

 public:
  Personne(); 
  Personne(string nom, string prenom, int age);
  Personne(const Personne &p);
  ~Personne();
  void setAge(int age);
  void setPrenom(string prenom);
  void setNom(string nom);
  void initialise(string nom, string prenom, int age);
  int getAge();
  string getPrenom();
  string getNom();
  void quiSuisJe();
};

#endif
