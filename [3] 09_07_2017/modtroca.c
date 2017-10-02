#include <stdio.h>

void troca1(int valor1, int valor2) {
	int valorAux;

	valorAux = valor1;
	valor1 = valor2;
	valor2 = valorAux;

	printf("\n::FIM DA FUNCAO 1:: Valor 1 = %d e Valor 2 = %d\n", valor1, valor2);
}

void troca2(int *end_valor1, int *end_valor2) {
	int valorAux;

	valorAux = *end_valor1;
	*end_valor1 = *end_valor2;
	*end_valor2 = valorAux;

	printf("\n::FIM DA FUNCAO 2:: Valor 1 = %d e Valor 2 = %d\n", *end_valor1, *end_valor2);
}