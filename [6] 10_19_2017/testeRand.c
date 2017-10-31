#include <stdio.h>
#include "methods.h"

int main() {
	int arr[1000];
	int i;

	int  maxN, minN, maxVal = 0, minVal = 5000000;

	cleanArray(arr, 1000);

	for (i = 0; i < 5000000; i++) {
		*(arr + randomInt(0,999)) += 1;
	}

	for (i = 0; i < 1000; i++) {

		if (*(arr + i) > maxVal) {
			maxVal = *(arr + i);
			maxN = i;
		}
		
		if (*(arr + i) < minVal) {
			minVal = *(arr + i);
			minN = i;
		}
	}

	printf("O numero %d teve maior contagem (%d) e o numero %d teve a menor contagem (%d)\n", maxN, maxVal, minN, minVal);
	printf("Diferenca entre a maior e menor contagem = %d - %d = %d\n", maxVal, minVal, (maxVal - minVal));

	printf("Desvio padrao dascontagens DP = %.2f", standardDeviation(arr, 1000));

	return 0;
}