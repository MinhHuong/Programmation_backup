#ifndef _ROI_
#define _ROI_

#include "Piece.h"

class Roi : public Piece
{
 public:
  Roi();
  Roi(int, int, bool);
  Roi(bool);
  ~Roi();

  virtual bool deplacement(Echiquier&,int, int) const;
  virtual bool enMat( Echiquier& ) const;
  
  bool etreEnMat( Echiquier& echiq );
  bool enPat( Echiquier& );
};

#endif
