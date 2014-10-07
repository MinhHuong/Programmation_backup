#include "Joueur.h"

Joueur::Joueur()
{
	_nom = "non défini";
	_isWhite = false;
}

Joueur::Joueur(string n, bool white)
{
	cout << "Contructeur avec paramètres" << endl;

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
	for(int y = complement ; compteur > 0 ; y -= change)
	{
		for(int x = 0 ; x < 8 ; x++)
		{
			tabPieces[num].setX(x);
			tabPieces[num].setY(y);
			num++;
		}
		compteur--;
	}
	
	for(int i = 0 ; i < 8 ; i++)
		tabPieces[i].setNom("Pion");
	int temp = 7;
	int ptr_name = 0;
	string name[] = { "Fou", "Cavalier", "Tour" };
	for(int i = 8 ; i < 16 && ptr_name <= 2 ; i++)
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
