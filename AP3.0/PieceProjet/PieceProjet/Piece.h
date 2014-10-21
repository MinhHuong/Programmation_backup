#pragma once
#ifndef _PIECE_
#define _PIECE_

#include <iostream>
#include <string>
#include "Echiquier.h"
#include "util.h"

using namespace std;

class Echiquier;

class Piece
{
 protected:
  int _x, _y;
  string _nom;
  bool _isWhite;
  static int _compteur;

 public:
  Piece();
  Piece(int, int, string, bool);
  Piece(bool);
  Piece(string);
  ~Piece();

  void afficher();

  int getY() const;
  int getX() const;
  string getNom() const;
  bool isWhite() const;
  static int getCompteur();

  void setX(int);
  void setY(int);
  void setNom(string);
  void setPart(bool);

  bool validerEndroit() const;

  virtual bool deplacement( Echiquier& , int, int) const = 0;
  bool capter( Echiquier&, int, int ) const;
  virtual bool enMat( Echiquier & ) const = 0;

  Piece& operator=( const Piece & p );
};

#endif
