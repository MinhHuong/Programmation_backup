#include <cstdlib>
#include <iostream>
#include <string>
#include <fstream>
#include "Liste.h"
#include "Etudiant.h"
#include "gestion.h"
#include "tri.h"

using namespace std;


int main()
{
  Liste<Etudiant> liste;
  
  fic2Liste( "liste2", liste );
  
  TAdresse debut = liste.adressePremier(), fin = liste;

  //afficherListe( liste );
  
  return EXIT_SUCCESS;
}

