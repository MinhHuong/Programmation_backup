#include "util.h"
#include <cmath>
#include <iostream>
#include <cassert>

using namespace std;

string intToString(int x){
  string x_s;
  int a;

  if(x==0)
    x_s="0";
  else {
     x_s="";
    if(x<0)
      a=-x;
    else
      a=x;
    while(a>0){
      x_s= ((char)('0'+a%10))+x_s;
      a/=10;
    }
    if(x<0)
      x_s="-"+x_s;
  }
  return x_s;
}

string floatToString(float x, int precision){
  string x_s;

  if(x==0){
    x_s="0";
    for(int i=0;i<precision;i++)
      x_s+="0";
  }
  else{
    int partie_conservee = (int)(x * pow(10.0,(double)precision));
    x_s = intToString(partie_conservee);
  }
  if(precision > 0)
    x_s.insert(x_s.length() - precision, ".");
  
  return x_s;
}

void cinPlastique(string& author, 
		  string& title, 
		  string& style, 
		  int& j, int& m, int& a, 
		  int& val, 
		  string& poss, 
		  int& ja, int& ma, int& aa) {
  cin.ignore();
  cout << "Auteur  : "; getline(cin,author);
  cout << "Titre   : "; getline(cin,title);
  cout << "Style   : "; getline(cin,style);
  cout << "Date de creation (jour/mois/annee) : "; cin >> j >> m >> a;
  cout << "Valeur  : "; cin >> val;

  cin.ignore();
  cout << "Possesseur : "; getline(cin,poss);
  cout << "Date d'acquis (jour/mois/annee) : "; cin >> ja >> ma >> aa;  
}

void cinPeinture(string& sup, string& mat) {
  cin.ignore();
  cout << "Support : "; getline(cin,sup);
  cout << "Matiere : "; getline(cin,mat);
}

void cinSculpture(string& materiau) {
  cin.ignore();
  cout << "Materiau : "; getline(cin,materiau);
}

void cinLivre(string& author, 
	      string& title, 
	      string& style, 
	      int& j, int& m, int& a, 
	      int& val, 
	      string& langue, 
	      string& theme, 
	      string& editeur, 
	      int& je, int& me, int& ae) {
  cin.ignore();
  cout << "Auteur  : "; getline(cin,author);
  cout << "Titre   : "; getline(cin,title);
  cout << "Style   : "; getline(cin,style);
  cout << "Date de creation (jour/mois/annee) : "; cin >> j >> m >> a;
  cout << "Valeur  : "; cin >> val;

  cin.ignore();
  cout << "Langue ecrite : "; getline(cin, langue);
  cout << "Theme   : "; getline(cin, theme);
  cout << "Editeur : "; getline(cin, editeur);
  cout << "Date d'edition (jour/mois/annee) : "; cin >> je >> me >> ae;
}

void cinPosition(int & indice) {
  cout << "Indice de l'oeuvre : ";
  cin >> indice;
}

void cinPossesseur(string & poss) {
  cin.ignore();
  cout << "Nouveau possesseur : ";
  getline(cin, poss);
}

void cinDate(int& j, int& m, int& a) {
  cout << "Nouvelle date (jour/mois/annee) : ";
  cin >> j >> m >> a;
}
