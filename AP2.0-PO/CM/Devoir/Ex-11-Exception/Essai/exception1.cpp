/****************************************************************************
 * Fichier: Main.cpp
 * Auteur: William Bussiere modifié par njournet
 * Date: 20 mai 2011
 * Description: Generation et manipulation d'exceptions standards
 ****************************************************************************/

//#include <exception>
#include <stdexcept>
#include <vector>
#include <iostream>
#include <typeinfo>
using namespace std;


/****************************************************************************
 * Fonction:	erreurLogique
 * Description: Produit une exception de la classe logic_error
 *				Principalement pour demontrer le lancement d'exception depuis
 *				une fonction
 * Paramètres:	aucun
 * Retour:		aucun
 ****************************************************************************/

void erreurLogique()
  throw(logic_error)
{
  float reponse	= 2.001f; // le f a la fin du nombre specifie que c'est un float
  float operande1 = 1.251f;
  float operande2 = 0.750f;

  // Ne jamais tester l'egalite entre des floats
  if( reponse != operande1 + operande2 )
    throw logic_error ("2.001 != 1.251 + 0.750");

  // Cette exception sera lancee seulement si la premiere ne l'est pas
  // Le lancement d'exception termine abruptuement le deroulement d'une fonction
  throw "Une simple exception";
}



int main( void)
{
  // Manipulation simple d'une exception de base //
  /*
  try {
     throw logic_error("Une simple exception");
    // erreurLogique();
  }
  catch ( exception &e ) {
    cout << "Exception : " << e.what() << endl;
    }*/

  

  // Manipulation d'une exception provenant d'une fonction //
  /*
  try {
    erreurLogique();
  }
  catch ( logic_error &e ) {
    cout << "Erreur de logique : " << e.what() << endl;
  }
  catch ( exception &e ) {
    cout << "Exception provenant d'une fonction : " << e.what() << endl;
  }
  */
  
  /*
  // Manipulation d'une exception avec catch dans ordre différent --> warning
  try {
    erreurLogique();
  }
  catch ( exception &e ) {
    cout << "Exception provenant d'une fonction : " << e.what() << endl;
  }
  catch ( logic_error &e ) {
    cout << "Erreur de logique : " << e.what() << endl;
    }
  */
  	
  //ordre des catch
  /*try
    {
      // créer un tableau de taille 10
      std::vector<int> tableau( 10 );
      // accéder au 11° élément
      tableau.at( 10 );
    }
  catch ( const std::bad_alloc & )
    {
      cout << "Erreur : memoire insuffisante.\n";
    }
  catch ( const std::out_of_range & )
    {
      cout << "Erreur : debordement de memoire.\n";
      }
  catch ( const std::exception & Exp )
    {
      cout << "Erreur : " << Exp.what() << ".\n";
      }
  catch ( ... ) // traite toutes les autres exceptions
    {
      cout << "Erreur inconnue.\n";
      }*/


  //Cascade
  /*
  try {
    int a=3;
    try {
      erreurLogique();
    }
    catch( logic_error &e) {
      cout << "premier niveau" << endl;
      throw e;
    }
		
  }
  catch ( logic_error &e ) {
    cout << "second niveau : " << e.what() << endl;
  }
  */

	
  
  // Exception de mauvaise allocation de memoire
  /*
  int* intArray = new int[10];
  try {
    int nbInts;

    cout << "Entrez 1000000000 (1 milliard) : ";
    cin >> nbInts;
    //int* intArray;
    intArray = new int[ nbInts ];

    delete [] intArray;
  }
  catch ( bad_alloc &e ) {
    cout << e.what() << endl;
    delete [] intArray;
    // Pas besoins de liberer la memoire de intArray
    // puisque new n'a rien reserve.
  }
  cout << endl;
  */

  // Utilisation du catch(...)
  
  try {
    int* boites = 0;

    try {
      boites = new int(5);
      throw int(4);
    }

    catch ( exception &e ) {
      // Ce catch n'attrapera pas l'exception puisqu'elle n'en derive pas
      cout << "Erreur simple." << endl;

      delete boites;
      boites = 0;
    }
    catch(...)
      {
	// Liberation de la memoire avant la relance vers le niveau superieur
	delete boites;
	boites = 0;

	cout << "Exception attrapee au premier niveau" << endl;
	throw; // relance la meme exception
      }
  }
  catch(int e){
    cout << "Exception attrapee au deuxieme niveau." << endl;
  }
  cout << endl;

  return 0;
}
