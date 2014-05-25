#include "PrixArticle.h"
using namespace std;

PrixArticle::PrixArticle(float prix, 
			 Article * a,
			 Magasin * m)
  : prixVente(prix), art(a), mag(m)
{
  //cout << "PrixArticle::Constructeur avec parametres" << endl;
}

PrixArticle::~PrixArticle() {
  //cout << "PrixArticle::Destructeur" << endl;
}

Article* PrixArticle::getArticle() const {
  return art;
}

float PrixArticle::getPrix() const {
  return prixVente;
}

/*
void PrixArticle::meilleurPrix(Article * a, vector<PrixArticle*> vecP) {
  int taille = 0;

  for (size_t i = 0 ; i < vecP.size() ; i++) {
    if (a == vecP[i]->getArticle())
      taille++;
  }

  float prix[taille];
  int j = 0;

  for (size_t i = 0 ; i < vecP.size() ; i++) 
    if (a == vecP[i]->getArticle()) { 
      prix[j] = vecP[i]->getPrix();     
      j++;
    }

  float min = prix[0];
  for (int m = 0 ; m < taille ; m++)
    if (min > prix[m])
      min = prix[m];

  for (size_t i = 0 ; i < vecP.size() ; i++)
    if (min == vecP[i]->getPrix()) {
      (vecP[i]->getArticle())->afficher();
      cout << "Prix : " << min << endl;
    }
}
*/
