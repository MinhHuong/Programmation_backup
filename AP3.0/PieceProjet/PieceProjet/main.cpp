#include <iostream>
#include <string>
#include <cstdlib>
#include <stdexcept>
#include <typeinfo>

#include "Piece.h"
#include "Roi.h"
#include "Dame.h"
#include "Tour.h"
#include "Cavalier.h"
#include "Fou.h"
#include "Pion.h"

#include "Joueur.h"
#include "JoueurBlanc.h"
#include "JoueurNoir.h"

#include "Echiquier.h"

using namespace std;

int main()
{
  Echiquier echiq;
  JoueurNoir jn( &echiq );
  JoueurBlanc jb( &echiq );

  /* Utilisation des exceptions */
  // try
  //   {
  //     JoueurNoir jn_bis( &echiq );
  //   }
  // catch( logic_error & e )
  //   {
  //     cout << e.what() << endl;
  //   }

  int x, y, x_dest, y_dest;
  Piece *p, *p_capte;
  string msg = "";
  bool tourDe = true; // true pour JoueurBlanc, false pour JoueurNoir
  bool run = true; // true si aucune regle n'est enfreinte

  do 
    {
      do 
	{
	  system("clear");
      
	  cout << msg << endl << endl;
	  echiq.affiche_bis();
	  coutPart( tourDe );
      
	  cinPosition( "choisir 1 Piece ( 0 0 pour quitter )", x, y );
	  if( x == 0 && y == 0 ) break;
	  else p = echiq.getPiece( x, y );

	  if( p != NULL && p->isWhite() == tourDe )
	    {
	      p->afficher();
	      cinPosition( "choisir sa nouvelle position", x_dest, y_dest );

	      if( echiq.deplacer( p, x_dest, y_dest ) && p->deplacement( echiq, x_dest, y_dest ) )
		{
		  //Capter une Piece de l'autre Joueur
		  if( p->capter( echiq, x_dest, y_dest ) )
		    {
		      p_capte = echiq.getPiece( x_dest, y_dest );
		      echiq.enlever( x_dest, y_dest );
		    }

		  //Pion arrive a l'autre bout
		  if( typeid(*p) == typeid(Pion) )
		    {
		      if( p->isWhite() ) 
			{
			  if( p->getY() == 8 )
			    {
			      Piece* transform = new Dame( p->getX(), p->getY(), p->isWhite() );
			      echiq.enlever( x_dest, y_dest );
			      echiq.placerPiece( transform );
			    }
			}
		    }
	      
		  echiq.deplacerPiece( p, x_dest, y_dest );
		  msg = "";
		  run = true;
		}
	      else
		{
		  msg = "\nMouvement invalide";
		  run = false;
		}
	    }
	  else
	    {
	      msg = "\nPiece selectionnee invalide ( soit inexistante, soit appartenant a l'autre Joueur )";
	      run = false;
	    }
	} while ( !run );

      tourDe = !tourDe;
    }
  while ( x != 0 && y != 0 );
  

  cout << "\n***** Au revoir *****\n\n";
  return 0;
}
