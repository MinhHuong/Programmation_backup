/**
 *	Nguyen Thanh Son Lam
 * 	PUF HCM
 *	LINF13
 *	HEAP SORT
 */

#include <iostream>
#include <cstdlib>
using namespace std;

void swap(int t[], int i, int j) {
	int temp = t[i];
	t[i] = t[j];
	t[j] = temp;
}

void reHeapUp(int heap[], int child) {
	if(child == 0) return;
	int dad = (int)( (child-1)/2 );
	if(heap[child] > heap[dad]) {
		swap(heap, child, dad);
		reHeapUp(heap, dad);
	}
	else {
		return;
	}
}

void reHeapDown(int heap[], int size) {
	if(size == 0) return;
	int i = 0, child_left, child_right;
	
	while(i != size) {
		child_left = 2*i+1;
		child_right = 2*i+2;
		
		if(child_left < size && child_right < size) { // have 2 child nodes
			if(heap[child_left] > heap[child_right]) {
				if(heap[i] < heap[child_left) {
					swap(heap, i, child_left);
				}
			}
			else {
				if(heap[i] < heap[child_right]) {
					swap(heap, i, child_right);
				}
			}
		}
		else if(child_left < size && child_right >= size) { // have 1 child left
			if(heap[child_left] > heap[i]) {
				swap(heap, i, child_left);
			}
		}
		i++;
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
	int tab[5] = { 5, 4, 3, 2, 1 };
	heapSort(tab, 5);
	for(int i = 0 ; i < 5 ; i++) {
		cout << tab[i] << " ";
	}
	cout << endl;
	return EXIT_SUCCESS;
}