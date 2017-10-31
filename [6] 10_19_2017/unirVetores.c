#include <stdio.h>
#include "methods.h"

int main() {
	int arrX[60], arrY[60], mergedArr[120];
	randomizeArray(arrX, 60, 0, 365);
	randomizeArray(arrY, 60, 0, 365);
	mergeArrays(arrX, arrY, 60, mergedArr);

	printf("A uniao dos vetores\nX = ");
	printArray(arrX, 60);
	printf("\ne Y = ");
	printArray(arrY, 60);
	printf("\ne igual ao vetor\nZ = ");
	printArray(mergedArr, 120);

	return 0;
}