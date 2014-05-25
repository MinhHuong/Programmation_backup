#include "Enseignant.h"

Enseignant::Enseignant() 
  : Personne()
{
  my_matiere = my_groupe = "";
}

Enseignant::Enseignant(string matiere, string groupe, string nom, string prenom, int age) 
  : Personne(nom,prenom,age),
    my_matiere(matiere),
    my_groupe(groupe)
{ }

Enseignant::Enseignant(const Enseignant &e) 
  : Personne(e)
{
  my_matiere = e.my_matiere;
  my_groupe = e.my_groupe;
}

void Enseignant::setMatiere(string matiere) {
  my_matiere = matiere;
}

void Enseignant::setGroupe(string groupe) {
  my_groupe = groupe;
}

string Enseignant::getMatiere() const {
  return my_matiere;
}

string Enseignant::getGroupe() const {
  return my_groupe;
}

void Enseignant::quiSuisJe() const {
  Personne::quiSuisJe();
  cout << "J'enseigne " << my_matiere << " et je fais partie du groupe " << my_groupe << endl;
}
