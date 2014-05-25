#ifndef COMPAGNIE_H
#define COMPAGNIE_H
#include <iostream>
#include <string>
#include "Siege.h"
#include "Employe.h"
#include "Date.h"
using namespace std;

class Compagnie {
 private:
  int nb_employe;
  Siege my_siege;
  Employe * my_employes;
  Date * date_fondation;

 public:
  Compagnie();
  Compagnie(string,Date);
  ~Compagnie();

  int getNbEmploye() const;

  void embaucher(Employe);
  //nb_employe++ et ajouter 1 nouveau employe dans le tableau conteant des employes

  void licencier(Employe);
  //le contraire de embaucher()

  void promouvoir(Employe);
  //changer le poste de l'employe

  void ListeEmploye();
  //citer tous les employes en utilisant travailler()

  void informer();
  //afficher toutes les informations de la compangie (le nombre d'employes, le siege, la date de fondation
};

#endif
