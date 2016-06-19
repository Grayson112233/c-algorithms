// C implementation of path compressed weighted quick union algorithm

// Cost Model:
// Initialize: N
// Union:      lg* N
// Find:       lg* N
// lg* = iterative log (in practice always less than 5)

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define SIDE_LEN 10

struct object {
	int r;
	int c;
};

// Each index in the array represents one object
// An object's value in the matrix is its parent node in a tree
// (If an object has no parent node, the value will be itself)
struct object objects[SIDE_LEN][SIDE_LEN];

int size[SIDE_LEN][SIDE_LEN];

// Initialize the objects array so that no object are connected
void init_objects() {
	for(int i = 0; i < SIDE_LEN; i++) {
		for(int j = 0; j < SIDE_LEN; j++) {
			objects[i][j].r = i;
			objects[i][j].c = j;
			size[i][j] = 1;
		}
	}
}

// Return pointer to object with value of root coords
// (Don't forget to free after use!)
struct object *root(int r, int c) {
	while(r != objects[r][c].r || c != objects[r][c].c) {
		//objects[i] = objects[objects[i]];
		int old_r = r;
		int old_c = c;
		r = objects[old_r][old_c].r;
		c = objects[old_r][old_c].c;
	}
	struct object *root = malloc(sizeof(struct object));
	root->r = r;
	root->c = c;
	return root;
}


// Create a union between object a and b
// (Set the value of a's root to p's root)
void join(int a_r, int a_c, int b_r, int b_c) {
	struct object *a_root = root(a_r, a_c);
	struct object *b_root = root(b_r, b_c);
	if(size[a_root->r][a_root->c] >= size[b_root->r][b_root->c]) {
		objects[b_root->r][b_root->c].r = a_root->r;
		objects[b_root->r][b_root->c].c = a_root->c;
		size[a_root->r][a_root->c] += size[b_root->r][b_root->c];
	} else {
		objects[a_root->r][a_root->c].r = b_root->r;
		objects[a_root->r][a_root->c].c = b_root->c;
		size[b_root->r][b_root->c] += size[a_root->r][a_root->c];
	}
	free(a_root);
	free(b_root);
}

bool is_connected(int a_r, int a_c, int b_r, int b_c) {
	struct object *a_root = root(a_r, a_c);
	struct object *b_root = root(b_r, b_c);
	// Temp bool used because we need to free the objects before we return
	bool connected = (a_root->r == b_root->r && a_root->c == b_root->c );
	free(a_root);
	free(b_root);
	return connected;
}

void print_objects() {
	for(int i = 0; i < SIDE_LEN; i++) {
		for(int j = 0; j < SIDE_LEN; j++) {
			printf("(%2d, %2d)\t", objects[i][j].r, objects[i][j].c);
		}
		printf("\n");
	}
}

int main() {

	init_objects();
	printf("Before unions:\n");
	print_objects();
	join(0, 0, 0, 1);
	printf("After unions:\n");
	print_objects();
	struct object *r1 = root(0, 0);
	struct object *r2 = root(0, 1);
	printf("(0, 0) root: (%2d, %2d)\n", r1->r, r1->c);
	printf("(0, 1) root: (%2d, %2d)\n", r2->r, r2->c);
	printf("(0, 0) connected to (0, 1): %s\n", is_connected(0, 0, 0, 1) ? "True" : "False");
	free(r1);
	free(r2);

	return 0;
}