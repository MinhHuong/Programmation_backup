#include "Complexe.h"
#include <iostream>
#include <string>
using namespace std;

void cinNombre(float& a, float& b, Complexe& c) {
  cout << "Entrez le reel puis l'imaginaire : ";
  cin >> a >> b;
  c.setReel(a); c.setImaginaire(b);
}


int main() {
  char choix;
  float reel, img;
  Complexe c1, c2, result;

  while (choix != 'n') {
    menu();
    cout << "\nVotre choix : "; cin >> choix;

    switch(choix) {
    case '1': // ecrire le nombre
      {
	cinNombre(reel, img, c1);
	break;
      }

    case '2': //afficher le nombre
      {
	cout << c1.toString() << endl;
	break;
      }

    case '3': // additionner
      {
	cinNombre(reel, img, c2);
	c1.plus(c2, result);
	cout << result.toString() << endl;
	break;
      }
      
    case '4': // multiplier
      {
	cinNombre(reel, img, c2);
	c1.fois(c2, result);
	cout << result.toString() << endl;
	break;
      }

    default:
      {
	cout << "Option non determinee.";
	break;
      }
    }

    cout << "\nVoulez-vous continuer (y/n) : ";
    cin >> choix;
  }
  
  return 0;
}
