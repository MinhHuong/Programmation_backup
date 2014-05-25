#include "Compagnie.h"

int main() {
  /*Employe e1("Minh Huong", 24, "secretaire");
  e1.travailler();

  Employe e2;
  e2.setEmploye("Son Lam", 33, "chef de projet");
  e2.travailler();*/

  /*
  Siege s1("Paris");
  Siege s2;
  s2.setPays("Bordeaux");
  */

  /*
  Date d1;
  d1.setDate(14,8,1995);
  d1.afficherDate();

  Date d2(22,4,1985);
  d2.afficherDate();*/

  Date d1(19,5,2008);
  Compagnie c1("Bordeaux",d1);
  
  Employe e1("Alice", 25, "secretaire");
  Employe e2("Amanda", 20, "stagiaire");

  c1.embaucher(e1);
  c1.embaucher(e2);

  c1.ListeEmploye();
  c1.informer();
  
  return 0;
}
