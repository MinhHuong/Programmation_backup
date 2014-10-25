#ifndef _RECTANGLE_
#define _RECTANGLE_

class Rectangle
{
 protected:
  float width, height;

 public:
  Rectangle();
  Rectangle( float, float );
  ~Rectangle();

  virtual float perimetre() const;
};

#endif
