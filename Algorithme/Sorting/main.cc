#include <iostream>
#include <cstdlib>

using namespace std;

void swap(int A[], int x, int y)
{
  int temp = A[x];
  A[x] = A[y];
  A[y] = temp;
}

void printArray(int A[], int n)
{
  for(int i = 0 ; i < n ; i++)
    {
      cout << A[i] << " ";
    }
  cout << endl;
}

/**
 * Find the smaller value for each comparison, then swap their position
 * (insert the smaller value to the left)
 *
 * For each inner loop, the program inserts the smaller value to the left of the other number in that comparison
 * The inner loop stops when the value has been taken to its right place 
 * (there are no other greater numbers)
 **/
void insertionSort(int A[], int n)
{
  for(int i = 1 ; i < n ; i++)
    {
      for(int j = i ; (j>0) && (A[j]<A[j-1]) ; j--)
	{
	  swap(A, j, j-1);
	}
    }
}

void insertionSort2(int A[], int n, int incr, int begin)
{
  for(int i = begin+incr ; i < n ; i+=incr)
    {
      for(int j = i ; (j>=incr) && (A[j]<A[j-incr]) ; j-=incr)
	{
	  swap(A, j, j-incr);
	}
    }
}


/**
 * For each outer loop, the algorithm finds the smallest value in the array
 * by comparing 2 adjacent values multiple times,
 * until the smallest value is placed to the first position
 *
 * Then it continues to find the next smallest value
 * And so on, until the array is completely sorted
 */
void bubbleSort(int A[], int n)
{
  for(int i = 0 ; i < n ; i++)
    {
      for(int j = n-1 ; j > i ; j--)
	{
	  if(A[j] < A[j-1])
	    {
	      swap(A, j, j-1);
	    }
	}
    }
}

/**
 * This algorithm finds the REAL smallest value in the array and puts it on the first position
 * Then, it continues to find the next smallest value
 * And so on, until the array is completely sorted
 */
void selectionSort(int A[], int n)
{
  int minIndex;

  for(int i = 0 ; i < n ; i++)
    {
      minIndex = i;
      for(int j = i ; j < n ; j++)
	{
	  if(A[j] < A[minIndex])
	    {
	      minIndex = j;
	    }
	}
      swap(A, i, minIndex);
    }
}

void shellSort(int A[], int n)
{
  for(int i = n/2 ; i >= 2 ; i/=2) 
    // the time the program divides the list to virtual sublists
    // i is also the number of sublists
    {
      for(int j = 0 ; j < i ; j++) 
	// for each sublist
	{
	  insertionSort2(A, n, i, j);
	}
      cout << endl;
    }
  insertionSort2(A, n, 1, 0);
}

int main()
{  
  int size = 16;
  int arr[] = { 59, 20, 17, 13, 28, 14, 23, 83, 36, 98, 11, 70, 65, 41, 42, 15 };
  printArray(arr, size);
  
  shellSort(arr, size);
  printArray(arr, size);

  return EXIT_SUCCESS;
}
