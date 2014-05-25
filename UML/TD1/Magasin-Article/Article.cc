#include "Article.h"
using namespace std;

int Article::nombreArticles = 0;

Article::Article(float prix, string libelle) {
  prixAchat = prix;
  libelleArticle = libelle;
  numArticle = nombreArticles;
  nombreArticles++;
}

//Article::~Article() {}

void Article::afficher() {
  cout << "Information de l'article :\n";
  cout << "Nom : " << libelleArticle << endl;
}


void Article::meilleurPrix(vector<PrixArticle*> vecP) {
  int taille = 0;

  for (size_t i = 0 ; i < vecP.size() ; i++) {
    if (this == vecP[i]->getArticle())
      taille++;
  }

  float prix[taille];
  int j = 0;

  for (size_t i = 0 ; i < vecP.size() ; i++) 
    if (this == vecP[i]->getArticle()) { 
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
