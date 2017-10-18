#include <math.h>

#define PI 3.141592
#define MAX(x, y) (((x) > (y)) ? (x) : (y))
#define MIN(x, y) (((x) < (y)) ? (x) : (y))
	
float paraMetrosPorSegundo (float v) {
	return (v / 3.6); 
}

float areaCirculo (float raio) {
	return ((PI) * (pow(raio, 2)));
}

int ehPar (int n) {
	if (n % 2 == 0) 
		return 1;
	else
		return 0;
}

int ehDivisivelPor3ou5 (int n) {
	if (n % 3 == 0) {
		if (n % 5 == 0)
			return 0;
		else
			return 1;
	} else if (n % 5 == 0) {
		if (n % 3 == 0)
			return 0;
		else 
			return 1;
	} else
		return 0;
}

float pesoIdeal (float h, char sexo) {
	switch (sexo) {
		case 'M':
		case 'm':
			return ((72.7 * h) - 58);
			break;
		case 'F':
		case 'f':
			return ((62.1 * h) - 44.7);
			break;
		default:
			return 0;
			break;
	}
}

float calculaMedia (int x, int y, int z, int operacao) {
	switch (operacao) {
		case 1:
			return (pow((x * y * z), (1.0 / 3.0)));
			break;
		case 2:
			return ((x + (2.0 * y) + (3.0 * z)) / 6.0);
			break;
		case 3:
			return (3.0 / ((1.0 / x) + (1.0 / y) + (1.0 / z)));
			break;
		case 4:
			return ((x + y + z) / 3.0);
			break;	
		default:
			return 0; 
			break;
	}
}

int somaImpares (int N) {
	int i;
	int soma = 0;

	for (i = 0; i <= N; i++) {
		if (i % 2 != 0)
			soma += i;
	}

	return soma;
}

double fatorial (int N) {
	int i;
	double fat = 1.0;

	for (i = N; i > 0; i--) {
		fat *= i;
	}

	return fat;
}

int somaNumerosDiv3ou5 (int N) {
	int i;
	int soma = 0;

	for (i = 0; i <= N; i++) {
		soma += (ehDivisivelPor3ou5(i)) ? i : 0;
	}

	return soma;
}

int numeroDivisores (int N) {
	int i;
	int numDiv = 0;

	for (i = 1; i <= N; i++) {
		numDiv += (N % i == 0) ? 1 : 0;
	}

	return numDiv;
}

int enesimoFibonacci (int N) {
	int i;
	int eneFib = 0, eneFibAnterior = 0;
	int aux = 0;

	for (i = 0; i < N-1; i++) {
		if (i == 0) {
			eneFib = 1;
		} else {
			aux = eneFib;
			eneFib += eneFibAnterior;
			eneFibAnterior = aux;
		}
	}

	return eneFib;
}

int mdc (unsigned int x, unsigned int y) {
	int i;
	int mdc = 0;

	for (i = 1; i < MIN(x, y); i++) {
		if ((x % i == 0) && (y % i == 0))
			mdc = i;
	}

	return mdc;
}

int mmc (unsigned int x, unsigned int y) {
	int i = 1;
	int mmc = 0;
	int aux = 0;

	do {
		aux = (MAX(x, y) * i);

		if ((aux % MIN(x, y)) == 0)
			mmc = aux;
		
		i++; 
	} while (mmc == 0);

	return mmc; 
}
