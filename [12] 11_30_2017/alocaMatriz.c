#include <stdio.h>
#include <stdlib.h>

void allocMatrix(float ***matrix, int m, int n);
void printMatrix(float **matrix, int m, int n);

int main(int argc, char *argv[]) {
	int m, n;
	float **matriz;

	fprintf(stdout, "Insira os valores desejados para o tamanho da matriz mxn: ");
	fscanf(stdin, "%d %d", &m, &n);
	fprintf(stdout, "Alocando matriz %dx%d...\n\n", m, n);
	allocMatrix(&matriz, m, n);
	printMatrix(matriz, m, n);

	return 0;
}

void allocMatrix (float ***matrix, int m, int n) {
	int i, j;

	*matrix = (float **)malloc(m * sizeof(float*));
	for (i = 0; i < m; i++) {
		(*(*matrix + i)) = (float *)malloc(n * sizeof(float));
		for (j = 0; j < n; j++) {
			(*(*(*matrix + i)+j)) = 0.0;
		}
	}
}

void printMatrix(float **matrix, int m, int n) {
	int i, j;

	for (i = 0; i < m; i++) {
		fprintf(stdout, "\t| ");
		for (j = 0; j < n; j++) {
			fprintf(stdout, "%d ", *(*(matrix + i) + j));
		}
		fprintf(stdout, "|\n");
	}
}