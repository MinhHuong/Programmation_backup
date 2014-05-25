#include "Polygone.h"
using namespace std;

void menu() {
  cout << "\n------- MANIPULATION D'UN POLYGONE -------\n\n" 
       << "   1. Saisir un polygone" << endl
       << "   2. Ajouter un sommet" << endl
       << "   3. Deplacer le polygone" << endl
       << "   4. Calculer le perimetre" << endl
       << "   5. Obtenir un point" << endl
       << "   6. Saisir le polygone depuis un fichier" << endl
       << "   7. Ecrire le polygone dans un fichier" << endl
       << "   8. Afficher les informations du polyonge\n\n"
       << "-------------------------------------------" << endl;
}

void cinPoint(float& abs, float& ord, Point& pt) {
  cout << "Entrez x puis y : ";
  cin >> abs >> ord;
  pt.setX(abs);
  pt.setY(ord);
}

void cinDeplacer(float& abs, float& ord) {
  cout << "Entrez dx puis dy : ";
  cin >> abs >> ord;
}

void cinIndice(int& ind, Polygone& p) {
  int taille = p.getTaille();
  cout << "Indice ( <= " << taille-1 << " ) : ";
  cin >> ind;
}

int main() {
  Polygone pol;
  Point p;
  float x, y, my_dx, my_dy;
  int indice;
  
  char choix;

  while (choix != 'n') {
    menu();

    cout << "\nVotre choix : "; cin >> choix;
    cout << endl;
    
    switch(choix) {
    case '1': // saisir un polygone
      {
	pol.saisie();
	break;
      }

    case '2': // ajouter un sommet
      {
	cinPoint(x, y, p);
	pol.ajoutSommet(p);
	break;
      }

    case '3': // deplacer le polygone
      {
	cinDeplacer(my_dx, my_dy);
	pol.deplace(my_dx, my_dy);
	break;
      }

    case '4': // calculer le perimetre
      {
	cout << "Perimetre = " << pol.Perimetre() << endl;
	break;
      }

    case '5': // obtenir 
      {
	cinIndice(indice, pol);
	cout << pol.getPoint(indice) << endl;
	break;
      }

    case '6': // saisir le polygone a partir d'un fichier
      {
	pol.litFichier("fichier_lit");
	break;
      }

    case '7': // ecrire le polygone dans un fichier
      {
	pol.ecritFichier("fichier_ecrit");
	break;
      }

    case '8': // afficher le polygone
      {
	cout << pol.toString() << endl;
	break;
      }

    default:
      {
	cout << "Option non determinee. Veuillez reessayer.\n";
	break;
      }
    }
    
    cout << "\nVoulez-vous continuer ? (y/n) : "; cin >> choix;
  }
    
  return 0;
}
