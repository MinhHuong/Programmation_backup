#include "JoueurBlanc.h"

JoueurBlanc::JoueurBlanc(Echiquier* echiq)
  : Joueur(true, echiq)
{
  //cout << "Constructeur par defaut::JoueurBlanc" << endl;
}


JoueurBlanc::~JoueurBlanc()
{
  //cout << "Destructeur::JoueurBlanc" << endl;
}

void JoueurBlanc::Init()
{}
