#include <iostream>
#include <cstdlib>

using namespace std;

#define R 500
#define S 500

struct apple // fallen_apple
{
  int x;
  int y;
};

int getDistance(apple a1, apple a2)
{
  return (a1.x-a2.x)*(a1.x-a2.x) + (a1.y-a2.y)*(a1.y-a2.y);
}

int main()
{
  /************ BEGIN INPUT FIELD ***********/
  int row, col;
  cout << "Rows, Columns ? "; cin >> row >> col;

  char schema[row][col];
  cout << "Schema : " << endl; 
  for(int i = 0 ; i < row ; i++)
    {
      for(int j = 0 ; j < col ; j++)
	{
	  cin >> schema[i][j];
	} 
    }
  
  int year;
  cout << "How many years ? "; cin >> year;

  apple year_apple[year];
  cout << "Positions of fallen apples (r,s) : " << endl;
  for(int i = 0 ; i < year ; i++)
    {
      cin >> year_apple[i].x >> year_apple[i].y;
    }
  /************ END INPUT FIELD ***********/

  int size = row*col;
  apple tab_apple[size];
  int num = 0;

  for(int i = 0 ; i < row ; i++)
    {
      for(int j = 0 ; j < col ; j++)
	{
	  tab_apple[i*row+j].x = 0;
	  tab_apple[i*row+j].y = 0;
	}
    }
  
  for(int i = 0 ; i < row ; i++)
    {
      for(int j = 0 ; j < col ; j++)
	{
	  if(schema[i][j] == 'x' || schema[i][j] == 'X') 
	    {
	      tab_apple[num].x = i+1;
	      tab_apple[num].y = j+1;
	      num++;
	    }
	}
    }

  int dist;
  int result = (R-1)*(R-1) + (S-1)*(S-1);
  for(int i = 0 ; i < year ; i++)
    {
      for(int j = 0 ; j < size && tab_apple[j].x != 0 && tab_apple[j].y != 0 ; j++)
	{
	  dist = getDistance(year_apple[i], tab_apple[j]);
	  result = ( result > dist ) ? dist : result;
	}

      tab_apple[num].x = year_apple[i].x;
      tab_apple[num].y = year_apple[i].y;
      num++;
      cout << result << endl;
      result = (R-1)*(R-1) + (S-1)*(S-1);
    }

  return EXIT_SUCCESS;
}
