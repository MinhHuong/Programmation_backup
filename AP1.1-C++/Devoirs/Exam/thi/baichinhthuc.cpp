#include <iostream>
#include <fstream>
#include<string>
#include<cstdlib>
#include<math.h>
#include <vector>
#include <ctime>
#include <sstream>
#include <map>
using namespace std;
const int TAILLE = 9;
typedef int TGrille[TAILLE][TAILLE];
TGrille matrice, matrice_solution;
void afficher_matrice(TGrille sudo)
{
	cout << "\n\n\t";
	for (int j = 0 ; j < TAILLE ; j++)
       cout << "  " << j+1 <<" ";
  	cout << endl;
 	cout << endl << "\t+";
  	for (int j = 0 ; j < TAILLE ; j++)
      cout << "---+" ;
  cout << endl;
      
  for (int i = 0 ; i < TAILLE ; i++)
    {
      cout << i+1 << "\t|";
      for (int j = 0 ; j < TAILLE ; j++)
	{
		switch (sudo[i][j])
	    {
	    case 0 : cout << "   "; break;
	    default : cout << " " <<sudo[i][j]<<" ";break;
	    }
	  
	  cout << "|";
	}

      cout << endl << "\t+";
      for (int j = 0 ; j < TAILLE ; j++)
           cout << "---+" ;
      cout << endl;
    }

}
void entrer_matrice(ifstream &f, TGrille sudo)
{
  
  for(int i=0;i<9;i++)
    for(int j=0;j<9;j++)
      f>>sudo[i][j];
}
void entrer_valeur( int i, int j)
{
  while(1){ 
    cout<<"Veuillez entrer les coordonnees i et j"<<endl;
    cout << "i=";cin >> i; cout << "j="; cin >> j;
    i--; j--;
    cout<<"la valeur choisie"<<endl;
    cin>>matrice[i][j];
    system("clear");
  }
}

void verifier(int x, int y, bool & nhapdung)
{
	int a=0, b=0,c=0;
	for (int i=0; i<9; i++)	{
		if(matrice[x][y]==matrice[i][y])
			a++;
		if(matrice[x][y]==matrice[x][i])
			b++;
	}
	for (int i= x-x%3; i<x-x%3+3; i++)
		for (int j= y-y%3; j<y-y%3+3; j++){
			if(matrice[x][y]==matrice[i][j])
				c++;
		}
			
	if(a>1){
		cout <<"Gia tri ban nhap trung gia tri tren cot, xin nhap lai \n";
		nhapdung=false;
		matrice[x][y]=0;
	}		
	else if (b>1){
		cout <<"Gia tri ban nhap trung gia tri tren dong, xin nhap lai \n";	
		nhapdung=false;
		matrice[x][y]=0;
	}		
	else if (c>1){
		cout <<"Gia tri ban nhap trung gia tri trong khung nho, xin nhap lai \n";
		nhapdung=false;
		matrice[x][y]=0;
	}		
	if (a ==1 && b == 1 && c == 1)
		nhapdung=true;
}
void show_solution(bool & solution, bool & nhapdung)
{
	if(solution) solution=false;
    else solution = true;
    nhapdung = true;
}
void verifier_grille(){
	int a=0;
	for (int i=0; i<9; i++)
		for (int j=0; j< 9; j++)
			if (matrice[i][j] != 0)
				if(matrice[i][j] !=  matrice_solution[i][j])
					a++;
	if (a>0) cout << "Bai cua ban sai roi \n";
	else cout << "Bai cua ban dung roi \n";
	
	cout << "Bam phim 1 de tiep tuc: ";
	cin >>a;
}
void chienthang(bool & quit){
	int a=0;
	for (int i=0; i<9; i++)
		for (int j=0; j< 9; j++)
			if(matrice[i][j] !=  matrice_solution[i][j])
				a++;
	if (a==0) {
		cout << "Chuc mung ban da giai xong tran sudoku nay\n";
		quit = true;
	}
}

int main()
{
  int i, j;
  char c;
  bool nhapdung=false, solution=false, quit = false;
  ifstream f("sodoku.txt");
  entrer_matrice(f, matrice);
  ifstream g("sodoku_solution.txt");
  entrer_matrice(g, matrice_solution);
  
  while(!quit)
  { 
  	system("cls");
  	if(!solution) afficher_matrice(matrice);
    else afficher_matrice(matrice_solution);
    nhapdung=false;
    
    while(!nhapdung){
    	cout <<"\nNhan 'h': tat/hien loi giai 'x': xoa sodoku de choi lai\n";
		cout <<"'c': kiem tra dung sai 'q':thoat, 't': nhap so.... : ";
    	cin >> c;
    	
    	if(c=='c'){
    		verifier_grille();
    		nhapdung=true;
    	}
    		
    	else if( c == 'h'){
    		show_solution(solution , nhapdung);
    	}
    	else if (c == 'x'){
    		ifstream f("sodoku.txt");
  			entrer_matrice(f, matrice);
  			nhapdung = true;
    	}
    	else if (c == 'q'){
    		quit = true;
    		nhapdung = true;
    		break;
    	}
    	    		
    	else if (c == 't'){
    		cout<<"Veuillez entrer les coordonnees i et j"<<endl;
    		cout << "i=";cin >> i; cout << "j="; cin >> j;
    		i--; j--;
    		cout<<"la valeur choisie"<<endl;    	
    		cin>>matrice[i][j];
    		verifier(i, j,nhapdung);
    	}
    	
    	
    }
    	
    chienthang(quit);
    
  }
  
  
}

