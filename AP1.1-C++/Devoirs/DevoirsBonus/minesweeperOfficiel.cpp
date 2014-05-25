#include <time.h>
#include <stdlib.h>
#include <iostream>
const int TAILLE = 100;

typedef int TGrille[TAILLE][TAILLE];

using namespace std;

TGrille khungchoi, khungthamkhao, dieukien;

void initGrille(TGrille grille, int so_cot, int so_dong)
{
  for (int i = 0 ; i < so_dong ; i++)
    for (int j = 0 ; j < so_cot ; j++)
      grille[i][j] = 0;	
      
}

void creerMines(TGrille grille, int nbMines, int so_cot, int so_dong)
{
  srand(time(NULL));
  int x,y;
  while (nbMines > 0){
    x = rand()%so_dong;
    y = rand()%so_cot;
    if (grille[x][y] == 0)
      {
    	grille[x][y] = -1;
    	nbMines--;
      }
  }      
}

void updateTableau(TGrille grille, int so_cot, int so_dong)
{
  srand(time(NULL));
  int x,y;
  for (int i = 0 ; i < so_dong ; i++)
    for (int j = 0 ; j < so_cot ; j++){
      if (grille[i][j] == -1) continue;
      if ((i>0) && (grille[i-1][j] == -1)) grille[i][j]++;
      if ((j>0) && (grille[i][j-1] == -1)) grille[i][j]++;
      if ((i<so_dong-1) && (grille[i+1][j] == -1)) grille[i][j]++;
      if ((j<so_cot-1) && (grille[i][j+1] == -1)) grille[i][j]++;
      if ((i>0)&&(j>0) && (grille[i-1][j-1] == -1)) grille[i][j]++;
      if ((i<so_dong-1) && (j>0)&&(grille[i+1][j-1] == -1)) grille[i][j]++;
      if ((i<so_dong-1) && (j<so_cot-1) && (grille[i+1][j+1] == -1)) grille[i][j]++;
      if ((i>0) && (j<so_cot-1) && (grille[i-1][j+1] == -1)) grille[i][j]++;
    }      
}

void afficherGrille(TGrille grille, int so_cot, int so_dong)
{
  cout << "\n\n\n\t";
  for (int j = 0 ; j < so_cot ; j++)
    {
      if (j<=9) cout << "  " << j+1 <<" ";
      else cout << " " << j+1 <<" ";
    }
  cout << endl;
  cout << endl << "\t-";
  for (int j = 0 ; j < so_cot ; j++)
    cout << "---+" ;
  cout << endl;
      
  for (int i = 0 ; i < so_dong ; i++)
    {
      cout << i+1 << "\t|";
      for (int j = 0 ; j < so_cot ; j++)
	{
	  switch (grille[i][j])
	    {
	    case 10 : cout << ":::"; break;
	    case -1 : cout << "bom"; break;
	    case 0 : cout << "   "; break;	    
	    default : cout << " " << grille[i][j] << " "; 
	    }
	  cout << "|";
	}

      cout << endl << "\t-";
      for (int j = 0 ; j < so_cot ; j++)
	cout << "---+" ;
      cout << endl;
    }

}

/*bool entranceValide(int x, int y, TGrille grille)
  {
  if (grille[x][y]==-1) return false;
  return true;
  }*/

bool decouvrir(int x, int y, int so_cot, int so_dong)
{ 	//cout<< khungthamkhao[0][0]<< " " << khungthamkhao[0][1] << " " << khungthamkhao[0][2]<<endl
  //cout <<endl<< x+1 <<" , " <<y+1 <<endl;
  //for (int i =0 ; i <so_dong  ; i++)
  //cout <<khungchoi[i][0]<<" , ";
  int a[15];
  for (int i=0; i<so_cot; i++) // dung de sua van de: neu chon so bom thap, sau lan chay ham de quy dau tien
    a[i]=khungthamkhao[0][i];		// thi dong dau cua khungthamkhao co vai o thay doi gia tri
  int b;
  if(y==so_cot-1)//sua van de cu moi khi mo 1 o cot cuoi dong i, thi o dong i+2 cot dau tien hien ket qua
    if(x+2<so_dong-1)
      b=khungchoi[x+2][0];

  if (khungthamkhao[x][y]==-1 && dieukien[x][y]==0) return false;
  else if(khungthamkhao[x][y]==0)
    {
      khungchoi[x][y]=10;
      dieukien[x][y]=1;			   
      if (x <so_dong -1){
	khungchoi[x+1][y] = khungthamkhao[x+1][y];
	if (khungchoi[x+1][y] == 0) khungchoi[x+1][y] = 10;
	else dieukien[x+1][y]=1;
      }        	
      if(x > 0){	
	khungchoi[x-1][y] = khungthamkhao[x-1][y];
	if (khungchoi[x-1][y] ==0 ) khungchoi[x-1][y] = 10;
	else dieukien[x-1][y]=1;
      }		
      if (y > 0){
	khungchoi[x][y-1] = khungthamkhao[x][y-1];
	if (khungchoi[x][y-1] == 0) khungchoi[x][y-1] = 10;
	else dieukien[x][y-1]=1;
      }			
      if (y < so_cot - 1){
	khungchoi[x][y+1] = khungthamkhao[x][y+1];
	if (khungchoi[x][y+1] ==0) khungchoi[x][y+1]  = 10;
	else dieukien[x][y+1]=1;
      }
      if (x > 0 && y >0){
	khungchoi[x-1][y-1] = khungthamkhao[x-1][y-1];
	if (khungchoi[x-1][y-1] == 0) khungchoi[x-1][y-1] = 10;
	else dieukien[x-1][y-1]=1;
      }
      if (x > 0 && y < so_cot-1){
	khungchoi[x-1][y+1]=khungthamkhao[x-1][y+1];
	if (khungchoi[x-1][y+1] == 0) khungchoi[ x-1 ][ y+1 ] = 10;
	else dieukien[x-1][y+1]=1;
      }
      if (x < so_dong-1 && y >0){
	khungchoi[x+1][y-1] = khungthamkhao[x+1][y-1];
	if (khungchoi[x+1][y-1]==0) khungchoi[x+1][y-1]=10;
	else dieukien[x+1][y-1]=1;
      }
      if (x < so_dong && y < so_cot){
	khungchoi[x+1][y+1] = khungthamkhao[x+1][y+1];
	if (khungchoi[x+1][y+1] == 0) khungchoi[x+1][y+1] = 10;
	else dieukien[x+1][y+1]=1;
      }		
        
      if ((x>0) &&(khungthamkhao[x-1][y] == 0) && (dieukien[x-1][y]==0)) {decouvrir(x-1,y, so_cot, so_dong);}
      if ((y>0)&&(khungthamkhao[x][y-1] == 0) && (dieukien[x][y-1]==0)) {decouvrir(x,y-1, so_cot, so_dong);}
      if ((x<so_dong-2)&&(khungthamkhao[x+1][y] == 0)&& (dieukien[x+1][y]==0)){decouvrir(x+1,y, so_cot, so_dong);}
      if ((y<so_cot-2)&&(khungthamkhao[x][y+1] == 0)&& (dieukien[x][y+1]==0)) {decouvrir(x,y+1, so_cot, so_dong);}
    }
  else {
    khungchoi[x][y]=khungthamkhao[x][y]; 
    dieukien[x][y]=1;
  }
  for (int i=0; i<so_cot; i++)//sua van de khungthamkhao bi thay doi gia tri
    khungthamkhao[0][i]=a[i];
  if(y==so_cot-1)//sua van de cu moi khi mo 1 o cot cuoi dong i, thi o dong i+2 cot dau tien hien ket qua
    if(x+2<so_dong-1)
      khungchoi[x+2][0]=b;
  return true;
}
void tickbom(int x, int y, int & so_bom){
  if(dieukien[x][y]==0){
    khungchoi[x][y]= -1;
    dieukien[x][y]=1;
    so_bom--;
  }
  else{
    khungchoi[x][y]= 0;
    dieukien[x][y]=0;
    so_bom++;
  }
}
void victoire(int so_cot, int so_dong, int  so_bom)
{
  int check=0, check_no_bom=0;
  for (int i = 0 ; i < so_dong ; i++)
    for (int j = 0 ; j < so_cot ; j++)
      if(khungchoi[i][j] !=0)
	check++;
  for (int i = 0 ; i < so_dong ; i++)
    for (int j = 0 ; j < so_cot ; j++)
      if(khungchoi[i][j] !=0 && khungthamkhao[i][j]!=-1)
	check_no_bom++;
  if (check== so_dong*so_cot || check_no_bom == so_dong*so_cot - so_bom){
    cout << "Bravo, you win";
    exit(0);
  }
    	
	
}
int main()
{ int so_bom , so_cot, so_dong;
  int x,y;
  bool c=true, game=true, ans=false;
  cout <<"Nhap vao so cot: ";
  cin >> so_cot;
  cout <<"Nhap vao so dong: ";
  cin >> so_dong;
  cout <<"Nhap vao so bom muon choi: ";
  cin >> so_bom;
  initGrille(khungchoi, so_cot, so_dong);
  initGrille(khungthamkhao, so_cot, so_dong);
  initGrille(dieukien, so_cot, so_dong);
  creerMines(khungthamkhao,so_bom, so_cot, so_dong);
  updateTableau(khungthamkhao, so_cot, so_dong);

  do{
    if(game==false && ans == true)	afficherGrille(khungthamkhao, so_cot, so_dong);
    if(game==true && ans == false)	afficherGrille(khungchoi, so_cot, so_dong);
    do{
      cout << "So bom can tim: " <<so_bom << endl;
      cout << "Nhap so '1': chon o can mo ra\n\t'2': danh/thao dau bom \n\t'3': hien/tat loi giai. \nChon lua: ";
      int a=1;
      cin >> a;
      switch (a){
      case 1:
	cout << "Entrez (x,y) de joueur ";
	cout << " : (quittez si valeur donnee n'est pas positive)";
	cin >> x >> y;
	x--; y--;        		
	c= decouvrir(x,y, so_cot, so_dong);        		
	break;
      case 2:
	cout << "Entrez (x,y) de boom ";
	cin >> x;
	cin >> y;
	x--; y--;
	tickbom(x, y, so_bom);
	break;
      case 3:
	if (game) {
	  game = false; ans = true;
	}
	else{
	  game = true; ans = false;
	}x=0, y=0;
	break;
      }
    }while(x<0 || x> so_dong -1  || y<0 || y > so_cot-1);
    //system("cls");
    //system("clear");
    victoire(so_cot, so_dong, so_bom);
  }while(c);
  if (!c) cout << "Vous etes mort !!!" << endl;
}
