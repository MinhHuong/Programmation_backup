#ifndef COMPAGNIE_H
#define COMPAGNIE_H
#include "Employe.h"
#include "Siege.h"

class Compagnie {
 private:
  int nb_employe;
  Siege siege;
  Employe * employe;

 public:
  Compagnie();
  Compagnie(string);
  ~Compagnie();

  int getNbEmploye() const;
  void embaucher(Employe);
  void ListeEmploye();
};

#endif
