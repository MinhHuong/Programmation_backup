#ifndef GESTION_H
#define GESTION_H

#include "Liste.h"
#include "Etudiant.h"

typedef Liste<Etudiant>::TIterator TAdresse;

// Exercice 36 : ===========================
void saisirListe( Liste<Etudiant> & l );
void afficherListe( Liste<Etudiant> l );
int rangListe( Liste<Etudiant> l, string nom );
float moyenneNotes( Liste<Etudiant> l );

// Exercice 37 : ===========================
void ajouterTrie( Liste<Etudiant> & l, Etudiant etd );
bool estTrie( Liste<Etudiant> l );
void fusionnerListe( Liste<Etudiant> L1, Liste<Etudiant> L2, Liste<Etudiant> & L3 );

#endif
