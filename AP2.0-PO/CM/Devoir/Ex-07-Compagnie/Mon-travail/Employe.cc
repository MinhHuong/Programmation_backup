#include "Employe.h"

Employe::Employe() 
  : my_nom("Non renseigne"),
    my_age(-1),
    my_poste("Non renseigne") 
{
  cout << "Employe : constructeur par defaut" << endl;
}

Employe::Employe(string nom, int age, string poste) 
  : my_nom(nom), my_age(age), my_poste(poste)
{
  cout << "Employe : constructeur avec parametre" << endl;
}

Employe::~Employe() {
  cout << "Employe : destructeur" << endl;
}

void Employe::setEmploye(string nom, int age, string poste) {
  my_nom = nom;
  my_age = age;
  my_poste = poste;
}

void Employe::travailler() {
  cout << "Je suis " << my_nom << ", " << my_age << " ans, et je vais travailler pour le poste " << my_poste << endl;
}
