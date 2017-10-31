#include <stdio.h>
#include "methods.h"

int main() {
	int vector1[] = {1,1,1,1};
	int vector2[] = {1,1,1};

	printf("Produto escalar dos vetores ");
	printArray(vector1, sizeof(vector1)/sizeof(int));
	printArray(vector2, sizeof(vector2)/sizeof(int));
	printf(" = %d", scalarProduct(vector1, vector2, sizeof(vector1)/sizeof(int), sizeof(vector2)/sizeof(int)));

	return 0;
}

