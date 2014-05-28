void afficher(Liste<int> l) 
{
  Tadresse adr;
  adr = l.adressePremier();

  while ( !adr.null() ) // adr != NULL
    {
      cout << l.valeurElement(adr) << endl;
      adr = l.adresseSuivant(adr);
    }
}

Tadresse recherche(Liste<int> l, TInfo elem)
{
  TAdresse adr = l.adressePremier();
  bool trouve = false;

  while( !trouve && !adr.null() )
    {
      if ( l.valeurElement(adr)==elem )
	trouve = true;
      else
	adr = l.adresseSuivant(adr);
    }

  return adr;
}

void insererElementFin(Liste<int> & l, TInfo Elem) 
{
  TAdresse adr, adrPrec;
  adr = l.adressePremier();

  while ( !adr.null() )
    {
      adrPrec = adr;
      adr = l.adresseSuivante(adr);
    }

  if ( adrPrec.null() )
    l.insererEnTete(elem);
  else
    l.insererApres(elem, adrPrec);
}

void copierListe(Liste<int> l1, Liste<int> & l_new)
{
  Tadresse adr_1 = l1.adressePremier(), adr_new = l_new.adressePremier();

  while ( !adr_1.nul() )
    {
      l_new.insererApres( l_new.insererApres(l1.valeurElement(adr_1)), adr_new);
      adr_1 = l1.adresseSuivant(adr_1);
      adr_new = l3.adresseSuivant(adr_new);
    }
}

void concatener(Liste<int> l1, Liste<int> l2, Liste<int> & l3) 
{
  TInfo fictif;

  l3.insererEnTete(fictif);
  
  copierListe(l1,l3);
  copierListe(l2,l3);

  l3.supprimerEnTete(fictif);
}
