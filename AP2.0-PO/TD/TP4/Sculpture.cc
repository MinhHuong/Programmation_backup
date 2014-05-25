#include "Sculpture.h"
using namespace std;

Sculpture::Sculpture(string aut, string titre, string sty, int j, int m, int a, int val,
		     string poss, int ja, int ma, int aa,
		     string mat) 
  : Plastique(aut, titre, sty, j, m, a, val,
	      poss, ja, ma, aa)
{
  //cout << "Sculpture::Constructeur avec parametres" << endl;
  my_materiau = mat;
}

Sculpture::Sculpture(const Sculpture& s) 
  : Plastique(s)
{
  //cout << "Sculpture::Constructeur par copie" << endl;
  my_materiau = s.my_materiau;
}

Sculpture::~Sculpture() {
  //cout << "Sculpture::Destructeur" << endl;
}

string Sculpture::toString() {
  string info = "Information de la sculpture : \n";
  info += Plastique::toString();
  info += "Materiau : " + my_materiau + "\n";
  
  return info;
}
