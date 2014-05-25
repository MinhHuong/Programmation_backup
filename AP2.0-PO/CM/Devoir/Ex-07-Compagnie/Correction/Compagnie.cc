#include "Compagnie.h"

Compagnie::Compagnie() 
  : employe(NULL),
    siege("Non renseigne")
{
  cout << "Compagnie : constructeur par defaut" << endl;
}

Compagnie::Compagnie(string nom) 
  : siege(nom) 
{
  cout << "Compagnie : constructeur avec parametre" << endl;
  nb_employe = 0;
  employe = NULL;
}

Compagnie::~Compagnie() {
  cout << "Compagnie : destructeur" << endl;
  if (employe != NULL)
    delete [] employe;
}

int Compagnie::getNbEmploye() const {
  return nb_employe;
}

void Compagnie::embaucher(Employe e) {
  Employe * temp;
  nb_employe++;

  if (employe == NULL)
    employe = new Employe[1];

  temp = new Employe[nb_employe];

  for (int i = 0; i < nb_employe-1; i++)
    temp[i] = employe[i];

  temp[nb_employe-1] = e;

  delete [] employe;

  employe = new Employe[nb_employe];

  for (int i = 0; i < nb_employe; i++)
    employe[i] = temp[i];
}

void Compagnie::ListeEmploye() {
  for (int i = 0; i < nb_employe; i++)
    employe[i].travailler();
}
