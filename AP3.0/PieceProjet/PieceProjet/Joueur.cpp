#include "Joueur.h"
#include <cstdlib>
#include <stdio.h>
#include <stdexcept>

int Joueur::_nbJoueur = 0;

Joueur::Joueur()
{
  _isWhite = false;
  _nbJoueur++;
}

Joueur::Joueur(bool w, Echiquier* echiq)
{
  _nbJoueur++;
  
  if( _nbJoueur > 2 )
    {
      logic_error annonce("Impossible de creer de plus de 2 Joueurs");
      throw annonce;
    }
  else
    {
      _isWhite = w;

      int lignePion = _isWhite ? 2 : 7;
      int ligneRoi = _isWhite ? 1 : 8;

      for( int i = 0 ; i < 8 ; i++ )
	{
	  tabPieces[i] = new Pion( i+1, lignePion, _isWhite );
	}

      for( int i = 8 ; i < 16 ; i++ )
	{
	  if( i == 8 || i == 15 )
	    tabPieces[i] = new Tour( i-7, ligneRoi, _isWhite );
	  if( i == 9 || i == 14 )
	    tabPieces[i] = new Cavalier( i-7, ligneRoi, _isWhite );
	  if( i == 10 || i == 13 )
	    tabPieces[i] = new Fou( i-7, ligneRoi, _isWhite );
	  if( i == 11 )
	    tabPieces[i] = new Dame( i-7, ligneRoi, _isWhite );
	  if( i == 12 )
	    tabPieces[i] = new Roi( i-7, ligneRoi, _isWhite );
	}

      for(int i = 0 ; i < 16 ; i++ )
	{
	  tabPieces[i]->setPart(_isWhite);
      
	  if( echiq->placer( tabPieces[i]) )
	    echiq->placerPiece( tabPieces[i]);
	}
    }
}


Joueur::~Joueur()
{
  //cout << "Destructeur du Joueur" << endl;
  _nbJoueur--;
}

bool Joueur::getPart() const
{
  return _isWhite;
}

void Joueur::setPart(bool w)
{
  _isWhite = w;
}

void Joueur::afficher() const
{
  string part = _isWhite ? "Blanc" : "Noir";
  cout << "Je suis le " << _nbJoueur << "e joueur" << " et je choisis la couleur " << part << endl;
}
