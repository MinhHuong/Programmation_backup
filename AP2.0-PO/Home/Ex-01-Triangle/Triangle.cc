#include "Triangle.h"
#include <iostream>
#include <math.h>
using namespace std;

Triangle::Triangle() {
  cout << "Triangle::Constructeur par defaut" << endl;
  a = b = c = 0.0;
}

void Triangle::saisir() {
  cout << "Entrez la longueur de trois cotes du triangle : ";
  float aa,bb,cc;
  cin >> aa >> bb >> cc;
  a = aa;
  b = bb;
  c = cc;
}

void Triangle::afficher() {
  cout << "La longueur des 3 cotes : " << a << ' ' << b << ' ' << c << endl;
}

bool Triangle::verifier() {
  return ((a+b>c) &&
	  (a+c>b) &&
	  (b+c>a));
}

void Triangle::classifier() {
  if (a == b) {
    if (a == c)
      cout << "Equilateral" <<m endl;
    else
      cout << "Isocele" << endl;
  }
  
  if (a == c) 
    cout << "Isocele" << endl;
  
  if (b == c)
    cout << "Isocele" << endl;

  if ((a*a + b*b == c*c) ||
      (a*c + c*c == b*b) ||
      (b*b + c*c == a*a))
    cout << "Rectangle" << endl;
}

float Triangle::Perimetre() const {
  return (a+b+c);
}

float Triangle::Aire() const {
  float p = Perimetre()/2.0;
  return sqrt(p*(p-a)*(p-b)*(p-c));
}
