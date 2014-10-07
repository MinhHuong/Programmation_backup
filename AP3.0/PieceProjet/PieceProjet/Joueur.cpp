#include "Joueur.h"

Joueur::Joueur()
{
	_nom = "non d�fini";
	_isWhite = false;
}

Joueur::Joueur(string n, bool white)
{
	cout << "Contructeur avec param�tres" << endl;

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
	// affecter les abcisses
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
	
	// affecter le nom des Pi�ces � des positions correspondantes
	// les Pions
	for(int i = 0 ; i < 8 ; i++)
		tabPieces[i].setNom("Pion");

	// Fou, Cavalier, Tour
	int temp = 7; // les distance entre 2 Pi�ces identiques
	int ptr_name = 0; // pointeur vers les positions dans le tableau name[]
	string name[] = { "Fou", "Cavalier", "Tour" };
	for(int i = 8 ; ptr_name <= 2 ; i++)
	{
		tabPieces[i].setNom(name[ptr_name]);
		tabPieces[i + temp].setNom(name[ptr_name]);
		temp -= 2;
		ptr_name++;
	}

	tabPieces[11].setNom("Reine");
	tabPieces[12].setNom("Roi");
}

Joueur::~Joueur()
{
	cout << "Destructeur" << endl;
}
