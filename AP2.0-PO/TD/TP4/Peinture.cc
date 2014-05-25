#include "Peinture.h"
using namespace std;

Peinture::Peinture(string aut, string titre, string sty,
		   int j, int m, int a, int val,
		   string poss, int ja, int ma, int aa,
		   string supp, string mat)
  : Plastique(aut, titre, sty, j, m, a, val, poss, ja, ma, aa)
{
  //cout << "Peinture::Constructeur avec parametres" << endl;
  my_support = supp;
  my_matiere = mat;
}

Peinture::Peinture(const Peinture& peint) 
  : Plastique(peint) {
  //cout << "Peinture::Constructeur par copie" << endl;
  my_support = peint.my_support;
  my_matiere = peint.my_matiere;
}

Peinture::~Peinture() {
  //cout << "Peinture::Destructeur" << endl;
}

string Peinture::toString() const {
  string info = "Information de la peinture :\n";
  info += Plastique::toString() +"\n";
  info += "Support : " + my_support + "\n";
  info += "Matiere : " + my_matiere + "\n";
  
  return info;
}
