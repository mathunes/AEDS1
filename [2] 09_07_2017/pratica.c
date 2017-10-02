#include <stdio.h>
#include "statistic.h"

void main() {
	float x, b, mu, beta;

	printf("\n");

	printf("Insira um valor de x para o calculo da distribuicao de Cauchy\n");
	printf("x: "); scanf("%f", &x);

	printf("Cauchy(%.1f) = %f\n\n", x, Cauchy(x));

	printf("Insira valores de x, mu e beta para o calculo da distribuicao de Gumbel\n");
	printf("x: "); scanf("%f", &x);
	printf("mu: "); scanf("%f", &mu);
	printf("beta: "); scanf("%f", &beta);

	printf("Gumbel(%.1f, %.1f, %.1f) = %f\n\n", x, mu, beta, Gumbel(x, mu, beta));

	printf("Insira valores de x, mu e b para o calculo da distribuicao de Laplace\n");
	printf("x: "); scanf("%f", &x);
	printf("mu: "); scanf("%f", &mu);
	printf("b: "); scanf("%f", &b);

	printf("Laplace(%.1f, %.1f, %.1f) = %f\n\n", x, mu, b, Laplace(x, mu, b));
}