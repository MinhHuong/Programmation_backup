#include <cstdlib>
#include <iostream>
#include "Liste.h"
#include "Etudiant.h"
#include "gestion.h"

using namespace std;

void menu()
{
  cout << endl 
       << "*****------------------------------ MENU -----------------------------*****" << endl
       << "|                                                                         |" << endl
       << "|     -1- Saisir une liste d'Etudiants                                    |" << endl
       << "|     -2- Afficher la liste d'Etudiants                                   |" << endl
       << "|     -3- Renvoyer le rang d'un Etudiant dans la liste (selon son nom)    |" << endl
       << "|     -4- Calculer la moyenne de notes des Etudiants                      |" << endl
       << "|     -5- Trier la liste d'Etudiants (selon leur note)                    |" << endl
       << "|     -6- Quitter                                                         |" << endl
       << "|                                                                         |" << endl
       << "*****-----------------------------------------------------------------*****" << endl;
}

void cinChoice( char & choice )
{
  cout << "\n==> Votre choix : ";
  cin >> choice;
}

typedef Liste<Etudiant>::TIterator TAdresse;
 
int main()
{  
  char choix;
  Liste<Etudiant> liste_etd, liste_triee;

  do
    {
      menu();
      cinChoice( choix );
      cout << endl;
      
      switch( choix )
	{
	case '1': // saisir la liste d'Etudiants
	  {
	    saisirListe( liste_etd );
	    break;
	  }

	case '2': // afficher la liste d'Etudiants
	  {
	    cout << "===== Votre liste d'Etudiants =====\n";
	    afficherListe( liste_etd );
	    break;
	  }

	case '3': // renvoyer le rang d'un Etudiant dans le liste ( selon le nom )
	  {
	    string name;
	    cout << "Nom de l'etudiant : \n";
	    cin.ignore();
	    getline( cin, name );
	    
	    if ( rangListe( liste_etd, name )!=0 )
	      cout << "L'etudiant se trouve au " << rangListe( liste_etd, name ) << " de la liste." << endl;
	    else
	      cout << "Cet etudiant n'existe pas dans la liste." << endl;
	    break;
	  }

	case '4': // calculer la moyenne des notes
	  {
	    cout << "La moyenne de notes des Etudiants : " << moyenneNotes( liste_etd ) << endl;
	    break;
	  } 

	case '5': // trier la liste d'Etudiants ( selon la note )
	  {	    
	    trierFauxJuste( liste_etd, liste_triee );
	    afficherListe( liste_triee );
	    break;
	  }

	case '6': // quitter
	  {
	    cout << "Au revoir." << endl;
	    break;
	  }

	default:
	  {
	    cout << "Erreur saisie. Veuillez ressayer." << endl;
	    break;
	  }
	}
    } while ( choix != '6' );

  return EXIT_SUCCESS;
}

