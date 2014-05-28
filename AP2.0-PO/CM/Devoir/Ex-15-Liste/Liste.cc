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


