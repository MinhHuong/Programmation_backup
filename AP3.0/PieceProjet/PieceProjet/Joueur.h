#pragma once
#ifndef _JOUEUR_
#define _JOUEUR_

#include <iostream>
#include <fstream>
#include <istream>
#include <string>
#include "Piece.h"
#include "Echiquier.h"

using namespace std;

class Joueur
{
private:
	string _nom;
	bool _isWhite;
	Echiquier* echiq;

public:
	Joueur();
	Joueur(string, bool);
	~Joueur();
};

#endif