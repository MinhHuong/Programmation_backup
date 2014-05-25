#include "Date.h"

int main() {
  Date date_init(1,1,2009);
  Date date_copie(date_init);  
  date_init.setDate(30,12,2010);
  date_init.afficherDate();
  date_copie.afficherDate();

  return 0;
}
