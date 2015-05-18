#include <iostream>
#include <unistd.h>

using namespace std;

void swap(int t[], int a, int b) {
  int temp = t[a];
  t[a] = t[b];
  t[b] = temp;
}


void display(int tab[], int n) {
  for(int i = 0 ; i < n ; i++) {
    cout << tab[i] << " ";
  }
  cout << endl;
}

void bubbleSort(int tab[], int n) {
  for(int j = 1 ; j < n-1 ; j++) {
    for(int i = n-1 ; i >= j ; i--) {
      if(tab[i] < tab[i-1]) {
	swap(tab, i, i-1);
      }
    }
  }

  display(tab, n);
}

void quickSort(int a[], int start, int end) {
  int i, j, pivot;
  
  if(start < end) {
    pivot = start;
    i = start;
    j = end;
    while(i < j) {
      while(a[i] <= a[pivot] && i <= end) {
	i++;
      }
      while(a[j] > a[pivot] && j >= start) {
	j--;
      }

      if(i < j) {
	swap(a, i, j);
      }
    }
  }
  
  swap(a, pivot, j);
  display(a, 8);
  quickSort(a, start, j); 
  quickSort(a, j+1, end);
}

int main() {
  int a[8] = { 6, 5, 9, 10, 11, 4, 5, 20 };
  quickSort(a, 0, 7);
  //display(a, 8);
  return 0;
}
