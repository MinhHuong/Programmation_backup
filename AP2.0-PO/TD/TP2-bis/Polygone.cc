#include "Polygone.h"
#include <sstream>
#include <fstream>
#include <cstdlib>
#include <iostream>
#include <assert.h>

int Polygone::my_taille = 0;

Polygone::Polygone()
{
  //cout << "Polygone::Constructeur par defaut" << endl;
  my_tab = NULL;
}

Polygone::Polygone(const Polygone & p) {
  my_taille = p.my_taille;
  my_tab = new Point[my_taille];
  for (int i = 0 ; i < my_taille ; i++)
    my_tab[i] = p.my_tab[i];
}

Polygone::~Polygone() {
  //cout << "Polygone::Destructeur" << endl;
  if (my_tab != NULL)
    delete [] my_tab;
}

void Polygone::saisie() {
  int nb;
  cout << "Nombre de sommets : ";
  cin >> nb;
  my_taille = nb;
  float x, y;
  
  my_tab = new Point[my_taille];

  for (int i = 0 ; i < my_taille ; i++) {
    cout << "Point[" << i << "] = ";
    cin >> x >> y;
    my_tab[i].setX(x);
    my_tab[i].setY(y);
  }
}

string Polygone::toString() {
  ostringstream oss;

  oss << "Les points contenant dans le polygone :\n";

  for (int i = 0 ; i < my_taille ; i++)
    oss << "Point[" << i << "] = " << my_tab[i].toString() << "\n";

  return oss.str();
}

void Polygone::deplace(float dx, float dy) {
  for (int i = 0; i < my_taille; i++)
    my_tab[i].deplace(dx,dy);
}

void Polygone::ajoutSommet(const Point & p) {
  int pos = 0;

  for (int i = 0 ; i < my_taille ; i++) {
    if ((my_tab[i].getX() == p.getX()) && 
    	(my_tab[i].getY() == p.getY()))
      pos = -1;
  }
  
  if (pos == -1)
    cout << p << " existe deja dans le polygone" << endl;
  else {
    Point * temp;
    my_taille++;

    if (my_tab == NULL)
      my_tab = new Point[1];

    temp = new Point[my_taille];

    for (int i = 0; i < my_taille-1; i++)
      temp[i] = my_tab[i];

    temp[my_taille-1] = p;

    delete [] my_tab;
  
    my_tab = new Point[my_taille];

    for (int i = 0; i < my_taille; i++)
      my_tab[i] = temp[i];
  }
}


float Polygone::Perimetre() const {
  float p = 0;

  for (int i = 0 ; i < my_taille-1 ; i++) 
    p += my_tab[i].distance(my_tab[i+1]);

  p += my_tab[my_taille-1].distance(my_tab[0]);
  
  return p;
}

void Polygone::litFichier(string nom_fic) {
  fstream f;
  int line = 0, i = 0;
  float a, b;
  Point p;

  int n_line = 0;
  float nb;

  // calculer le nombre de lignes
  f.open(nom_fic, ios::in);
  f >> nb;
  while ( !f.eof() ) {
    n_line++;
    f >> nb;
  }
  f.close();

  // calculer le nombre de points
  int nb_points = n_line/2;

  my_tab = new Point[nb_points];

  // commencer a manipuler le fichier
  f.open(nom_fic, ios::in);

  float coor;
  f >> coor;
  while ( !f.eof() ) {
    line++;

    if (line % 2 == 1) { // ligne impaire : x
      a = coor;
      p.setX(a);
    }
    else { // ligne paire : y
      b = coor;
      p.setY(b);
      ajoutSommet(p);
      i++;
    }
    
    f >> coor;
  }

  f.close();
}

void Polygone::ecritFichier(string nom_fic) {
  fstream f;

  saisie();
  
  f.open(nom_fic, ios::out);
  f << "Polygone : " << endl;
  for (int i = 0 ; i < my_taille ; i++)
    f << my_tab[i].toString() << endl;
  f.close();
  
}

Point Polygone::getPoint(int ind) const {
  for (int i = 0; i < my_taille; i++)
    if (i == ind)
      return my_tab[i];
}

int Polygone::getTaille() const {
  return my_taille;
}

// constructeur par copie : il doit creer un nouveau variable de type Point pour contenir my_tab[i] --> une affectation

// const Point & getPoint(int ind) const
// il prend l'adresse du point d'indice [i] et fait une affectation directe


Polygone & Polygone::operator=(const Polygone & p) {
  cout << "Polygone::Operateur d'affectation" << endl;
  if (this != &p) {
    my_taille = p.my_taille;

    my_tab = new Point[my_taille];
    for (int i = 0; i < my_taille ; i++)
      my_tab[i] = p.my_tab[i];
  }
  return *this;
}
