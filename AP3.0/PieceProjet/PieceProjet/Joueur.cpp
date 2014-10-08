#include "Joueur.h"
#include <cstdlib>
#include <stdio.h>

Joueur::Joueur()
{
	_nom = "non défini";
	_isWhite = false;
}

Joueur::Joueur(string n, bool white)
{
	Piece tabPieces[16];
	cout << "Contructeur avec paramètres::Joueur" << endl;

	_nom = n;
	_isWhite = white;
	
	int complement, change;
	if(_isWhite)
	{
		complement = 1;
		change = 1;
	}
	else
	{
		complement = 6;
		change = -1;
	}

	int num = 0, compteur = 2;
	int y = complement;
	// affecter les ordonnées
	while(compteur > 0)
	{
		for(int x = 0 ; x < 8 ; x++)
		{
			tabPieces[num].setX(x);
			tabPieces[num].setY(y);
			num++;
		}
		y -= change;
		compteur--;
	}
	
	// affecter le nom des Pièces à des positions correspondantes
	// les Pions
	for(int i = 0 ; i < 8 ; i++)
		tabPieces[i].setNom("Pion");

	// Fou, Cavalier, Tour
	int temp = 7; // les distance entre 2 Pièces identiques
	int ptr_name = 0; // pointeur vers les positions dans le tableau name[]
	string name[] = { "Fou", "Cavalier", "Tour" };
	for(int i = 8 ; ptr_name <= 2 ; i++)
	{
		tabPieces[i].setNom(name[ptr_name]);
		tabPieces[i + temp].setNom(name[ptr_name]);
		temp -= 2;
		ptr_name++;
	}

	tabPieces[11].setNom("Dame");
	tabPieces[12].setNom("Roi");

	for( int i = 0 ; i < 16 ; i++ )
	{
		if( echiq->placer(&tabPieces[i]) )
		{
			
		}
	}
}

Joueur::~Joueur()
{
	cout << "Destructeur du Joueur" << endl;
}
