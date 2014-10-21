#include "JoueurNoir.h"


JoueurNoir::JoueurNoir(Echiquier* echiq)
  : Joueur(false, echiq)
{
  //cout << "Constructeur par defaut::JoueurNoir" << endl;
}


JoueurNoir::~JoueurNoir()
{
  //cout << "Destructeur::JoueurNoir" << endl;
}

void JoueurNoir::Init()
{}
