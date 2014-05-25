#ifndef CONCRETE_OBSERVABLE_H
#define CONCRETE_OBSERVABLE_H
#include <iostream>
#include <vector>
#include "Observable.h"
using namespace std;

class ConcreteObservable : public Observable {
 public:
  ConcreteObservable();
  ~ConcreteObservable();
};

#endif
