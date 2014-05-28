#include <iostream>
#include "Pile.h"
using namespace std;

void affichePile(Pile<int> p) 
{
  int elem = 0;

  while ( !p.pileVide() ) 
    {
      elem = p.valeurSommet();
      cout << elem << endl;
      p.depiler();
    }
}


void compter(Pile<int> p)
{
  int nb=0;

  while ( !p.pileVide() ) 
    {
      nb++;
      p.depiler();
    }

  cout << "Le nombre d'elements " << nb << endl;
}


void clonerPile(Pile<int> p, Pile<int> & p_clone)
{
  Pile<int> temp;

  while ( !p.pileVide() )
    {
      temp.empiler( p.valeurSommet() );
      p.depiler();
    }

  while ( !temp.pileVide() ) 
    {
      p_clone.empiler( temp.valeurSommet() );
      temp.depiler();
    }
}

void inverserPile(Pile<int> & p) 
{
  Pile<int> temp;
  clonerPile(p, temp);

  while ( !p.pileVide() ) 
    {
      p.depiler();
    }

  while ( !temp.pileVide() )
    {
      p.empiler( temp.valeurSommet() );
      temp.depiler();
    }
}

void eraseNegative(Pile<int> & p) 
{
  Pile<int> temp;
  clonerPile(p, temp);
  inverserPile(temp);
  
  while ( !p.pileVide() )
    {
      p.depiler();
    }

  int valeur;
  while ( !temp.pileVide() )
    {
      valeur = temp.valeurSommet();
      if ( valeur >= 0 )
	p.empiler( valeur );
      temp.depiler();
    }
}

int main() {
  Pile<int> my_pile;
  int val, i=0;
 
  while(i<5) 
    {
      cout << "Nouvelle valeur : ";
      cin >> val;
      my_pile.empiler(val);
      i++;
    }
  
  affichePile(my_pile);
  
  return 0;
}
