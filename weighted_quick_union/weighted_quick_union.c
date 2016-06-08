// C implementation of weighted quick union algorithm

#include <stdio.h>
#include <stdbool.h>

#define NUM_OBJECTS 10

// Each index in the array represents one object
// An object's value in the array is its parent node in a tree
// (If an object has no parent node, the value will be itself)
int objects[NUM_OBJECTS];

int size[NUM_OBJECTS];

// Initialize the objects array so that no object are connected
void init_objects() {
	for(int i = 0; i < NUM_OBJECTS; i++) {
		objects[i] = i;
		size[i] = 1;
	}
}

int root(int i) {
		while(i != objects[i]) { i = objects[i]; }
		return i;
}

// Create a union between object a and b
// (Set the value of a's root to p's root)
void join(int a, int b) {
	int a_root = root(a);
	int b_root = root(b);
	if(size[a_root] >= size[b_root]) {
		objects[b_root] = a_root;
		size[a_root] += size[b_root];
	} else {
		objects[a_root] = b_root;
		size[b_root] += size[a_root];
	}
}

bool is_connected(int a, int b) {
	return root(a) == root(b);
}

void print_objects() {
	printf("Object\tValue\tSize\n");
	for(int i = 0; i < NUM_OBJECTS; i++) {
		printf("%d\t%d\t%d\n", i, objects[i], size[i]);
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