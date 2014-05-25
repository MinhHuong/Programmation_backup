#include <iostream>
#include <cstdlib>
#include <unistd.h>
#include <math.h>

using namespace std;

void relax ();
void jeux1 ();
void jeux2 ();
void desiner1();
//void recursive(int e);



int main ()
{
  while (1)
  {
    int a;
    cout << "1. Relax" << endl << "2. Playing game 1" << endl << "3. Playing game 2" << endl << "4. Quit" << endl<<endl;
    cout << "Enter your choice: ";
    cin >> a;
    if (a == 1)
      {
	system ("clear");
	desiner1 ();
      }
    else if (a == 2)
      {
	system ("clear");
	jeux1 ();
      }
    else if (a == 3)
      {
	system ("clear");
	jeux2 ();
      }
    else if (a == 4)
      break;
    else
      system ("clear");
      
  }
}


void desiner1 ()
{
  int row=30,column=100,h=1,k=1;
  char c;
  bool a=false,b=false;
  
  cout << a << b;
  for (;;((a==0 && b==0)?(h++, k++):((a==1 && b==0)? (h--,k++): ((a==1 && b==1)?(h--, k--): (h++, k--)))))
	{
	  for (int i=0; i<row; i++)
	    {
	      for (int j=0; j<column; j++)
		{
		  if (i==0 || i==row-1 || j==0 || j==column-1)
		    cout << "x";
		  else if (h==i && k==j)
		    cout << "O"; 
		  else
		    cout << " ";
		}
	      cout << endl;
	    }
	  if (h == row-2)
	    a = true;
	  if (k == column -2)
	    b = true;
	  if (h == 1)
	    a = false;
	  if (k == 1)
	    b = false;
	  usleep (10000);
	  // cout << "Press q to return to menu"<<endl;
		  // if (kbhit())
		  // {
		  //   cin >> c;    
		  //   if (c =='q')
		  //   break;
		  // }
	  system ("clear");
	 
	}
    
}
//void recursive (int e)
//{
// for (a[e]=0; a[e]<2; a[e])
//   {recursive (e-1);
      

//}
void jeux1 ()
{
  char c;
  int a[5],b,d=0;
  for (int i=0; i<5; i++)
    {
      for(a[0]=0; a[0]<2; (a[0])++)
	{
	  for(a[1]=0; a[1]<2;(a[1])++)
	    {
	      for(a[2]=0; a[2]<2; (a[2])++)
		{
		  for(a[3]=0; a[3]<2; (a[3])++)
		    {
		      for(a[4]=0; a[4]<2; (a[4])++)
			{ a[i]=1;
			  cout << a[0]*16 + a[1]*8 + a[2]*4 + a[3]*2 + a[4] << " , ";
			}
		    }
		}
	    }
	}
      cout << endl << "Ngay sinh cua ban co nam trong day so nay khong? 1: Co ;  0: Khong"<<endl;
      cin >> b;
      if (b==1)
	d=d+pow(2,4-i);
      

    }
  cout <<"Ngay sinh cua ban la ngay: " << d<<endl<<endl;
  
}
void jeux2 ()
{}
