#ifndef _FOU_
#define _FOU_

#include "Piece.h"

class Fou : virtual public Piece
{
 public:
  Fou();
  Fou(int, int, bool);
  Fou(bool);
  ~Fou();

  virtual bool deplacement(Echiquier&, int, int) const;
  virtual bool enMat( Echiquier& ) const;
};

#endif
