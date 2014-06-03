#include <cstdlib>
#include <iostream>
#include "Liste.h"
#include "Etudiant.h"
#include "gestion.h"

using namespace std;

typedef Liste<Etudiant>::TIterator TAdresse;
 
int main()
{  
  Liste<Etudiant> liste_1, liste_2, liste_triee;
  
  cout << "\n====== Saisie de la 1ere liste Etudiant ======\n";
  saisirListe( liste_1 );

  cout << "\n====== Affichage de la 1ere liste Etudiant ======\n";
  afficherListe( liste_1 );

  cout << "\n====== Saisie de la 2e liste Etudiant ======\n";
  saisirListe( liste_2 );

  cout << "\n====== Affichage de la 2e liste Etudiant ======\n";
  afficherListe( liste_2 );

  fusionnerListe( liste_1, liste_2, liste_triee );
  
  cout << "\n====== Affichage de la 2e liste Etudiant ======\n";
  afficherListe( liste_triee );

  /*
  cout << "\n====== Tester si une liste est triee (en fonction des notes) ======\n";
  if ( estTrie( liste ) )
    cout << "La liste est triee" << endl;
  else
    cout << "La liste n'est pas triee" << endl;

  cout << "\n====== Ajout dans une liste trie ======\n";
  Etudiant etd;
  cout << "Etudiant : ";
  etd.saisie();
  ajouterTrie( liste, etd );
  afficherListe( liste );


  cout << "\n====== Le rang d'un etudiant dans la liste (en fonction de son nom) ======\n";
  string name;
  cout << "Entrez le nom : "; cin >> name;
  cout << "Son rang : " << rangListe( liste, name ) << endl;

  cout << "\n====== Moyenne des notes ======\n";
  cout << "La moyenne des notes : " << moyenneNotes( liste ) << endl;
  */

  
  
  return EXIT_SUCCESS;
}

