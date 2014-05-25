#include "Personne.h"

int main() {
  Personne pers1;
  pers1.setAge(19);
  pers1.setPrenom("Huong");
  pers1.setNom("Minh");
  pers1.quiSuisJe();

  Personne pers2(pers1);
  pers2.quiSuisJe();
  pers2.getAge();

  Personne pers3("Son","Lam",33);
  pers3.quiSuisJe();

  Personne tabPers[3];
  tabPers[0] = pers1; 
  tabPers[0].quiSuisJe();

  tabPers[1] = pers2;
  tabPers[1].quiSuisJe(); 

  tabPers[2] = pers3;
  tabPers[2].quiSuisJe();

  tabPers[0].setAge(41); 
  tabPers[0].quiSuisJe(); 

  pers1.quiSuisJe(); 

  pers3.setAge(61); 
  pers3.quiSuisJe();
  tabPers[2].quiSuisJe(); 

  Personne tabPersCopie[3]={pers1,pers2,pers3};
  tabPersCopie[0].quiSuisJe();
  tabPersCopie[1].quiSuisJe();
  tabPersCopie[2].quiSuisJe();

  return 0;
}
