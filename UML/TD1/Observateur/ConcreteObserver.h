#ifndef CONCRETE_OBSERVER_H
#define CONCRETE_OBSERVER_H
#include <iostream>
#include "Observer.h"

class ConcreteObserver : public Observer {
 public:
  ConcreteObserver();
  ~ConcreteObserver();
  
  virtual void update(Observable);
};

#endif
