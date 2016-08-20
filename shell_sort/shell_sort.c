// Shell array sorting algorithm

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

void shell_sort(int *array, int len) {
	// Determine best first value for h
	int h = 1;
	while(h < len / 3) { h = (h * 3) + 1; }
	while(h > 0) {
		for(int i = h; i < len; i++) {
			for(int j = i; j >= h && array[j] < array[j-h]; j -= h) {
				int temp = array[j];
				array[j] = array[j-h];
				array[j-h] = temp;
			}
		}
		h = h / 3;
	}
}

int main() {

	// Populate array with random integers from 0 to 10
	populate_array(array, LEN, 0, 10);
	
	printf("Unsorted: \n");
	print_array(array, LEN);

	shell_sort(array, LEN);

	printf("Sorted: \n");
	print_array(array, LEN);

	return 0;

}