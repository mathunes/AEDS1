#include <stdio.h>

#define MIN(x, y) (((x) < (y)) ? (x) : (y))

int scalarProduct (int *vector1, int *vector2, size_t vector1_size, size_t vector2_size);
void printVector (int *vector, size_t size);

int main() {
	int vector1[] = {1,1,1,1};
	int vector2[] = {1,1,1};

	printf("Produto escalar dos vetores ");
	printVector(vector1, sizeof(vector1)/sizeof(int));
	printVector(vector2, sizeof(vector2)/sizeof(int));
	printf(" = %d", scalarProduct(vector1, vector2, sizeof(vector1)/sizeof(int), sizeof(vector2)/sizeof(int)));

	return 0;
}

int scalarProduct (int *vector1, int *vector2, size_t vector1_size, size_t vector2_size) {
	int i;
	int scalarProduct = 0;

	for (i = 0; i < MIN(vector1_size, vector2_size); i++) {
		scalarProduct += *(vector1 + i) * *(vector2 + 1);
	}

	return scalarProduct;
}

void printVector (int *vector, size_t size) {
	int i;
	printf("[");
	for (i = 0; i < size; i++) {
		printf("%d", *(vector + i));
		if (i != (size - 1)) printf(", ");
	}
	printf("]");
}