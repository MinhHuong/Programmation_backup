#pragma once

#ifndef _JOUEUR_NOIR_
#define _JOUEUR_NOIR_

#include "Joueur.h"

#include <iostream>

using namespace std;

class JoueurNoir : public Joueur
{
 public:
  JoueurNoir(Echiquier*);
  ~JoueurNoir();

  virtual void Init();
};

#endif
