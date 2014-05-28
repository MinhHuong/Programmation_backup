#ifndef DATE_H
#define DATE_H
#include <iostream>

class Date {
 private:
  int my_jour;
  int my_mois;
  int my_annee;

 public:
  Date();
  Date(int j, int m, int a);
  ~Date();

  void affiche();

  bool bissextile() const;
  int nombre_jours() const;
  bool verifierDate() const;

  int getJour() const;
  int getMois() const;
  int getAnnee() const;

  void setJour(int j);
  void setMois(int m);
  void setAnnee(int a);

  bool operator<=(const Date & d);
  bool operator>=(const Date & d);
  bool operator==(const Date & d);
  Date operator=(const Date & d);

  void lendemain();
  int intervalle(const Date & d) const;
};

#endif
