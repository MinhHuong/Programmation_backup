#include "gestion.h"

// 36.1 : ===============================
void saisirListe(Liste<Etudiant> & l) 
{
  int size;
  cout << "Le nombre d'etudiants : ";
  cin >> size;

  Etudiant etd;
  l.insererEnTete( etd );
  
  TAdresse adr = l.adressePremier();
  
  for (int i=0 ; i<size ; i++)
    {
      etd.saisie();
      l.insererApres( etd, adr );
      adr = l.adresseSuivant( adr );
    }

  l.supprimerEnTete();
}

// 36.2 : =================================
void afficherListe(Liste<Etudiant> l)
{
  TAdresse adr = l.adressePremier();

  while ( adr != l.null() )
    {
      cout << *adr << endl;
      adr = l.adresseSuivant( adr ); 
    }
}

// 36.3 : ==================================
int rangListe( Liste<Etudiant> l, string nom )
{
  int rang=0;

  TAdresse adr = l.adressePremier();
  
  while ( adr != l.null() )
    {
      if ( nom==adr->nom() )
	{
	  rang++;
	  return rang;
	}
      
      rang++;
      adr = l.adresseSuivant( adr );
    }

  return 0;
}

// 36.4 : =================================
float moyenneNotes( Liste<Etudiant> l )
{
  float somme=0, cpt=0;

  TAdresse adr = l.adressePremier();

  while ( adr != l.null() )
    {
      somme += adr->note();
      cpt++;
      
      adr = l.adresseSuivant( adr );
    }

  return ( somme/cpt );
}

// 37.1 : ==================================
void ajouterTrie( Liste<Etudiant> & l, Etudiant etd )
{
  float note = etd.note();
  int cpt=0;

  TAdresse adr = l.adressePremier(), temp=l.null();

  while ( adr != l.null() )
    {
      if ( note > adr->note() ) 
	{
	  temp = adr;
	  adr = l.adresseSuivant( adr );
	}
      else
	break;
    }

  if ( temp != l.null() )
    l.insererApres( etd, temp );
  else
    l.insererEnTete( etd );
}

// 37.2 : ===================================
bool estTrie( Liste<Etudiant> l )
{
  TAdresse adr = l.adressePremier(), next = l.adresseSuivant( adr );

  while ( next != l.null() )
    {
      if ( adr->note() > next->note() )
	return false;
      else
	{
	  adr = l.adresseSuivant( adr );
	  next = l.adresseSuivant( next );
	}
    }
  
  return true;
}

// 37.3 : ===================================
void fusionnerListe( Liste<Etudiant> L1, Liste<Etudiant> L2, Liste<Etudiant> & L3 )
{
  TAdresse adr_1 = L1.adressePremier(), adr_2 = L2.adressePremier(), adr_3 = L3.adressePremier();

  float note_1, note_2;

  Etudiant fictif;
  L3.insererEnTete( fictif );
  
  while ( adr_1 != L1.null() && adr_2 != L2.null() )
    {
      note_1 = adr_1->note();
      note_2 = adr_2->note();

      if ( note_1 < note_2 ) 
	{
	  L3.insererApres( *adr_1, adr_3 );
	  adr_1 = L1.adresseSuivant( adr_1 );
	}
      else if ( note_1 > note_2 )
	{
	  L3.insererApres( *adr_2, adr_3 );
	  adr_2 = L2.adresseSuivant( adr_2 );
	}
      else  // note_1 == note_2
	{
	  L3.insererApres( *adr_1, adr_3 );
	  adr_1 = L1.adresseSuivant( adr_1 );
	  adr_2 = L1.adresseSuivant( adr_2 );
	}
      
      adr_3 = L3.adresseSuivant( adr_3 );
    }

  if ( adr_1 == L1.null() )
    {
      while (adr_2 != L2.null() )
	{
	  L3.insererApres( *adr_2, adr_3 );
	  adr_3 = L3.adresseSuivant( adr_3 );
	}
    }
  else if ( adr_2 == L2.null() )
    {
      while (adr_1 != L1.null() )
	{
	  L3.insererApres( *adr_1, adr_3 );
	  adr_3 = L3.adresseSuivant( adr_3 );
	}
    }

  L3.supprimerEnTete();
}

