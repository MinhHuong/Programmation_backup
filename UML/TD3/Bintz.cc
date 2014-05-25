#include "Bintz.h"
#include <cstdlib>
#include <string>
#include <unistd.h>
#include <iostream>
#include <termios.h>
#include <stdio.h>

Bintz::Bintz() {
  etat = normal;
  time = 3;
}

Bintz::~Bintz() {}

void Bintz::timer(int t) {
  for (int i = t ; i >= 0 ; i--) {
    system("clear");    
    cout << "\t\t\t\t" << i << endl;
    sleep(1);
  }
}

void Bintz::timer_pleurer(int t) {
  string choix;
  for (int i = t ; i >= 0 ; i--) {
    system("clear");
    cout << "\t\t\t\t" << i << endl;
    cout << "Voulez-vous que Bintz s'arrete a pleurer ? (y/n) : ";
    getline(cin, choix);
    if (choix == "y")
      break;
    else if (choix.empty())
      continue;
    sleep(1);
  }
}

void Bintz::pleurer() {
  cout << "Bintz pleure" << endl;
}

void Bintz::manger() {
  cout << "Bintz mange" << endl;
}

int Bintz::chanter() {
  char choix;

  cout << "Voulez-vous chanter a votre Bintz ? (y/n) : ";
  cin >> choix;
  if (choix == 'y')
    return 1;
  else
    return 0;
}

void Bintz::sourire() {
  if (chanter() == 1)
    cout << "Bintz sourit" << endl;
}

void Bintz::mettre_bavoir() {
  cout << "Bintz met son bavoir" << endl;
}

void Bintz::retirer_bavoir() {
  cout << "Bintz retire son bavoir" << endl;
}

void Bintz::maj_etat(ETAT et) {
  etat = et;
}

void Bintz::afficher_etat() {
  cout << "Etat de Bintz maintenant : " << etat << endl;
}

int Bintz::getTime() const {
  return time;
}
