#include "Employe.h"
#include "Gerant.h"
#include "Secretaire.h"
#include <vector>
#include <typeinfo>

int main() {
  vector<Employe*> v;
  
  Employe * e1 = new Employe("Alice",25);

  Employe * e2 = new Gerant("Adam", 35);
  
  Employe * e3 = new Secretaire("Layla",27);

  v.push_back(e1);
  v.push_back(e2);
  v.push_back(e3);

  int nb_sec = 0;  

  cout << "En utilisant TYPEID : " << endl;
  for (size_t i = 0 ; i < v.size() ; i++)
    if (typeid(*v[i]) == typeid(Secretaire))
      nb_sec++;
  
  cout << "Il y a " << nb_sec << " secretaire(s)" << endl;

  cout << endl << "En utilisant le transtypage : " << endl;
  nb_sec = 0;
  for (size_t i = 0 ; i < v.size() ; i++) {
    Secretaire * s = dynamic_cast<Secretaire*>(v[i]);
    if (s == NULL)
      cout << "Ce n'est pas 1 secretaire" << endl;
    else {
      cout << "1 secretaire trouve" << endl;
      nb_sec++;
    }
  }

  cout << "Il y a " << nb_sec << " secretaire(s)" << endl;

  return 0;
}
