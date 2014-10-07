#pragma once
#include <iostream>
#include <fstream>
#include <istream>
#include <string>
#include "Piece.h"

using namespace std;

class Joueur
{
private:
	string _nom;
	bool _isWhite;
	Piece tabPieces[16];

public:
	Joueur();
	Joueur(string, bool);
	~Joueur();

	int getCompteur() const;
};

