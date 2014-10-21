#ifndef _PION_
#define _PION_

#include "Piece.h"
#include "Dame.h"

class Pion : public Piece
{
 public:
  Pion();
  Pion(int, int, bool);
  ~Pion();

  virtual bool deplacement(Echiquier&, int, int) const;
  virtual bool enMat( Echiquier& ) const;
  
  Dame& operator=( Piece* p );
};

#endif
