#include<iostream>
#include<cstdlib>
using namespace std;

// passage par reference
void echange1( int & a, int & b ) {
}
// utilisation des adresses explicitement (pointeurs)
void echange2( int* pa, int* pb ) {
}

int main() {
  int i = 1, j = 2 ;
  cout << "avant echange1 : "
       << " i = " << i
       << " j = " << j << endl;
  // passage des variables (par reference implicitement)
  //echange1(..,..
  cout << "apres echange1 : "
       << " i = " << i
       << " j = " << j << endl;
  // passage des adresses des variables explicitement
  //echange2(..,..
  cout << "apres echange2 : "
       << " i = " << i
       << " j = " << j << endl;
  return EXIT_SUCCESS;
}
