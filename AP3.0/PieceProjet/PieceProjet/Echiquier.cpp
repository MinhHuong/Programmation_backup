/** 
 * Mise en oeuvre de Echiquier.h
 *
 * @file Echiquier.cpp
 */

#include <iostream>
// A besoin de la declaration de la classe
#include "Echiquier.h"
#include "Piece.h"
#include <string>
#include <fstream>
#include <istream>
#include <ctype.h>

using namespace std;

/**
 * Constructeur par défaut.
 * Initialise à vide l'echiquier.
 */
Echiquier::Echiquier()
{
  //cout << "Echiquier::Constructeur par defaut" << endl;

  for( int i = 0 ; i < 64 ; i++ )
    m_cases[i] = NULL;
}


/**
 * Recupere la piece situee sur une case.
 *
 * @param x un entier entre 1 et 8
 * @param y un entier entre 1 et 8
 *
 * @return 0 si aucune piece n'est sur cette case et un pointeur
 * vers une piece sinon.
 */
Piece* Echiquier::getPiece( int x, int y )
{
  if( x >= 1 && x <= 8 && y >= 1 && y <= 8 )
    {
      int place = (x-1) + (y-1)*8;
      return m_cases[place];
    }
  else
    {
      return NULL;
    }
}

Piece* Echiquier::getPiece( int num )
{
  if( num >= 0 && num < 64 ) 
    return m_cases[num];
  else
    return NULL;
}


/**
 * Place une piece sur l'echiquier, aux coordonnees specifiees dans la piece.
 *
 * @param p un pointeur vers une piece
 *
 * @return 'true' si le placement s'est bien passe, 'false' sinon
 * (case occupee, coordonnees invalides, piece vide )
 */
bool Echiquier::placer( Piece* p )
{
  return ( p->validerEndroit() && getPiece(p->getX(), p->getY()) == 0 && p->getNom() != "" );
}


/**
 * Placer une pièce dans l'échiquier (l'initialisation)
 */
void Echiquier::placerPiece( Piece* p )
{
  int x = p->getX()-1, y = p->getY()-1; 
  m_cases[x + y*8] = p; 
}


/**
 * Deplace une piece sur l'echiquier, des coordonnees specifiees
 * dans la piece aux coordonnees x,y. 
 *
 * @param p un pointeur vers une piece
 * @param x un entier entre 1 et 8
 * @param y un entier entre 1 et 8
 *
 * @return 'true' si le placement s'est bien passe, 'false' sinon
 * (case occupee, coordonnees invalides, piece vide, piece pas
 * presente au bon endroit sur l'echiquier)
 */
bool Echiquier::deplacer( Piece* p, int x, int y )
{
  return ( p->validerEndroit() && x >= 1 && x <= 8 && y >= 1 && y <= 8 );
}

void Echiquier::deplacerPiece( Piece* p, int x, int y)
{
  int x_org = p->getX(), y_org = p->getY();
  m_cases[ (x_org-1) + (y_org-1)*8 ] = NULL;

  p->setX( x );
  p->setY( y );
  m_cases[ (x-1) + (y-1)*8 ] = p;
}

/**
 * Enleve la piece situee sur une case (qui devient vide).
 *
 * @param x un entier entre 1 et 8
 * @param y un entier entre 1 et 8
 *
 * @return 0 si aucune piece n'est sur cette case et le pointeur
 * vers la piece enlevee sinon.
 */
Piece* Echiquier::enleverPiece( int x, int y )
{
  return getPiece(x, y);
}

// enlever la piece a la position (x,y)
void Echiquier::enlever( int x, int y )
{
  if( getPiece(x,y) != NULL )
    {
      m_cases[(x-1) + (y-1)*8] = NULL;
    }
}


/**
 * Affiche l'echiquier avec des # pour les cases noires et . pour
 * les blanches si elles sont vides, et avec B pour les pieces
 * blanches et N pour les pieces noires.
 */
void Echiquier::affiche()
{
  cout << endl << "  12345678" << endl;
  char tmp;

  for ( int y = 1; y <= 8; y++ )
    {
      cout << y << " ";
      for ( int x = 1; x <= 8; x++ )
	{
	  char c;
	  Piece* p = getPiece( x, y );
	  if ( p == 0 ) 
	    c = ( ( x + y ) % 2 ) == 0 ? '#' : '.';
	  else
	    {
	      tmp = p->getNom()[0];
	      c = p->isWhite() ? tmp : tolower(tmp);
	    }
	  cout << c;
	}
      cout << " " << y << endl;
    }

  cout << "  12345678" << endl << endl;
}


/**
 * Désallouer le tableau des pointeurs
 *
 */
Echiquier::~Echiquier()
{
  //cout << "Destructeur::Echiquier" << endl;

  //pas necessaire d'appeler "delete" parce que le tableau des pointeurs sera tout supprime, a propos des pieces vers lesquels pointe ce tableau, ils seront aussi supprimes une fois le destructeur de la classe Joueur appele
}

void Echiquier::affiche_bis()
{
  string piece;
  char tmp;
  Piece* p;

  for( int y = 0 ; y <= 18 ; y++ )
    {
      if( y % 2 == 0 && y != 0 && y != 18 )
	{
	  cout << " " << y/2 << "  ";
	}
      else
	{
	  cout << "    ";
	}
      for( int x = 1 ; x <= 8 ; x++ )
	{ 
	  if( y == 0 || y == 18 )
	    {
	      cout << "  " << x << " ";
	    }
	  else if( y % 2 == 0 )
	    {
	      cout << "|";
	      p = getPiece( x, y/2 );

	      if( p != NULL )
		{
		  tmp = ( p->getNom() )[0];
		  tmp = p->isWhite() ? tmp : tolower(tmp);
		  piece = " " + string(1, tmp) + " ";
		}
	      else
		{
		  piece = ( x + y/2 ) % 2 == 0 ? " # " : " . ";
		}

	      cout << piece;
	    }
	  else
	    {
	      cout << "+---";
	    }

	  if( x == 8 && y != 0 && y != 18 )
	    {
	      if( y % 2 == 0 ) cout << "|  " << y/2;
	      else cout << "+";
	    }
	}

      cout << endl;
    }
}
