#ifndef PRIX_ARTICLE_H
#define PRIX_ARTICLE_H
#include <iostream>
#include "Magasin.h"
#include "Article.h"
#include <vector>
using namespace std;

class Article;
class Magasin;

class PrixArticle {
 private:
  float prixVente;
  Article * art;
  Magasin * mag;
  
 public:
  PrixArticle(float, Article*, Magasin*);
  ~PrixArticle();

  Article* getArticle() const;
  float getPrix() const;
  void meilleurPrix(Article*, vector<PrixArticle*>);
};

#endif
