#ifndef _DAME_
#define _DAME_

#include "Tour.h"
#include "Fou.h"

class Dame : public Fou, public Tour
{
 public:
  Dame();
  Dame(int, int, bool);
  ~Dame();

  virtual bool deplacement(Echiquier&, int, int) const;
  virtual bool enMat( Echiquier& ) const;
};


#endif
