#include <stdio.h>
#include <stdlib.h>

#define NUM_PESSOAS 7

int redeSocial[NUM_PESSOAS][NUM_PESSOAS];

void inicializar_rede() {
	int i, j;

	for (i = 0; i < NUM_PESSOAS; i++) {
		for (j = 0; j < NUM_PESSOAS; j++) {
			redeSocial[i][j] = 0;
		}
	}
}

void adicionar_amizade (int i, int j) {
	if (i == j) {
		redeSocial[i][j] = 0;
		redeSocial[j][i] = 0;
	} else {
		redeSocial[i][j] = 1;
		redeSocial[j][i] = 1;
	}
}

float random_float() {
	return (rand() % (1 + 1 - 0)) + 0;
}

void popularRedeSocialAleatoriamente (float P) {
	int i, j;
	float r;

	for (i = 0; i < NUM_PESSOAS; i++) {
		for (j = i; j < NUM_PESSOAS; j++) {
			r = random_float();
			if (r < P) {
				adicionar_amizade(i,j);
			}
		}
	}
}

void imprimirRedeSocial() {
	int i, j;

	printf("\n");
	printf("| id |");
	for (i = 0; i < NUM_PESSOAS; i++) {
		printf(" n%d |", i);
	}
	printf("\n");

	for (i = 0; i < NUM_PESSOAS; i++) {
		printf("| n%d |", i);
		for (j = 0; j < NUM_PESSOAS; j++) {
			printf(" %d  |", redeSocial[i][j]);
		}
		printf("\n");
	}
}

int numAmigosEmComum(int v, int u) {
	int amigosEmComum[NUM_PESSOAS - 1];
	int numAmigosEmComum = 0;
	int i = 0, j = 0;

	for (j = 0; j < NUM_PESSOAS; j++) {
		if (j != v && j != u) {
			if (redeSocial[v][j] == 1) {
				if (redeSocial[u][j] == 1) {
					amigosEmComum[i++] = j;
					numAmigosEmComum++;
				}
			}
		}
	}

	printf("\nAmigos em comum entre as pessoas n%d e n%d sao ",v,u);
	
	printf("[");
	for (i = 0; i < numAmigosEmComum; i++) {
		printf("n%d", amigosEmComum[i]);
		if (i != (numAmigosEmComum - 1)) printf(", ");
	}
	printf("]");

	return numAmigosEmComum;
}

float coeficienteAglomeracao (int v) {
	float cont = 0.0, n = 0.0;
	int i,j,a,b;

	for (j = 0; j < NUM_PESSOAS; j++) {
		if (redeSocial[v][j] == 1) {
			n++;
			for (a = 0; a < NUM_PESSOAS; a++) {
				if (a != j && a != v) {
					if (redeSocial[v][a] == 1) {
						if (redeSocial[a][j] == 1)
							cont++;
					}
				}
			}
		}
	}

	return (cont / ((n*(n-1.0)) / 2.0) );
}