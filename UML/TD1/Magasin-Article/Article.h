#ifndef ARTICLE_H
#define ARTICLE_H
#include <iostream>
#include <string>
#include <vector>
#include "Magasin.h"
#include "PrixArticle.h"

using namespace std;

class PrixArticle;

class Article {
 private:
  int numArticle;
  static int nombreArticles;
  float prixAchat;
  string libelleArticle;
  vector <PrixArticle*> v_M;

 public:
  Article(float, string);

  void afficher();
  void meilleurPrix(vector<PrixArticle*> vecP);
};

#endif
