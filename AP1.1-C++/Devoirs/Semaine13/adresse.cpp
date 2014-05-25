#include <iostream>
#include <cstdlib>
using namespace std;

int main()
{
  int j = 10;
  int *int_ptr = &j;
  cout << "La variable j a pour adresse " << &j << endl
       << " et a pour valeur " << j << endl
       << "Le pointeur int_ptr pointe sur " << int_ptr << endl
       << " et la valeur pointee est " << *int_ptr << endl
       << "(int_ptr a pour adresse " << &int_ptr << " )"<< endl;
  return EXIT_SUCCESS;
}
