#pragma once
#ifndef _JOUEUR_
#define _JOUEUR_

#include <iostream>
#include <stdexcept>
#include <string>

#include "Piece.h"
#include "Roi.h"
#include "Dame.h"
#include "Cavalier.h"
#include "Fou.h"
#include "Tour.h"
#include "Pion.h"

#include "Echiquier.h"

using namespace std;

class Joueur
{
 protected:
  Piece* tabPieces[16];
  bool _isWhite;
  static int _nbJoueur;

 public:
  Joueur();
  Joueur(bool, Echiquier*);
  ~Joueur();

  bool getPart() const;
  void setPart(bool);
  virtual void Init() = 0;

  void afficher() const;
};

#endif
