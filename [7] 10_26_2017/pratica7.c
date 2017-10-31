#include <stdio.h>
#include "redesocial.h"

int main () {
	inicializar_rede();
	popularRedeSocialAleatoriamente(0.6);
	imprimirRedeSocial();
	int n = numAmigosEmComum(2,4);
	printf(" total de %d amigos em comum.\n", n);
	printf("O coeficiente de aglomeracao da pessoa n2 = %.2f", coeficienteAglomeracao(2)); 
}