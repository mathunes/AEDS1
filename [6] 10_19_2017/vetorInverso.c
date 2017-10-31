#include <stdio.h>
#include "methods.h"

int main() {
	int n,i;
	int arr[1000], inverseArr[1000];

	printf("Insira um valor n para o tamanho do vetor: ");
	scanf("%d", &n);

	printf("Preencha o vetor X com os %d valores\n", n);

	for (i = 0; i < n; i++) {
		fflush(stdin);
		scanf("%d",(arr + i));
	}

	inverseArray(arr, inverseArr, n);
	
	printf("O inverso do vetor X = ");
	printArray(arr, n);
	printf(" e igual ao vetor Y = ");
	printArray(inverseArr, n);

	return 0;
}