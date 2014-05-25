#include "Magasin.h"
using namespace std;

int Magasin::nombreMagasins = 0;

Magasin::Magasin(string nom, string adr) {
  nomMag = nom;
  adrMag = adr;
  numMag = nombreMagasins;
  nombreMagasins++;
}
