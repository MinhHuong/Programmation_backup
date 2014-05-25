#ifndef _UTIL_H
#define _UTIL_H
#include <string>

using namespace std;

string intToString(int n);
string floatToString(float x, int precision);

void cinPlastique(string& author, 
		  string& title, 
		  string& style, 
		  int& j, int& m, int& a, 
		  int& val, 
		  string& poss, 
		  int& ja, int& ma, int& aa);

void cinPeinture(string& sup, string& mat);

void cinSculpture(string& materiau);

void cinLivre(string& author, 
	      string& title, 
	      string& style, 
	      int& j, int& m, int& a, 
	      int& val, 
	      string& langue, 
	      string& theme, 
	      string& editeur, 
	      int& je, int& me, int& ae);

void cinPosition(int & indice);

void cinPossesseur(string & poss);

void cinDate(int& j, int& m, int& a);

#endif
