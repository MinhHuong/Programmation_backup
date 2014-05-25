#include "Rationnel.h"
#include "util.h"
#include <iostream>
using namespace std;

int main() {
  Rationnel r1, r2, resultat;
  int num, deno;
  char choix;
  
  while (choix != 'n') {
    menu();
    cout << "\nVotre choix : "; cin >> choix;
    
    switch(choix) {
    case '1': // ajouter 1 nombre
      {
	cinNombre(num, deno, r1);
	break;
      }

    case '2': // inverser
      {
	r1.inverse();
	r1.affiche();
	break;
      }

    case '3': // tester l'egalite
      {
	cinNombre(num, deno, r2);
	
	if ( r1.egal(r2) )
	  cinResult(r1, r2, resultat, eg);
	else
	  cinResult(r1, r2, resultat, ineg);
	
	break;
      }

    case '4': // additionner
      {
	cinNombre(num, deno, r2);
	r1.plus(r2, resultat);
	cinResult(r1, r2, resultat, add);
	break;
      }

    case '5': // soustraire
      {
	cinNombre(num, deno, r2);
	r1.moins(r2, resultat);
        cinResult(r1, r2, resultat, take);
	break;
      }

    case '6': // multiplier
      {
	cinNombre(num, deno, r2);
	r1.fois(r2, resultat);
        cinResult(r1, r2, resultat, mult);
	break;
      }

    case '7': // diviser
      {
	cinNombre(num, deno, r2);
	r1.diviser(r2, resultat);
        cinResult(r1, r2, resultat, div);
	break;
      }

    case '8': // afficher le nombre
      {
	r1.affiche();
	break;
      }

    default:
      {
	cout << "Option non determinee.";
	break;
      }
    }
    
    cout << "\nVoulez-vous continuer ? (y/n) : ";
    cin >> choix;
  }
  
  return 0;
}
