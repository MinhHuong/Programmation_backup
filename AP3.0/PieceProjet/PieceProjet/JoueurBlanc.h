#pragma once

#ifndef _JOUEUR_BLANC_
#define _JOUEUR_BLANC_

#include "Joueur.h"
#include <iostream>

using namespace std;

class JoueurBlanc : public Joueur
{
 public:
  JoueurBlanc(Echiquier*);
  ~JoueurBlanc();

  virtual void Init();
};

#endif
