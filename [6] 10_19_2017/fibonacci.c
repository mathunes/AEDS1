#include <stdio.h>
#include "methods.h"

int main() {
	unsigned long long  fib[1001];
	fibonacci(fib);

	int i;
	printf("::SEQUENCIA DE FIBONACCI::\nInsira valores entre 0 e 1000\n\n");
	do {
		fflush(stdin);
		scanf("%d", &i);
		printf("fib(%d) = %llu\n",i, fib[i]);
	} while (i >= 0 && i <= 1000);

	return 0;
}