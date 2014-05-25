#include<iostream>
#include<cstdlib>
#include<stdio.h>
#include<string.h>
using namespace std;
const int taille=6;

bool check(int i,int j, int *popo);
void hihi(int a[],int *popo,int taille);

void hihi(int a[],int *popo,int taille){
  int tampon=0;
  int tamp=0;
  int count=0;
  
  
  for(int i=0;i<taille;i++){
    if(a[i]>tampon){
      *popo=i;
      tampon=a[i];
     }
    /* else if(a[i]==tampon){
	*(popo+1)=i;
	cout<<"ai "<<a[i]<<"tampon "<<tampon<<"popo+1 : "<<*(popo+1)<<endl;
	count++;
	}*/
  }
  for(int j=1;j<taille;j++){
    tamp=0;
    for (int i=0;i<taille;i++){
      if (a[i]<=a[*(popo+j-1)] && a[i]>=tamp && check(i,j,popo)){

	*(popo+j)=i;
	tamp=a[i];
	cout<<"ai "<<a[i]<<"tamp "<<tamp<<"check "<<check<<endl;
      }
      
    }
    
  }
  
}

bool check(int i,int j, int *popo){
  bool pipi=true;
  for(int x=1;x<=j;x++){
    if(i==*(popo+x-1)){
      cout<<" popo+x-1 "<<*(popo+x-1)<<" i "<<i<<endl;
      pipi=false;
    }
  }
  return pipi;
}

           
       

int main()
{
  int a[taille];
  int pos[taille];
  cout<<"entrer la suite"<<endl;
  for(int i=0; i<taille;i++){
    cin>>a[i];
    cout<<"fhfi "<<a[i]<<endl;
  }
  hihi(a,pos,taille);
  for(int i=0;i<taille;i++)
    cout<<pos[i]<<" ";

}



