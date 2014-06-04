#ifndef GESTION_H
#define GESTION_H

#include "Liste.h"
#include "Etudiant.h"

// Raccourci pour TAdresse
typedef Liste<Etudiant>::TIterator TAdresse;

void afficherListe( const Liste<Etudiant> & liste );

// crée une liste à partir d'un fichier
void fic2Liste( std::string nom_fic, Liste<Etudiant> & l );

// sauvegarder une liste a un fichier
void liste2Fix( std::string nom_fic, Liste<Etudiant> l );

#endif
