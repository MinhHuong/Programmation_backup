#include "Date.h"
#include <math.h>
using namespace std;

ostream& operator<<(ostream& out, const Date& d) {
  out << d.toString();
  return out;
}

Date::Date() {
  cout << "Date::Constructeur par defaut" << endl;
  j = m = a = 0;
}

Date::Date(int jour, int mois, int annee) {
  cout << "Date::Constructeur avec parametres" << endl;
  j = jour;
  m = mois;
  a = annee;
}

Date::~Date() {
  cout << "Date::Destructeur" << endl;
}

string Date::toString() const {
  ostringstream oss;
  oss << j << '/' << m << '/' << a;
  return oss.str();
}

int Date::nbJour() const {
  int nb_jour;

  // Fevrier
  if (m==2) {
    if (bissextile())
      nb_jour = 29;
    else
      nb_jour = 28;
  }

  // Les mois de 31 jours
  else if ((m==1)||(m==3)||(m==5)||(m==7)||(m==8)||(m==10)||(m==12)) 
    nb_jour = 31;

  // Les mois de 30 jours
  else 
    nb_jour = 30;
    
  return nb_jour;
}

bool Date::bissextile() const {
  if (a % 100 == 0) {
    if (a % 400 == 0)
      return true;
    else
      return false;
  }
  else if (a % 4 == 0)
    return true;
  
  return false;
}

bool Date::verifier() const { 
  if ( (j>0) && (j<=nbJour()) && (m>0) && (m<13) )
    return true;
  else
    return false;
}

void Date::increJour() {
  if (j==nbJour()) {
    if (m==12) {
      a++;
      m=1;
    }
    else {
      m++;
    }
    j=1;
  }
  else
    j++;
}

void Date::decreJour() {
  if (j==1) {
    int old_m = m;
    --m;

    if (old_m==1) {
      a--;
      m=12;
    }
    j=nbJour();
  }  
  else
    j--;
}

void Date::increSem() {
  int total_jour = nbJour();
  
  if (j+7>total_jour) {
    if (m==12) {
      a++;
      m=1; 
    }
    else {
      m++;
    }
    j = 7-(total_jour-j);
  }
  else
    j+=7;
}

void Date::decreSem() {
  if (j-7<1) {
    int old_m = m;
    --m;

    if (old_m==1) {
      a--;
      m=12;
    }    
    j=nbJour()-(7-j);
  }
  else
    j-=7;
}
