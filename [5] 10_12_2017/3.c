#include <stdio.h>

void printFloydTriangle (int height);
void printFloydTriangleRow (int row);

int main() {
	int n;

	printf("\n:: Triangulo de Floyd ::\n");
	do {

    printf("\nAltura: ");
  	fflush(stdin);
    scanf("%d", &n);

    if (n >= 1) {
    	printf("\n Linha n = %d do Triangulo de Floyd:", n);
    	printFloydTriangleRow(n);
		printf("\n\n Triangulo de Floyd com altura n = %d\n\n", n); 
    	printFloydTriangle(n);
    }
    else 
    	printf("Insira uma altura a partir de 1\n");

  } while (n < 1);

	return 0;
}

void printFloydTriangle (int height) {
	int i,j, aux = 1;

	for (i = 1; i <= height; i++) {
		printFloydTriangleRow(i);
		printf("\n");
	}
}

void printFloydTriangleRow (int row) {
	int i,j, aux = 1, height = row;

	for (i = 1; i <= height; i++) {
		for (j = 1; j <= i; j++) {
			if (i == (row))
				printf (" %d", aux);
			aux++;
		}
	} 

}