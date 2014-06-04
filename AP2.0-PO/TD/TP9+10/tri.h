#ifndef TRI_H
#define TRI_H
#include "gestion.h"
#include "Liste.h"
#include "Etudiant.h"

typedef Liste<Etudiant>::TIterator TAdresse;

TAdresse medianSousListe( Liste<Etudiant> l, TAdresse a, TAdresse b );


#endif
