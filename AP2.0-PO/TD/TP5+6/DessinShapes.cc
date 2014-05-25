#include "DessinShapes.h"
#include "Circle.h"
#include <iostream>
#include <unistd.h>
using namespace std;

DessinShapes::DessinShapes() {
  for (int i = 0 ; i < MAX ; i++)
    my_tabShapes[i] = NULL;
  
  my_nbShapes = 0;
}

DessinShapes::~DessinShapes() {}

void DessinShapes::addShape(Shape * pshape) {
  my_nbShapes++;

  int check = 0;
  for (int i = 0 ; i < my_nbShapes-1 ; i++)
    if (my_tabShapes[i] == pshape)
      check = -1;
  
  if (check == -1)
    cout << "Cette forme existe deja" << endl;
  else
    my_tabShapes[my_nbShapes-1] = pshape;
}

void DessinShapes::refresh(Screen & s) {
  for (int i = 0 ; i < my_nbShapes ; i++)
    my_tabShapes[i]->draw(s);
  s.refresh();
}

void DessinShapes::setColourAll(char col) {
  for (int i = 0 ; i < my_nbShapes ; i++)
    my_tabShapes[i]->setColour(col);
}

void DessinShapes::moveAll(int dx, int dy) {
  for (int i = 0 ; i < my_nbShapes ; i++)
    my_tabShapes[i]->move(dx,dy);
}

void DessinShapes::eraseAll() {
  for (int i = 0 ; i < my_nbShapes ; i++)
    delete my_tabShapes[i];

  my_nbShapes = 0;
}

Shape * DessinShapes::select(int ind) const {
  for (int i = 0 ; i < my_nbShapes ; i++) 
    if (i == ind) 
      return my_tabShapes[i];

  return NULL;
}

void DessinShapes::setColourOne(int indice, char col) {
  Shape * s = select(indice);
  
  if (s != NULL)
    s->setColour(col);
  else {
    cout << "Indice pas trouvee." << endl;
    sleep(2);
  }
}

void DessinShapes::moveOne(int indice, int dx, int dy) {
  Shape * s = select(indice);

  if (s != NULL) 
    s->move(dx, dy);
  else {
    cout << "Indice pas trouvee." << endl;
    sleep(2);
  }
}

void DessinShapes::erase(int indice) {
  for (int i = indice ; i < my_nbShapes-1 ; i++)
    my_tabShapes[i] = my_tabShapes[i+1];
    
  my_nbShapes--;
}

void DessinShapes::eraseOne(int indice) {
  Shape * s = select(indice);
  
  if (s != NULL)
    erase(indice);
  else {
    cout << "Indice pas trouvee. Veuillez entrez une autre indice" << endl;
    sleep(2);
  }
}

Shape * DessinShapes::select(const Point & p) const {
  for (int i = 0 ; i < my_nbShapes ; i++)
    if (my_tabShapes[i]->appartenir(p))
      return my_tabShapes[i];
  
  return NULL;
}

void DessinShapes::setColourOne(const Point & p, char col) {
   Shape * s = select(p);

  if (s != NULL)
    s->setColour(col);
  else {
    cout << "Ce point n'appartient a aucune forme." << endl;
    sleep(2);
  }
}

void DessinShapes::moveOne(const Point & p, int dx, int dy) {
  Shape * s = select(p);

  if (s != NULL)
    s->move(dx,dy);
  else {
    cout << "Ce point n'appartient a aucune forme." << endl;
    sleep(2);
  }
}

void DessinShapes::erase(const Point & p) {
  int pos;

  for (int i = 0 ; i < my_nbShapes ; i++)
    if (my_tabShapes[i]->appartenir(p))
      pos = i;

  for (int i = pos ; i < my_nbShapes-1 ; i++)
    my_tabShapes[i] = my_tabShapes[i+1];

  my_nbShapes--;
}

void DessinShapes::eraseOne(const Point & p) {
  Shape * s = select(p);

  if (s != NULL)
    erase(p);
  else {
    cout << "Ce point n'appartient a aucune forme." << endl;
    sleep(2);
  } 
}

void DessinShapes::modifierRayon(int indice, int r) {
  Circle * c = dynamic_cast<Circle*>( select(indice) );
  if (c != NULL) 
    c->setRadius(r);
  else {
    cout << "Cette indice ne correspond pas a un cercle" << endl;
    sleep(2);
  }
}
