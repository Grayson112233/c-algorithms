// Insertion array sorting algorithm

// Cost:
// Worst:   n^2
// Average: n^2
// Best:    n

#include <stdio.h>
#include "random.h"

#define LEN 10

int array[LEN];

void print_array(int *array, int len) {
	printf("{ ");
	for(int i = 0; i < len - 1; i++) {
		printf("%d, ", array[i]);
	}
	printf("%d } \n", array[len - 1]);
}

void insertion_sort(int *array, int len) {
	for(int i = 1; i < len; i++) {
		for(int j = i; j > 0; j--) {
			if(array[j-1] > array[j]) {
				// Previous value is less, swap them
				int temp = array[j];
				array[j] = array[j-1];
				array[j-1] = temp;
			} else {
				break;
			}
		}
	}
}

int main() {

	// Populate array with random integers from 0 to 10
	populate_array(array, LEN, 0, 10);
	
	printf("Unsorted: \n");
	print_array(array, LEN);

	insertion_sort(array, LEN);

	printf("Sorted: \n");
	print_array(array, LEN);

	return 0;
}
