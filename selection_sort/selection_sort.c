// Selection array sorting algorithm

// Cost Model:
// Worst: n^2
// Average: n^2
// Best: n^2

#include <stdio.h>
#include "random.h"

#define LEN 10

int array[LEN];

void print_array(int *array, int len) {
	printf("{ ");
	for(int i = 0; i < len - 1; i++) {
		printf("%d, ", array[i]);
	}
	printf("%d }\n", array[len -1]);
}

void selection_sort(int *array, int len) {
	for(int i = 0; i < len; i++) {
		// Determine smallest unsorted value
		int min = i;
		for(int j = i + 1; j < len; j++) {
			if(array[j] < array[min]) {
				min = j;
			}
		}
		// Swap with position i
		int temp = array[min];
		array[min] = array[i];
		array[i] = temp;
	}
}

int main() {

	// Populate array with random integers from 0 to 10
	populate_array(array, LEN, 0, 10);

	printf("Unsorted array:\n");
	print_array(array, LEN);

	selection_sort(array, LEN);

	printf("Sorted array:\n");
	print_array(array, LEN);

	return 0;
}
