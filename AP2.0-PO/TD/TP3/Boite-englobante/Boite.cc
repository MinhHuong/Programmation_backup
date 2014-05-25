#include "Boite.h"
#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

void Boite::agrandir() {
  my_nb_alloues *= 2;
  
  Point * temp;
  temp = new Point[my_nb_alloues];
    
  for (int i = 0 ; i < my_nb_alloues/2 ; i++)
    temp[i] = my_points[i];
    
  delete [] my_points;
    
  my_points = new Point[my_nb_alloues];

  for (int i = 0 ; i < my_nb_points-1; i++)
    my_points[i] = temp[i];

  delete [] temp;
}

Boite::Boite(const Point & p ) {
  //cout << "Boite::Constructeur avec parametre d'un point" << endl;
  
  my_nb_alloues = 5;
  my_nb_points = 1;

  my_points = new Point[my_nb_alloues];
  my_points[0] = p;

  my_bas_gauche = my_haut_droite = p;
}

Boite::Boite(const Boite & b) {
  my_bas_gauche = b.my_bas_gauche;
  my_haut_droite = b.my_haut_droite;
  my_nb_points = b.my_nb_points;
  my_nb_alloues = b.my_nb_alloues;
  
  my_points = new Point[my_nb_alloues];
  for (int i = 0 ; i < my_nb_points ; i++)
    my_points[i] = b.my_points[i];
}

Boite::~Boite() {
  //cout << "Boite::Destructeur" << endl;
  if (my_points != NULL)
    delete [] my_points;
}

void Boite::affiche() const {
  cout << "Point bas-gauche : " << my_bas_gauche << endl;
  cout << "Point haut-droite : " << my_haut_droite << endl;
  cout << "Le nombre de points : " << my_nb_points << endl;
  for (int i = 0 ; i < my_nb_points ; i++)
    cout << i+1 << ". " << my_points[i].toString() << endl;
}

bool Boite::interieur(const Point & p) const {
  return ( ((p < my_haut_droite) ||
	    (p == my_haut_droite)) && 
	   ((my_bas_gauche < p) ||
	    (my_bas_gauche == p)) );
}

void Boite::ajouterPoint(const Point & p) {
  int pos;

  for (int i = 0 ; i < my_nb_points ; i++) 
    if (my_points[i] == p) {
      pos = -1;
      cout << p << " existe deja dans la boite" << endl;
    }

  if (pos != -1) {
    my_nb_points++;

    if (my_nb_points > my_nb_alloues)
      agrandir();
  
    float 
      min_x = my_bas_gauche.getX(),
      min_y = my_bas_gauche.getY(),
      max_x = my_haut_droite.getX(),
      max_y = my_haut_droite.getY(),
      px = p.getX(),
      py = p.getY();

    min_x = (px < min_x ? px : min_x);
    min_y = (py < min_y ? py : min_y);
    max_x = (px > max_x ? px : max_x);
    max_y = (py > max_y ? py : max_y);

    my_bas_gauche.setX(min_x);
    my_bas_gauche.setY(min_y);
    my_haut_droite.setX(max_x);
    my_haut_droite.setY(max_y);

    my_points[my_nb_points-1] = p;
  }
}

void Boite::supprimerPoint(const Point & p) {
  int pos = -1;

  for (int i = 0 ; i < my_nb_points ; i++) 
    if (my_points[i] == p)
      pos = i;

  if (pos != -1) {
    // si p existe dans la boite
    for (int i = pos ; i < my_nb_points-1 ; i++)
      my_points[i] = my_points[i+1];
    
    my_nb_points--;

    // tester le nombre de points : > 0 ou <= 0
    if (my_nb_points == 0) {
      my_bas_gauche.setX(0.0);
      my_bas_gauche.setY(0.0);
      my_haut_droite.setX(0.0);
      my_haut_droite.setY(0.0);
      cout << "Attention ! Tous les points ont ete supprimes !\n";
    }
    else {
      float px, py,
	min_x = my_haut_droite.getX(),
	min_y = my_haut_droite.getY(),
	max_x = my_bas_gauche.getX(),
	max_y = my_bas_gauche.getY();
    
      for (int i = 0 ; i < my_nb_points ; i++) {
	px = my_points[i].getX();
	py = my_points[i].getY();

	min_x = (px < min_x ? px : min_x);
	min_y = (py < min_y ? py : min_y);
	max_x = (px > max_x ? px : max_x);
	max_y = (py > max_y ? py : max_y);
      }

      my_bas_gauche.setX(min_x);
      my_bas_gauche.setY(min_y);
      my_haut_droite.setX(max_x);
      my_haut_droite.setY(max_y);
    }
  }
  
  else
    cout << p << " n'existe pas dans la boite" << endl;
}

Boite & Boite::operator=(const Boite & b) {
  //cout << "Boite::Operateur d'affectation" << endl;
  if (this != &b) {
    my_bas_gauche = b.my_bas_gauche;
    my_haut_droite = b.my_haut_droite;
    my_nb_points = b.my_nb_points;
    my_nb_alloues = b.my_nb_alloues;
    
    my_points = new Point[my_nb_alloues];
    for (int i = 0 ; i < my_nb_points ; i++)
      my_points[i] = b.my_points[i];
  }
  return *this;
}
