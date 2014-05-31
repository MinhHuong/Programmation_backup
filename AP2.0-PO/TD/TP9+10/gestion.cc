///////////////////////////////////////////////////////////////////////////////
// gestion.cc
///////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <string>
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
// A FAIRE

// sauvegarde une liste dans un fichier
// A FAIRE 


// et tout ce qui peut servir...
// à compléter

