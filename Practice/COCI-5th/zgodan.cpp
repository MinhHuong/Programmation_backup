#include <iostream>
#include <cstdlib>
#include <unistd.h>
#include <math.h>

#define MAX 20

using namespace std;

bool isDiffParity(int n1, int n2)
{
  return ( (n1 % 2) != (n2 % 2) );
}

bool isWholeDiffParity(int tab[])
{
  for(int i = 0 ; i < MAX && tab[i+1] != -1; i++)
    {
      if(!isDiffParity(tab[i], tab[i+1]))
	return false;
    }

  return true;
}

void decompose(int nb, int tab[])
{
  int input = nb;
  int i = 0;
  while(input != 0)
    {
      tab[i] = input % 10;
      input = input / 10;
      i++;
    }
}

void initTab(int tab[])
{
  for(int i = 0 ; i < MAX; i++)
    {
      tab[i] = -1;
    }
}

int getResult(int digits[], int input, bool isInf)
{
  int result = input;
  int change = isInf ? -1 : 1;

  initTab(digits);
  decompose(input, digits);

  while(!isWholeDiffParity(digits))
    {
      result += change;
      decompose(result, digits);
    }

  return result;
}

int main()
{
  int digits[MAX];
  
  int input;
  cout << "Please enter your number (not so handsome) : "; cin >> input;
  if(input/10 < 1)
    {
      cout << input << " is already a handsome number" << endl;
    }
  else
    {
      int result_sup = getResult(digits, input, false);
      int result_inf = getResult(digits, input, true);
      int d_sup = result_sup-input;
      int d_inf = input-result_inf;
      
      if     (d_sup > d_inf)  cout << result_inf << endl;
      else if(d_sup < d_inf)  cout << result_sup << endl;
      else                    cout << result_inf << " " << result_sup << endl;
    }

  return EXIT_SUCCESS;
}
