#ifndef _CAVALIER_
#define _CAVALIER_

#include "Piece.h"

class Cavalier : public Piece
{
 public:
  Cavalier();
  Cavalier(int, int, bool);
  ~Cavalier();

  virtual bool deplacement(Echiquier&, int, int) const;
  virtual bool enMat( Echiquier& ) const;
};

#endif
