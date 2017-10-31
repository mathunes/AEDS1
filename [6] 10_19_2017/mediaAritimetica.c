#include <stdio.h>
#include "methods.h"

int main() {
	int arr[10];
	randomizeArray(arr, sizeof(arr)/sizeof(int), 0, 10);
	printf("Media aritimetica do vetor ");
	printArray(arr, sizeof(arr)/sizeof(int));
	printf(" = %.2f\n", arithmeticMean(arr, sizeof(arr)/sizeof(int)));
	return 0;
}

