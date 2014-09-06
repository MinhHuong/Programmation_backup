#include "gestion.h"

// 36.1 : ===============================
void saisirListe(Liste<Etudiant> & l) 
{
  int size;
  cout << "Le nombre d'etudiants : ";
  cin >> size;
  cout << endl;

  Etudiant etd;
  l.insererEnTete( etd );
  
  TAdresse adr = l.adressePremier();
  
  for (int i=0 ; i<size ; i++)
    {
      etd.saisie();
      l.insererApres( etd, adr );
      adr = l.adresseSuivant( adr );
      cout << endl;
    }

  l.supprimerEnTete();
}

// 36.2 : =================================
void afficherListe(Liste<Etudiant> l)
{
  TAdresse adr = l.adressePremier();

  while ( adr != l.null() )
    {
      cout << *adr;
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

  if ( next==l.null() )
    return true;

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
  TAdresse adr_1 = L1.adressePremier(), adr_2 = L2.adressePremier();

  Etudiant fictif;
  L3.insererEnTete( fictif );

  TAdresse adr_3 = L3.adressePremier();

  while ( adr_1 != L1.null() )
    {
      ajouterTrie( L3, *adr_1 );
      adr_1 = L1.adresseSuivant( adr_1 );
    }

  while ( adr_2 != L2.null() )
    {
      ajouterTrie( L3, *adr_2 );
      adr_2 = L2.adresseSuivant( adr_2 );
    }

  L3.supprimerEnTete();
}

// sans utiliser des fonctions predefinies
void trier_insert( Liste<Etudiant> src, TAdresse & adr_src, Liste<Etudiant> & dest, TAdresse & adr_dest )
{
  dest.insererApres( *adr_src, adr_dest );
  adr_src = src.adresseSuivant( adr_src );
}

void insert_rest( Liste<Etudiant> src, TAdresse & adr_src, Liste<Etudiant> dest, TAdresse & adr_dest )
{
  dest.insererApres( *adr_src, adr_dest );
  adr_src = src.adresseSuivant( adr_src );
  adr_dest = src.adresseSuivant( adr_dest );
}

void fusionnerListe_2( Liste<Etudiant> L1, Liste<Etudiant> L2, Liste<Etudiant> & L3 ) 
{
  TAdresse adr_1 = L1.adressePremier(), adr_2 = L2.adressePremier();
  
  Etudiant fictif;
  L3.insererEnTete( fictif );

  TAdresse adr_3 = L3.adressePremier();
  
  while ( adr_1 != L1.null() && adr_2 != L2.null() )
    {
      if ( adr_1->note() <= adr_2->note() ) 
	trier_insert( L1, adr_1, L3, adr_3 );
      else
	trier_insert( L2, adr_2, L3, adr_3 );
      
      adr_3 = L3.adresseSuivant( adr_3 );
    }
  

  if ( adr_1 == L1.null() )
    {
      while (adr_2 != L2.null() )
	insert_rest( L2, adr_2, L3, adr_3 );
    }
  else if ( adr_2 == L2.null() )
    {
      while (adr_1 != L1.null() )
	insert_rest( L1, adr_1, L3, adr_3 );
    }
  
  L3.supprimerEnTete();
}

// 38 : ====================================
void trierFauxJuste( Liste<Etudiant> l, Liste<Etudiant> & l_triee )
{
  TAdresse adr = l.adressePremier(), temp;
  
  while ( adr!=l.null() )
    {
      if ( adr->note()==0 &&
	   adr!=l.adressePremier() )
	{
	  l.insererEnTete( *adr );
	  l.supprimerApres( temp );
	}
      
      temp = adr;
      adr = l.adresseSuivant();
    }
  
  /*
  Liste<Etudiant> l_faux, l_vrai;
  Etudiant fictif;

  l_faux.insererEnTete( fictif );
  l_vrai.insererEnTete( fictif );
  TAdresse adr_faux = l_faux.adressePremier(), adr_vrai = l_vrai.adressePremier();

  TAdresse adr = l.adressePremier();

  while ( adr != l.null() )
    {
      if ( adr->note()==0 )
	trier_insert( l, adr, l_faux, adr_faux );
      else
	trier_insert( l, adr, l_vrai, adr_vrai );
    }

  l_faux.supprimerEnTete();
  l_vrai.supprimerEnTete();

  fusionnerListe( l_faux, l_vrai, l_triee );
  */
}
