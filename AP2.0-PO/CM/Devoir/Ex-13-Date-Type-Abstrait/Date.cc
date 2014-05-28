#include "Date.h"
using namespace std;

Date::Date() {
  my_jour = my_mois = 1;
  my_annee = 1000;
}

Date::Date(int j, int m, int a) {
  my_jour = j;
  my_mois = m;
  my_annee = a;
}

Date::~Date() {}

void Date::affiche() 
{
  cout << "C'est le " << my_jour << "/" << my_mois << "/" << my_annee << endl;
}

bool Date::bissextile() const {
  if (my_annee%100==0) 
    return (my_annee%400==0);
  else
    return (my_annee%4==0);
}

int Date::nombre_jours() const
{
  int nb_jours;

  if ( my_mois==2 )
    {
      if ( bissextile() )
	nb_jours = 29;
      else
	nb_jours = 28;
    }
  else if ( (my_mois==1) || (my_mois==3) || (my_mois==5) || (my_mois==7) || (my_mois==8) || (my_mois==10) || (my_mois==12) )
    nb_jours = 31;
  else
    nb_jours = 30;

  return nb_jours;
}

bool Date::verifierDate() const {
  return ( ( my_jour>0 ) && ( my_jour<=nombre_jours() ) && ( my_mois>0 ) && ( my_mois<13 ) );
}

int Date::getJour() const {
  return my_jour;
}

int Date::getMois() const {
  return my_mois;
}

int Date::getAnnee() const {
  return my_annee;
}

void Date::setJour(int j) {
  my_jour = j;
}

void Date::setMois(int m) {
  my_mois = m;
}

void Date::setAnnee(int a) {
  my_annee = a;
}

bool Date::operator>=(const Date & d) {
  if (my_annee > d.my_annee)
    return true;
  else if (my_annee < d.my_annee)
    return false;
  else 
    {
      if (my_mois > d.my_mois)
	return true;
      else if (my_mois < d.my_mois)
	return false;
      else
	return (my_jour >= d.my_jour);
    }
}

bool Date::operator<=(const Date & d) {
  if (my_annee < d.my_annee)
    return true;
  else if (my_annee > d.my_annee)
    return false;
  else 
    {
      if (my_mois < d.my_mois)
	return true;
      else if (my_mois > d.my_mois)
	return false;
      else
	return (my_jour <= d.my_jour);
    }
}

bool Date::operator==(const Date & d) {
  return ( (my_annee==d.my_annee) &&
	   (my_mois==d.my_mois) &&
	   (my_jour==d.my_jour) );
}

Date Date::operator=(const Date & d) 
{
  if (*this != d) 
    {
      my_jour = d.my_jour;
      my_mois = d.my_mois;
      my_annee = d.my_annee;
    }

  return *this;
}

void Date::lendemain() {
  if ( my_jour==nombre_jours() )
    {
      my_jour = 1;
      
      if ( my_mois==12 )
	{
	  my_annee++;
	  my_mois = 1;
	}
      else
	{
	  my_mois++;
	}
    }
  else
    {
      my_jour++;
    }
}

int Date::intervalle(const Date & d) const {
  Date temp;
  if ( d <= *this )
    {
      temp = *this;
      *this = d;
      d = temp;
    }

  
}

/*
  13/2/2008  ---> 30/5/2010
*/
