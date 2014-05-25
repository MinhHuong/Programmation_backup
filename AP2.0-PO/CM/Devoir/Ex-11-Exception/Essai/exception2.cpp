/****************************************************************************
 * Fichier: Main.cpp
 * Auteur: William Bussiere
 * Date: 12 mai 2011
 * Description: Attraper des exceptions de meme famille dans un seul bloc try
 ****************************************************************************/

#include <iostream>
#include <stdexcept>
#include <vector>
using namespace std;


/****************************************************************************
 * Fonction:	etudierLimite
 * Description: Pour etudier la limite d'une fonction
 *				Son vrai role est de retourner une erreur en cas 
 *				de division par zero
 * Paramètres:	- (double) x : parametre bidon1 (IN)
 *				- (double) y : parametre bidon2 (IN)
 * Retour:		(double) la valeur de la limite
 ****************************************************************************/
double etudierLimite(double x, double y)
{
  // Evalue s'il n'y aura pas de division par zero
  if (x == y)
    throw logic_error("Division par zero");

  return ( (x+y)/(x-y) );
}


/****************************************************************************
 * Fonction: testerVecteur
 * Description: Tente de produire une exception de la classe vecteur
 * Paramètres:	- (double) x : parametre bidon1 (IN)
 *		- (double) y : parametre bidon2 (IN)
 * Retour: aucun
 ****************************************************************************/
void testerVecteur(double x, double y)  
{
  vector <int> vecteur;
  int *indiceErrone; // Declare ici, il est accessible dans le try et le catch

  try
    {
      indiceErrone=new int(9);
      cout << vecteur.at(*indiceErrone);
      delete indiceErrone; // <-Pas exécuté si exception à la ligne précédente.
    }
  catch(out_of_range &erreur)
    {
      cout << "il y a exception avec STL" << " " << erreur.what() << endl;

      delete indiceErrone;	// Nettoye la mémoire
      indiceErrone=NULL;			// Indique que le pointeur n'est plus valide
      throw;					// Relance l'exception
    }
}



int main() 
{
  double a, b=2.0;
  cout << "a=2.0 pour exception logic, a=1.0 pour erreur STL" << endl;
  cout << "Entrez a: ";
  cin >> a;
  cout << endl << endl;

  // Ce bloc teste les deux fonctions
  try 
    {
      if( a == 1.0 )
	testerVecteur(a,b);

      cout << etudierLimite(a,b) 
	   << endl;
    }

  // Doit être avant, car c'est une classe dérivée de logic_error
  catch (out_of_range &erreur)
    {
      cout << "stl::erreur " << erreur.what() << endl;
    }
  // Toutes les autres erreurs de type ou derivees de logic_error
  catch (logic_error &erreur)
    {
      cout << erreur.what() << endl;
    }

  cout << "Termine!" << endl << endl;


  return 0;
}
