#ifndef UTIL_H
#define UTIL_H
#include <iostream>
#include <string>
#include <sstream>
#include "Rationnel.h"

using namespace std;

class Rationnel;

enum operand { add  = '+',
	       take = '-',
	       mult = '*',
	       div  = ':',
	       eg   = '=',
	       ineg = '#' };

int pgcd(int, int);
string intToString(int);

void menu();
void cinNombre(int& n, int& d, Rationnel& r);
void cinResult(Rationnel a, Rationnel b, Rationnel c, char op);

#endif
