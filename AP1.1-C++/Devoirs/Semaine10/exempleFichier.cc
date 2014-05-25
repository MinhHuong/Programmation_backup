#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

/******************************************************************************************************************/

void saisir(fstream & f, int i) {
  f.open("test", ios::out);

  if (f.fail()) 
    cerr << "erreur" << endl;

  for (i = 0 ; i < 10 ; i++)
    f << i << " ";

  f.close();
}


void afficher(fstream & f, int nombre) {
  f.open("test", ios::in) ;

  if ( f.fail()) 
    cerr << "erreur" << endl;
  
  f >> nombre;
  while (!f.eof()) {
    cout << "nombre lu = " << nombre << endl;
    f >> nombre;
  }

  f.close();
}


void ajouter(fstream & f, int nombre) {
  f.open("test", ios::out | ios:: app);

  if (f.fail())
    cerr << "erreur" << endl;
  
  for (int nombre = 10 ; nombre < 20 ; nombre++)
    f << nombre << " ";

  f.close();
}
  

/******************************************************************************************************************/

int main() {

  int i, nombre, number;
  fstream f;

  saisir(f, i);
  afficher(f, nombre);
  ajouter(f, number);

  return EXIT_SUCCESS;
}
