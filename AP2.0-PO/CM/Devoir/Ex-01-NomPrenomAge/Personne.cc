#include "Personne.h"

Personne::Personne() {
  my_nom = my_prenom = "";
  my_age = new int;
  *my_age = -1;
}

Personne::Personne(string nom, string prenom, int age) 
{
  my_prenom = prenom;
  my_nom = nom;
  my_age = new int;
  *my_age = age;
}

Personne::~Personne() {
  cout << "Personne : destructeur" << endl;
}

Personne::Personne(const Personne &p) {
  my_nom = p.my_nom;
  my_prenom = p.my_prenom;
  my_age = p.my_age;
}

void Personne::setAge(int age) {
  my_age = new int;
  *my_age = age;
}

void Personne::setPrenom(string prenom) {
  my_prenom = prenom;
}

void Personne::setNom(string nom) {
  my_nom = nom;
}

void Personne::initialise(string nom,
			  string prenom,
			  int age) {
  my_nom = nom;
  my_prenom = prenom;
  my_age = new int;
  *my_age = age;
}

int Personne::getAge() {
  return *my_age;
}

string Personne::getPrenom() {
  return my_prenom;
}

string Personne::getNom() {
  return my_nom;
}

void Personne::quiSuisJe() {
  cout << "Je suis " << my_prenom << " " << my_nom << endl;
  cout << "J'ai " << *my_age << " ans" << endl;
}
