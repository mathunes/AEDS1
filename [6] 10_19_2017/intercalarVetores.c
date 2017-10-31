#include <stdio.h>
#include "methods.h"

int main() {
	int arr1[] = { 0,2,4,6,8,10,12,14,16,18 };
	int arr2[] = { 1,3,5,7,9,11,13,15,17,19 };
	int intercalatedArray[20];

	intercalateArrays(arr1, arr2, 10, intercalatedArray);

	printf("Intercalacao do vetor X = ");
	printArray(arr1, sizeof(arr1) / sizeof(int));
	printf("\ncom o vetor Y = ");
	printArray(arr2, sizeof(arr2) / sizeof(int));
	printf("\ne igual ao vetor Z = ");
	printArray(intercalatedArray, sizeof(intercalatedArray) / sizeof(int));
	printf("\n");
	
	return 0;
}