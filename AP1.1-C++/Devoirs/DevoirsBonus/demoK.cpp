#include<iostream>
#include<stdio.h>
using namespace std;

//tableau

#define TAILLE 100

int tab [TAILLE];
int index [TAILLE];

void Init();
void Min (int tab[], int n, int k);
void Display(int k);

int main()
{
  int Min1,Min2;
  int nb,l,k;
  do{
     cout << "Entrez la taille du tableau" << endl;
     cin >> nb;
     for (int i = 0 ; i < nb ; i++)
         cin >> tab[i];
     for (int i = 0 ; i < nb ; i++)
         cout <<" " << tab[i];
     
     cout << "Entrez k: " << endl;
     cin >> k;
     while ((k<1)||(k>=nb)){
           cout << " K n'est pas valid ! Re-entrez k: " << endl;
           cin >> k;
     }
     Init();
     Min(tab,nb,k);
     Display(k);
     cout << "continuer ? (0=non)";
     cin >> l;
  }while(l!=0);
  return 0;
}

void Init()
{
     for( int i=0;i<TAILLE;i++) 
          index[i]=-1;
}

void Min (int tab[], int n, int k)
{
  cout << "Begin de chercher " << k << " --- " << endl;
  int min1=9999, ind;
  bool b;
  if(k<1) return;
  for (int i=0; i<n; i++){
      b = false;
      for (int j=0; j<n; j++){
          if (index[j]==i)    b = true;
      }
      if(b) continue;
      
      //cout << "\n TAB " << i << " = " << tab[i] << " "<< endl;
      if (tab[i]<min1){
         min1 = tab[i];
         ind = i;
         //cout << "enregistrer " << ind << endl;
      }
  }
  //cout << "Enregistrer " << ind << endl;
  index[k-1] = ind;
  
  Min (tab, n, k-1);
  cout << "Fin de chercher " << k << " --- " << endl;
}
void Display(int k)
{
  for (int i=k-1; i>=0; i--){
      cout << "Le " << k-i << "ieme plus petit: " << tab[index[i]] << endl; 
  }     
}
