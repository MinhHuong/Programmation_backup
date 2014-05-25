/****************************************************************************
 * Fichier: main.cpp
 * Auteur: William Bussiere
 * Date: 8 juin 2011
 * Description: Solutionnaire de l 'exercice sur le traitement des exceptions 
 *				avec des pointeurs.
 ****************************************************************************/

#include <iostream>
#include <string>
using namespace std;


class Poisson {
public :
  Poisson() {
    cout << "Construction d'un poisson" << endl;
  }
  
  ~Poisson() {
    cout << "Destruction d'un poisson" << endl;
  }
};


int main() {
  try {
    Poisson* poisson = 0; // Poiteur a desallouer
    
    try {
      poisson = new Poisson();
      throw string("Eau gelee");
    }
    catch( char c ) {
      cout << "Throw char : " << c << endl;
    }
    catch( float f ) {
      cout << "Throw float : " << f << endl;
    }
    catch (...) {
      delete poisson;
      throw;	// relance de l'exception vers les niveaux superieurs
    }

    delete poisson;
  }
  catch( string s ) {
    cout << s << endl;
  }

  return 0;
}
