#include "Employe.h"
using namespace std;

Employe::Employe() {
  my_id = my_nom = ' ';
  my_salaire = 0.0;
}

void Employe::saisir() {     
  string nom,id;
  float salaire;

  cout << "Le nom de l'employe : ";
  cin >> nom;
  my_nom = nom;

  cout << "Son numero ID : ";
  cin >> id;
  my_id = id;

  cout << "Son salaire : ";
  cin >> salaire;
  my_salaire= salaire;
}

void Employe::afficher() { 
  cout << "Je suis " << my_nom 
       << ", mon ID : " << my_id << endl;
  cout << "Mon salaire est de " << my_salaire 
       << " et le bonus : " << bonus() << endl;
}

float Employe::bonus() { }
