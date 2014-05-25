#include "Enseignant.h"
#include <vector>

void afficher(Personne p) {
  p.quiSuisJe();
}

int main() {
  cout << "1. Pointeur : " << endl;
  Enseignant *e1 = new Enseignant("AP1.2","Paris 6", "Karine","Heydemann",27); 
  Personne *p1 = new Personne("Alice","Alain",25);
  vector<Personne*> v;
  v.push_back(e1);
  v.push_back(p1);
  v[0]->quiSuisJe();
  v[1]->quiSuisJe();

  cout << endl << "2. Statique :" << endl;
  Enseignant nj("AP1.1","LaBri","Olivier","Ly",30);
  Personne p("Fabien","Baldacci",27);
  vector<Personne> vp;
  vp.push_back(nj);
  vp.push_back(p);
  vp[0].quiSuisJe();
  vp[1].quiSuisJe();

  return 0;
}
