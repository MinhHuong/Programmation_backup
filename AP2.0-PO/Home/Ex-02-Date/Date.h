#ifndef DATE_H
#define DATE_H
#include <string>
#include <iostream>
#include <sstream>
using namespace std;

class Date {
 private:
  int j;
  int m;
  int a;

 public:
  Date();
  Date(int,int,int);
  ~Date();

  std::string toString() const;
  int nbJour() const;
  bool bissextile() const;
  bool verifier() const;  
  void increJour();
  void decreJour();
  void increSem();
  void decreSem();
};

std::ostream& operator<<(std::ostream& out, const Date& d);

#endif
