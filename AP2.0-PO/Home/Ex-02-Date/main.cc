#include "Date.h"
#include <iostream>
#include <string>
#include <vector>
#include <typeinfo>
using namespace std;

int main() {
  vector<Date*> v;
  v.push_back(new Date(1,1,1990));
  v.push_back(new Date(29,2,2008));
  v.push_back(new Date(14,8,1995));
  v.push_back(new Date(27,12,2014));
  v.push_back(new Date(31,12,2012));

  for (int i = 0 ; i < v.size() ; i++) {
    if (v[i]->verifier())
      cout << *v[i] << " existe" << endl;
  }
  
  for (int i = 0 ; i < v.size() ; i++)
    delete v[i];

  return 0;
}
