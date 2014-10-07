#pragma once
#ifndef _PIECE_
#define _PIECE_

#include <iostream>

using namespace std;

class Piece
{
private:
	int _x, _y;
	string _nom;
	bool _isWhite;

public:
	Piece();
	Piece(int, int, string, bool);
	~Piece();

	void afficher();
	int getY() const;
	int getX() const;
	void setX(int);
	void setY(int);
	void setNom(string);
};

#endif