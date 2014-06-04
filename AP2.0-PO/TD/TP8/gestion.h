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

// Fusionner 1 liste ( utiliser les fonctions predefinies )
void fusionnerListe_2( Liste<Etudiant> L1, Liste<Etudiant> L2, Liste<Etudiant> & L3 );

// sans utiliser les fonctions predefinies
void trier_insert( Liste<Etudiant> src, TAdresse & adr_src, Liste<Etudiant> & dest, TAdresse & adr_dest );

void insert_rest( Liste<Etudiant> src, TAdresse & adr_src, Liste<Etudiant> dest, TAdresse & adr_desr );

void fusionnerListe_2( Liste<Etudiant> L1, Liste<Etudiant> L2, Liste<Etudiant> & L3 );

// Exercice 38 : ============================
void trierFauxJuste( Liste<Etudiant> l, Liste<Etudiant> & liste_triee  );

#endif
