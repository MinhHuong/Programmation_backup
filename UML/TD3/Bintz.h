#ifndef BINTZ_H
#define BINTZ_H

#include <iostream>
using namespace std;

enum ETAT { normal = 'n', 
	    faim = 'f', 
	    manger = 'm',
	    repos = 'r' };

class Bintz {
 private:
  char etat;
  int time;

 public:
  Bintz();
  ~Bintz();

  void timer(int t);
  void timer_pleurer(int t);
  void pleurer();
  void manger();
  int chanter();
  void sourire();
  void mettre_bavoir();
  void retirer_bavoir();
  void maj_etat(ETAT );
  void afficher_etat();
  int getTime() const;
};

#endif
