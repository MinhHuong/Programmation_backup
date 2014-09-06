#ifndef _ENTIER_
#define _ENTIER_

#include <iostream>

class Entier 
{
 private:
  int nombre;

 public:
  Entier();
  Entier( int nb );
  Entier( const Entier& e );

  ~Entier();

  Entier operator=( const Entier& e );
  Entier operator+( const Entier& e ) const;
  Entier operator-( const Entier& e ) const;
  Entier operator*( const Entier& e ) const;
  Entier operator/( const Entier& e ) const;

  std::string toString() const;

  void incrementer();
  void doSomething();

  const int getValue();
};

#endif
