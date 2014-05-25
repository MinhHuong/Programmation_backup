#ifndef OBSERVER_H
#define OBSERVER_H
#include <iostream>
#include "Observable.h"
using namespace std;

class Observer {
 public:
  virtual void update(Observable) = 0;
  
 protected:
  string mySubject;
};

#endif
