#ifndef SIEGE_H
#define SIEGE_H
#include <iostream>
#include <string>
using namespace std;

class Siege {
 private:
  string my_pays;
  
 public:
  Siege();
  Siege(string);
  ~Siege();
  
  string getSiege() const;
};

#endif
