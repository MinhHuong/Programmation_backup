#include <iostream>
#include <stdlib.h>
#include "Date.h"
using namespace std;

int main() {
  Date d(31,12,2004);
  Date d2(31,12,2004);

  if ( d == d2 )
    cout << "d == d2" << endl;
  else if ( d >= d2 )
    cout << "d >= d2" << endl;
  else
    cout << "d <= d2" << endl;

  return 0;
}
