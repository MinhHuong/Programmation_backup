#include "Boite.h"
#include <iostream>
#include <string>
using namespace std;

void menu();
void cinPoint(float& abs, float& ord);


int main() {
  float x, y;
  cout << "\n***** Entrez un point quelconque pour initialiser la boite *****\n\n";
  cinPoint(x,y);
  Point p(x,y);
  Boite boite(p);

  char choix;
  while (choix != 'n') {
    menu();
    cout << "\nVotre choix : "; cin >> choix;
    switch(choix) {
    case '1': // ajouter un point
      {
	cinPoint(x,y);
	p.setX(x); p.setY(y);
	boite.ajouterPoint(p);
	break;
      }
      
    case '2': // supprimer un point
      {
	cinPoint(x,y);
	p.setX(x); p.setY(y);
	boite.supprimerPoint(p);
	break;
      }
      
    case '3': // afficher les info de la boite
      {
	boite.affiche();
	break;
      }

    default: // autre choix
      {
	cout << "Non determine. Reessayez" << endl;
	break;
      }
    }
    
    cout << "\nVoulez-vous continuer ? (y/n) : ";
    cin >> choix;
  }
  
  return 0;
}


void menu() {
  cout << "\n_____________ BOITE ENGLOBANTE _____________\n\n"
       << "   1. Ajouter un point" << endl
       << "   2. Supprimer un point" << endl
       << "   3. Afficher les informations de la boite" << endl << endl
       << "--------------------*******--------------------" << endl;
}

void cinPoint(float& abs, float& ord) {
  cout << "Entrez le point (x puis y) : ";
  cin >> abs >> ord;
}
