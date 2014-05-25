#include <iostream>
#include <cstdlib>
#include <termios.h>
#include <stdio.h>
#include <unistd.h>
#include <ctime>
#include "Bintz.h"
using namespace std;

void normal(Bintz & b) {
  b.afficher_etat();
  b.sourire();
}

void manger(Bintz & b) { 
  b.maj_etat(manger);
  b.mettre_bavoir();
  b.mange();
  b.retirer_bavoir(); 
}

int main() {
  Bintz animal;
  int temps = animal.getTime();
  
  normal(animal);

  animal.timer(temps);

  b.maj_etat(faim);

  animal.timer(temps);

  animal.maj_etat(repos);
  animal.pleurer();
  animal.maj_etat(normal);
  

  return EXIT_SUCCESS;
}
