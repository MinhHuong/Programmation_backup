#include "Article.h"
#include "Magasin.h"
#include "PrixArticle.h"
#include "Employe.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
  Article * a1 = new Article(20, "Parapluie");
  Article * a2 = new Article(13, "Chaise");
  Article * a3 = new Article(19, "Table");
  vector<Article*> vA;
  vA.push_back(a1);
  vA.push_back(a2);
  vA.push_back(a3);

  Magasin * m1 = new Magasin("Petit", "234");
  Magasin * m2 = new Magasin("Moyen", "567");
  Magasin * m3 = new Magasin("Grand", "100");
  Magasin * m4 = new Magasin("ABC", "987");
  Magasin * m5 = new Magasin("WalMart", "555");
  vector<Magasin*> vM;
  vM.push_back(m1);
  vM.push_back(m2);
  vM.push_back(m3);
  vM.push_back(m4);
  vM.push_back(m5);

  // prix pour l'article a1
  PrixArticle * p1 = new PrixArticle(25.5,a1,m2);
  PrixArticle * p2 = new PrixArticle(21,a1,m2); 

  // l'article a2
  PrixArticle * p3 = new PrixArticle(15,a2,m3);
  PrixArticle * p4 = new PrixArticle(17,a2,m4);
  PrixArticle * p5 = new PrixArticle(16,a2,m5);

  // l'article a3
  PrixArticle * p6 = new PrixArticle(29,a3,m1);
  PrixArticle * p7 = new PrixArticle(28.5,a3,m4);

  vector<PrixArticle*> vP;
  vP.push_back(p1);
  vP.push_back(p2);
  vP.push_back(p3);
  vP.push_back(p4);
  vP.push_back(p5);
  vP.push_back(p6);
  vP.push_back(p7);

  // chercher le meilleur prix pour chaque article
  a1->meilleurPrix(vP);
  a2->meilleurPrix(vP);
  a3->meilleurPrix(vP);

  for (size_t i = 0 ; i < vA.size() ; i++)
    delete vA[i];

  for (size_t i = 0 ; i < vM.size() ; i++)
    delete vM[i];

  for (size_t i = 0 ; i < vP.size() ; i++)
    delete vP[i];
 
  return 0;
}
