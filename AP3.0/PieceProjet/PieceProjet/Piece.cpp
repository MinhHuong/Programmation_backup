#include "Piece.h"
#include <iostream>
#include <fstream>
#include <istream>
#include <string>

using namespace std;

Piece::Piece()
{
	_x = _y = -1;
	_nom = "";
	//cout << "Constructeur par defaut" << endl;
}

Piece::Piece(int x, int y, string n, bool white)
{
	_x = x;
	_y = y;
	_nom = n;
	_isWhite = white;
	cout << "Constructeur avec paramètres" << endl;
}

Piece::~Piece()
{
	//cout << "Destructeur de la pièce" << endl;
}

void Piece::afficher()
{
	cout << "Position (" << _x << " , " << _y << " )" << endl;
	cout << "Nom : " << _nom << endl;
}

int Piece::getY() const
{
	return _y;
}

int Piece::getX() 
{
	return _x;
}

bool Piece::isWhite() const
{
	return _isWhite;
}

string Piece::getNom() const
{
	return _nom;
}

void Piece::setX(int x)
{
	_x = x;
}

void Piece::setY(int y)
{
	_y = y;
}

void Piece::setNom(string n)
{
	_nom = n;
}

bool Piece::validerEndroit() const
{
	return ( _x >= 1 && _x <= 8 && _y >= 1 && _y <= 8 );
}