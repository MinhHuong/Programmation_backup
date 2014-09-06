#include "tri.h"
#include <iostream>
#include <cstdlib>
#include <string>

TAdresse medianSousListe( Liste<Etudiant> l, TAdresse a, TAdresse b )
{
  if (a==b)
    l.erreur( "La sous-liste doit avoir au moins 2 elements !" );
  
  TAdresse found = a;

  while ( a!=b && l.adresseSuivant( a )!=b )
    {
      found = l.adresseSuivant( found );
      a = l.adresseSuivant( a );
      a = l.adresseSuivant( a );
    }

  return found;
}

void fusionSousListeConsev( Liste<Etudiant> & src, TAdresse start, TAdresse inter, TAdresse end )
{
  TAdresse store, real_start=start;

  Etudiant fictif;
  src.insererEnTete( fictif );

  TAdresse temp = src.adressePremier();
  if ( start!=src.adressePremier() )
    while ( src.adresseSuivant( temp )!=real_start )
      temp = src.adresseSuivant( temp );

  store=temp;

  /*
  cout << *start << endl
       << *inter << endl
       << *end << endl
       << *temp << endl;
  */

  while ( src.adresseSuivant( inter )!=src.adresseSuivant( end ) && start!=src.adresseSuivant( inter ) )
    {
      if ( start->note() <= src.adresseSuivant( inter )->note() )
	{
	  temp = start;
	  start = src.adresseSuivant( start );
	}
      else
	{	  
	  src.insererApres( *(src.adresseSuivant( inter )), temp );
	  src.supprimerApres( inter );
	  start = real_start;
	}
    }

  src.supprimerEnTete();
}


Liste<Etudiant> triFusion( Liste<Etudiant> & l )
{
  TAdresse adr = l.adressePremier();
  
  
}
