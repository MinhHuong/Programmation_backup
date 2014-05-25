#include "Cercle.h"

Cercle::Cercle() 
  : rayon_(0.0), centre_(0.0,0.0) {
  cout << "Cercle : constructeur par defaut" << endl;
}

Cercle::Cercle(float rayon, float x, float y) 
  : rayon_(rayon), centre_(x,y) {
  cout << "Cercle : constructeur avec parametre" << endl;
}

Cercle::~Cercle() {
  cout << "Cercle : destructeur" << endl;
}

void Cercle::setCentre(float x, float y) {
  centre_ = Point(x,y);
}

void Cercle::setRayon(float rayon) {
  rayon_ = rayon;
}

void Cercle::dessiner() {
  cout << "Votre cercle a du rayon " << rayon_ << " et son centre : ";
  centre_.getPoint();
}
