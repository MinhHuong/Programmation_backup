#include "Gestion.h"
using namespace std;

Gestion::Gestion() {
  my_nbOeuvres = 0;
  
  for (int i = 0 ; i < MAX ; i++)
    my_tabOeuvres[i] = NULL;
}

Gestion::~Gestion() {}

void Gestion::addOeuvre(Oeuvre * oeu) {
  my_nbOeuvres++;

  int check = 0;
  for (int i = 0 ; i < my_nbOeuvres ; i++)
    if (my_tabOeuvres[i] == oeu)
      check = -1;

  if (check != -1)
    my_tabOeuvres[my_nbOeuvres-1] = oeu;
  else
    cout << "Cette oeuvre existe deja dans le stock" << endl;
}

void Gestion::set_possesseur(int indice, string poss) {
  Plastique * plas = dynamic_cast<Plastique*>( find_Oeuvre(indice) );

  if (plas != NULL)
    plas->setPossesseur(poss);
  else
    cout << "Oeuvre pas trouvee" << endl;
}

void Gestion::set_date_acquis(int indice, int ja, int ma, int aa) {
  Plastique * plas = dynamic_cast<Plastique*>(find_Oeuvre(indice) );
  
  if (plas != NULL)
    plas->setDateAcquis(ja, ma, aa);
  else
    cout << "Oeuvre pas trouvee" << endl;
}

Oeuvre * Gestion::find_Oeuvre(int indice) {
  for (int i = 0 ; i < my_nbOeuvres ; i++)
    if (i == indice)
      return my_tabOeuvres[i];
  
  return NULL;
}

void Gestion::print_Oeuvre(int indice) {
  Oeuvre * oeu = find_Oeuvre(indice);
  cout << oeu->toString() << endl;
}

void Gestion::print_all_title() {
  for (int i = 0 ; i < my_nbOeuvres ; i++)
    cout << my_tabOeuvres[i]->getTitle() << endl;
}
