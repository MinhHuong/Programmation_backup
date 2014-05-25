#ifndef OBSERVABLE_H
#define OBSERVABLE_H
#include <iostream>
#include <vector>
using namespace std;

class Observable {
 public:
  void addObserver(const Observer&);
  void deleteObserver(const Observer&);
  void setChanged();
  void notifyObservers();

 protected:
  vector<Observer*> v;
};

#endif
