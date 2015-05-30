#include <iostream>

using namespace std;

/* PUF HCM - LINF13 - LE NGUYEN MINH HUONG */

void display(int arr[], int size) {
  for(int i = 0 ; i < size ; i++) {
    cout << arr[i] << " ";
  }
  cout << endl;
}

void swap(int arr[], int x, int y) {
  int temp = arr[x];
  arr[x] = arr[y];
  arr[y] = temp;
}

void reHeapUp(int heap[], int child) {
  int dad;

  while(child != 0) {
    dad = (int)( (child-1)/2 );
    if(heap[child] > heap[dad]) {
      swap(heap, child, dad);
      child = dad;
    }
    else {
      return;
    }
  }
}

void reHeapDown(int heap[], int size) {
  if(size == 0) return;
  
  int index = 0;
  int left, right;

  while(index != size-1) {
    left = 2*index+1;
    right = 2*index+2;
    if( (left < size) && (right < size) ) {
      if( heap[left] > heap[right] && heap[left] > heap[index] ) {
		swap(heap, left, index);
      }
      else if( heap[left] <= heap[right] && heap[right] > heap[index] ) {
		swap(heap, right, index);
      }
    }
    else if( (left < size) && (right >= size) ) {
      if(heap[left] > heap[index]) {
		swap(heap, left, index);
      }
    }
    
    index++;
  }
}

void heapSort(int arr[], int size) {
  for(int i = 0 ; i < size ; i++) {
    reHeapUp(arr, i);
  }

  for(int i = size-1 ; i > 0 ; i--) {
    swap(arr, 0, i);
    reHeapDown(arr, i);
  }
}

int main() {
  const int size = 5;
  int tab[size] = { 5, 7, 2, 1, 4 };
  heapSort(tab, size);
  display(tab, size);
  return 0;
}
