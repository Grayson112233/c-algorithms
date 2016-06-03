// Quick find union search algorithm (eager implementation)

// Cost Model:
// Initialize: N
// Union:      N
// Find:       1
// Union is too slow, performing N unions on each of the N objects is quadratic

#include <stdio.h>
#include <stdbool.h>

#define NUM_OBJECTS 10

// Each index in the array will represent one object
// Two objects are connected to each other if they have the same value in the array
int objects[NUM_OBJECTS];

void init_objects() {
	// Initialize the objects array so that no object are connected
	for(int i = 0; i < NUM_OBJECTS; i++) {
		objects[i] = i;
	}
}

// Create a union between object a and b
void join(int a, int b) {
	// All objects of the same value of a will be changed to the value of b
	int replace = objects[a];
	for(int i = 0; i < NUM_OBJECTS; i++) {
		if(objects[i] == replace) {
			objects[i] = objects[b];
		}
	}
}

bool is_connected(int a, int b) {
	return objects[a] == objects[b];
}

void print_objects() {
	printf("Object\tValue\n");
	for(int i = 0; i < NUM_OBJECTS; i++) {
		printf("%d\t%d\n", i, objects[i]);
	}
}

int main() {

	init_objects();
	printf("Before unions:\n");
	print_objects();
	join(4, 3);
	join(0, 1);
	join(4, 1);
	printf("After unions:\n");
	print_objects();
	printf("0 connected to 3: %s\n", is_connected(0, 3) ? "True" : "False");

	return 0;
}