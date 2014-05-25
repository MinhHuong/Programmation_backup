#include <iostream>
#include <math.h>
using namespace std;

void affichage(int espace,int N,string msg)
{
  cout << "x";
  for ( int k = 0 ; k < espace ; k++)
    cout << " " ;
  cout << msg;
  for ( int k = 0 ; k < espace ; k++)
    cout << " " ;
  if ((N - msg.length() - 2) % 2 == 1)  
    cout << " x";
  else
    cout << "x";
} 


                 
int main()
{
  int N,espace1,espace2;
  string msg1,msg2;

  cout << "Message 1 = " ; cin >> msg1;
  cout << "Message 2 = " ; cin >> msg2;
  cout << "N = "; cin >> N;

  espace1 = (N - msg1.length()-2)/2;
  espace2 = (N - msg2.length()-2)/2;

  for (int i = 0 ; i < N ; i++)
    {
      if (i == N/2 -1) 
        affichage (espace1,N,msg1); 
	
      else if ( i == N/2)
	affichage (espace2,N,msg2);

      else  
	{
	  for (int f = 0 ; f < N ; f++)
	    { if (f == 0 || f == N - 1 || i == 0 || i == N - 1)
		cout << "x";
	      else
		cout << ' '; }
	}
      cout << endl; 
    }
}
