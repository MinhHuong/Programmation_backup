#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>

#include "Liste.h"
#include "Etudiant.h"
#include "gestion.h"

using namespace std;

   
// comme son nom l'indique...
void afficherListe( const Liste<Etudiant> & liste )
{
  TAdresse adr = liste.adressePremier();
  while( adr != liste.null() )
  {
    cout << liste.valeurElement( adr ) << endl;
    adr = liste.adresseSuivant( adr );
  } 
}
  

// crée une liste à partir d'un fichier
void fic2Liste( string nom_fic, Liste<Etudiant> & l )
{
  Etudiant fictif, etd;
  l.insererEnTete( fictif );

  TAdresse adr = l.adressePremier();

  fstream f;
  f.open( nom_fic.c_str(), ios::in );

  while ( !f.eof() )
    {      
      etd.lireFlux( f );
      l.insererApres( etd, adr );
      adr = l.adresseSuivant( adr );
    }
  f.close();

  l.supprimerEnTete();
}


// sauvegarde une liste dans un fichier
void liste2Fix( string nom_fic, Liste<Etudiant> l )
{
  TAdresse adr = l.adressePremier();

  fstream f;
  f.open( nom_fic.c_str(), ios::out );
  
  while ( adr!=l.null() )
    {
      adr->ecrireFlux( f );
      adr = l.adresseSuivant( adr );
    }

  f.close();
}
