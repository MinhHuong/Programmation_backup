#include <iostream>
#include <unistd.h>

using namespace std;

/********************************
 *      PUF HCM - LINF13
 *
 *  Mai Trung Hieu
 *  Nguyen Vu Anh Trung
 *  Le Nguyen Minh Huong
 ********************************/

/**
 * Swap 2 elements in the array
 **/
void swap(int t[], int a, int b) {
  int temp = t[a];
  t[a] = t[b];
  t[b] = temp;
}


/**
 * Display the whole array
 **/
void display(int tab[], int n) {
  for(int i = 0 ; i < n ; i++) {
    cout << tab[i] << " ";
  }
  cout << endl;
}


/**
 * Bubble Sort
 **/
void bubbleSort(int tab[], int n) {
  for(int j = 1 ; j < n-1 ; j++) {
    for(int i = n-1 ; i >= j ; i--) {
      if(tab[i] < tab[i-1]) {
	swap(tab, i, i-1);
      }
    }
  }
}


/**
 * Quick Sort
 **/
void quickSort(int a[], int start, int end) {
  int i, j, pivot;
  
  if(start+1 < end) {
    pivot = start;
    i = start;
    j = end;

    while(i < j) {
      while(a[i] <= a[pivot] && i < end) {
	i++;
      }
      while(a[j] > a[pivot] && j > start) {
	j--;
      }

      if(i < j) {
	swap(a, i, j);
      }
    }
  
  swap(a, pivot, j);
  quickSort(a, start, j); 
  quickSort(a, j+1, end);
  }
  else if(start+1 == end) {
    swap(a, start, end);
  }
}

int main() {
  const int size = 8;
  int a[size] = { 6, 5, 9, 10, 11, 4, 5, 20 };
  //int a[size] = { 2, 1 };
  quickSort(a, 0, size-1);
  //bubbleSort(a, size);
  display(a, size);
  return 0;
}
