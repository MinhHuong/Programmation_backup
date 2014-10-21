#ifndef _TOUR_
#define _TOUR_

#include "Piece.h"

class Tour : virtual public Piece
{
 public:
  Tour();
  Tour(int, int, bool);
  Tour(bool);
  ~Tour();

  virtual bool deplacement(Echiquier&, int, int) const;
  virtual bool enMat( Echiquier& ) const;
};


#endif
