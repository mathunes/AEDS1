#include <stdio.h>
#include "modtroca.h"

int main() {
	
	int x = 1, y = 100;

	troca1(x, y);
	printf("\n::VALORES DE X E Y:: x = %d e y = %d\n", x, y);	
	troca2(&x, &y);
	printf("\n::VALORES DE X E Y:: x = %d e y = %d\n", x, y);	

	return 0;
}
