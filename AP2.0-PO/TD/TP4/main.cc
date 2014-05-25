#include <iostream>
#include <string>
#include <istream>
#include <cstdlib>
#include <unistd.h>
#include <termios.h>
#include "Peinture.h"
#include "Sculpture.h"
#include "Livre.h"
#include "util.h"
#include "Gestion.h"

void menu() {
  cout << "\n========== GESTION DES OEUVRES ========== " << endl
       << "1. Ajouter une peinture" << endl
       << "2. Ajouter une sculpture" << endl
       << "3. Ajouter un livre" << endl
       << "4. Changer le possesseur d'une peinture / d'une sculpture" << endl
       << "5. Changer la date d'acquis d'une peinture / d'une sculpture" << endl
       << "6. Afficher l'information d'une oeuvre a une indice choisie" << endl
       << "7. Afficher toutes les oeuvres (seulement leur titre)" << endl
       << "8. Quitter" << endl
       << "=========================================\n";
}

using namespace std;

int main()
{
  Gestion gestion;
  
  string auteur, titre, style, poss, sup, matiere, materiau, lang, theme, editeur;
  int j, m, a, ja, ma, aa, je, me, ae;
  int value;
  int ind = 0;
  
  char choix;
  
  while (choix != '8') {
    //sleep(2);
    menu(); 
    cout << "Votre choix : "; 
    cin >> choix;

    switch(choix) {
    case '1': // ajouter une peinture 
      cinPlastique(auteur, titre, style, j, m, a, value, poss, ja, ma, aa);
      cinPeinture(sup, matiere);
      gestion.addOeuvre(new Peinture(auteur, titre, style, j, m, a, value, poss, ja, ma, aa, sup, matiere));  
      break;

    case '2': // ajouter une sculpture
      cinPlastique(auteur, titre, style, j, m, a, value, poss, ja, ma, aa);
      cinSculpture(materiau);
      gestion.addOeuvre(new Sculpture(auteur, titre, style, j, m, a, value, poss, ja, ma, aa, materiau));
      break;

    case '3': // ajouter un livre
      cinLivre(auteur, titre, style, j, m, a, value, lang, theme, editeur, je, me, ae);
      gestion.addOeuvre(new Livre(auteur, titre, style, j, m, a, value, lang, theme, editeur, je, me, ae));
      break;

    case '4': // changer le possesseur 
      cinPosition(ind);
      cinPossesseur(poss);
      gestion.set_possesseur(ind, poss);
      break;

    case '5': // changer la date d'acquis
      cinPosition(ind);
      cinDate(ja, ma, aa);
      gestion.set_date_acquis(ind, ja, ma, aa);
      break;

    case '6': // afficher les informations d'une oeuvre a une indice choisie
      cinPosition(ind);
      gestion.print_Oeuvre(ind);
      break;

    case '7': // afficher tous les titres
      gestion.print_all_title();
      break;
   
    case '8': //quitter
      exit(-1);
      break;
    }
  }

  return EXIT_SUCCESS;
}

