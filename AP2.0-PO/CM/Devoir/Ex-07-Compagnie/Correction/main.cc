#include "Siege.h"
#include "Employe.h"
#include "Compagnie.h"

int main() {
  Employe e1("Nicholas");
  Employe e2("Vincent");
  Employe e3("Olivier");

  {
    Compagnie c("Paris");
    c.embaucher(e1);
    c.embaucher(e2);
    c.embaucher(e3);
    c.ListeEmploye();
  }

  e1.travailler();
  
  return 0;
}
