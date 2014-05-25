#include "Personne.h"

Personne::Personne() {
  my_nom = my_prenom = "";
  my_age = -1;
}

Personne::Personne(string nom, string prenom, int age) 
{
  my_prenom = prenom;
  my_nom = nom;
  my_age = age;
}

Personne::Personne(const Personne &p) {
  my_nom = p.my_nom;
  my_prenom = p.my_prenom;
  my_age = p.my_age;
}

void Personne::setAge(int age) {
  my_age = age;
}

void Personne::setPrenom(string prenom) {
  my_prenom = prenom;
}

void Personne::setNom(string nom) {
  my_nom = nom;
}

int Personne::getAge() const {
  return my_age;
}

string Personne::getPrenom() const {
  return my_prenom;
}

string Personne::getNom() const {
  return my_nom;
}

void Personne::quiSuisJe() const {
  cout << "Je suis " << my_prenom << " " << my_nom << endl;
  cout << "J'ai " << my_age << " ans" << endl;
}
