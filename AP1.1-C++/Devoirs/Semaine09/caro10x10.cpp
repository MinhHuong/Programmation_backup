#include <iostream>
#include <cstdlib>
#include <unistd.h>
#include <math.h>
#include <stdio.h>
#include <termios.h>
using namespace std;

#define TAILLE 10

int caro[TAILLE][TAILLE];

int main() {
  for (int i = 0 ; i < TAILLE ; i++) {
    cout << i+1 << "\t|";
    for (int j = 0 ; j < TAILLE ; j++)
      cout << "   " << '|';
    
    cout << endl << "\t-";
    for (int j = 0 ; j < TAILLE ; j++)
      cout << "---+" ;
    cout << endl;
  }
}

