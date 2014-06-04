#include <cstdlib>
#include <iostream>
#include <string>
#include <fstream>
#include "Liste.h"
#include "Etudiant.h"
#include "gestion.h"

using namespace std;


int main()
{
  Liste<Etudiant> liste;

  fic2Liste( "liste1", liste );
  liste2Fix( "liste1_copy", liste );
  
  return EXIT_SUCCESS;
}

