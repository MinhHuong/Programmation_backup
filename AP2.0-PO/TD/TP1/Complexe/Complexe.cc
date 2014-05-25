#include "Complexe.h"
Complexe::Complexe() {
  my_reel = my_imaginaire = -1;
}

Complexe::Complexe(float a, float b) {
  my_reel = a;
  my_imaginaire = b;
}

Complexe::~Complexe() {
  //cout << "Complexe : destructeur" << endl;
}

string Complexe::toString() const {
  string re = intToString(my_reel),
    img = intToString(my_imaginaire);

  string nb = "";

  if (my_reel == 0)
    nb += "";
  else 
    nb += re;

  if (my_imaginaire == 0) {
    if (my_reel == 0)
      nb = "0";
    else
      nb += "";
  }
  else if (my_imaginaire == 1)
    nb += " + i";
  else if (my_imaginaire == -1)
    nb += " - i";
  else if (my_imaginaire < 0)
    nb += img + "i";
  else
    nb += " + " + img + "i";
  
  return nb;
}

void Complexe::setReel(float a) {
  my_reel = a;
}

void Complexe::setImaginaire(float b) {
  my_imaginaire = b;
}

float Complexe::getReel() const {
  return my_reel;
}

float Complexe::getImaginaire() const {
  return my_imaginaire;
}

void Complexe::plus(const Complexe & c, Complexe & s) const {
  s.my_reel = my_reel + c.my_reel;
  s.my_imaginaire = my_imaginaire + c.my_imaginaire;
}

void Complexe::fois (const Complexe & c, Complexe & p) const {
  p.my_reel = my_reel*c.my_reel - my_imaginaire*c.my_imaginaire;
  p.my_imaginaire = my_reel*c.my_imaginaire + c.my_reel*my_imaginaire;
}
