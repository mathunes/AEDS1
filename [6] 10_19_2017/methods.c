#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MIN(x, y) (((x) < (y)) ? (x) : (y))

//PRODUTO ESCALAR DE DOIS VETORES
int scalarProduct (int *vector1, int *vector2, int vector1_size, int vector2_size) {
	int i;
	int scalarProduct = 0;

	for (i = 0; i < MIN(vector1_size, vector2_size); i++) {
		scalarProduct += *(vector1 + i) * *(vector2 + 1);
	}

	return scalarProduct;
}

//SEQUENCIA DE FIBONACCI
void fibonacci(unsigned long long *arr) {
	int i;

	*(arr + 0) = 0;
	*(arr + 1) = 1;

	for (i = 2; i <= 1000; i++) {
		*(arr + i) = *(arr + i - 1) + *(arr + i - 2);
	}
}

//MEDIA DOS ELEMENTOS DE UM VETOR
float arithmeticMean (int *arr, int len) {
	int i;
	float mean = 0.0;

	for (i = 0; i < len; i++) {
		mean += *(arr + i);
	}

	return (mean / (float) len);
}

//DESVIO PADRAO
float standardDeviation (int *arr, int len) {
	int i;
	float mean = arithmeticMean(arr, len);
	float sum = 0.0;
	float standardDeviation;

	for (i = 0; i < len; i++) {
		sum += pow((*(arr + i) - mean), 2);
	}

	standardDeviation = sqrt((sum / (float) len));

	return standardDeviation;
}

//INTERCALACAO DE VETORES
void intercalateArrays(int *arr1, int *arr2, int len, int *intercaletedArray) {
	int i, x = 0, y = 0;

	for (i = 0; i < len*2; i++) {
		if (i % 2 == 0)
			*(intercaletedArray + i) = *(arr1 + x++);
		else
			*(intercaletedArray + i) = *(arr2 + y++);
	}
}

//INVERSO DE UM VETOR
void inverseArray(int *arr, int *inverseArr, int len) {
	int i, j = len;

	for (i = 0; i < len; i++) {
		*(inverseArr + --j) = *(arr + i);
	}
}

//UNIAO DE VETORES
void mergeArrays(int *arr1, int *arr2, int len, int *mergedArray) {
	int i, x = 0, y = 0;

	for (i = 0; i < len*2; i++) {
		if (i < len)
			*(mergedArray + i) = *(arr1 + x++);
		else
			*(mergedArray + i) = *(arr2 + y++);
	}
}

//IMPRIME VETOR
void printArray(int *arr, int len) {
	int i;

	printf("[");
	for (i = 0; i < len; i++) {
		printf("%d", *(arr + i));
		if (i != (len - 1)) printf(", ");
	}
	printf("]");
}


//LIMPA VETOR
void cleanArray (int *arr, int len) {
	int i;

	for (i = 0; i < len; i++) {
		*(arr + i) = 0;
	}
}

//NUMERO INTEIRO EM UM INTERVALO
int randomInt (int min, int max) {
	return (rand() % (max + 1 - min)) + min;
}

//INTEIROS RANDOMICOS EM UM VETOR
void randomizeArray (int *arr, int len, int min, int max) {
	int i;

	for (i = 0; i < len; i++) {
		*(arr + i) = randomInt(min, max);
	}
}



