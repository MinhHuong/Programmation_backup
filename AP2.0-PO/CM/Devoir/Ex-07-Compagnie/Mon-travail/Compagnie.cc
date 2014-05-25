#include "Compagnie.h"

Compagnie::Compagnie()
  : my_siege("Non renseigne"),
    my_employes(NULL),
    date_fondation(NULL),
    nb_employe(0) 
{
  cout << "Compagnie : constructeur par defaut" << endl;
}

Compagnie::Compagnie(string pays, Date fondation) {
  cout << "Compagnie : constructeur avec parametre" << endl;

  nb_employe = 0;
  my_siege = Siege(pays);

  date_fondation = new Date;
  *date_fondation = fondation;

  my_employes = NULL;
}

Compagnie::~Compagnie() {
  cout << "Compagnie : destructeur" << endl;

  if (my_employes != NULL)
    delete [] my_employes;
  
  if (date_fondation != NULL)
    delete date_fondation;
}

int Compagnie::getNbEmploye() const {
  return nb_employe;
}

void Compagnie::embaucher(Employe e) {
  Employe * temp;
  nb_employe++;

  if (my_employes == NULL)
    my_employes = new Employe[1];

  temp = new Employe[nb_employe];

  for (int i = 0; i < nb_employe-1; i++)
    temp[i] = my_employes[i];  

  temp[nb_employe-1] = e;

  delete [] my_employes;

  my_employes = new Employe[nb_employe];
  
  for (int i = 0; i < nb_employe; i++)
    my_employes[i] = temp[i];
}

void Compagnie::licencier(Employe e) {
  
}

void Compagnie::promouvoir(Employe e) {

}

void Compagnie::ListeEmploye() {
  for (int i = 0; i < nb_employe ; i++)
    my_employes[i].travailler();
}

void Compagnie::informer() {
  cout << "La compagnie a " << nb_employe << " employes" << endl;

  cout << "Son siege se situe a " << my_siege.getPays() << endl;

  date_fondation->afficherDate();

  cout << "La liste des employes : " << endl;
  for (int i = 0; i < nb_employe; i++)
    ListeEmploye();
}
