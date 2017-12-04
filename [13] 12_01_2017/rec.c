#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>


int somaDosCubos(int n);
void imprimeCrescente(int n);
void imprimeDecrescente(int n);
int somaDosElementos(int *vet, int n, int i);
float mediaDosElementos(int *vet, int n, int i);
int potencia(int base, int expoente);
void inverteString(char *str, int len);
void inverteInteiro(int x);
void decimalBinario(int x);
int menorElemento(int *vet, int n);

int main(int argc, char *argv[]) {
	
	int m, n, i;
	int *v;
	char *s;

	srand(time(NULL)); 

	n = 1 + rand() % 9;
	m = 1 + rand() % 4;
	
	v = (int *)malloc(n*sizeof(int));
	for (i = 0; i < n; i++) {
		v[i] = rand() % 20;
	}

	s = (char *)malloc(n*sizeof(char));
	for (i = 0; i < n; i++) {
		s[i] = (char) (65 + (rand() % 57));
	}

	fprintf(stdout, "\n\t\t\t::: n = %d :::\n", n);

	fprintf(stdout, "\n[SOMA DOS CUBOS]\t\t\t");
	fprintf(stdout, "1^3 + ... + %d^3 = %d\n", n, somaDosCubos(n));

	fprintf(stdout, "\n[IMPRIME EM ORDEM CRESCENTE]\t\t");
	imprimeCrescente(n);
	fprintf(stdout, "\n");

	fprintf(stdout, "\n[IMPRIME EM ORDEM DECRESCENTE]\t\t");
	imprimeDecrescente(n);
	fprintf(stdout, "\n");

	fprintf(stdout, "\n[SOMA DOS ELEMENTOS DE UM VETOR]\t");
	fprintf(stdout, "[");
	for (i = 0; i < n; i++) {
		fprintf(stdout, " %d", v[i]);
	}
	fprintf(stdout, " ] = ");
	fprintf(stdout, "%d\n", somaDosElementos(v, n, 0));

	fprintf(stdout, "\n[MEDIA DOS ELEMENTOS DE UM VETOR]\t");
	fprintf(stdout, "[");
	for (i = 0; i < n; i++) {
		fprintf(stdout, " %d", v[i]);
	}
	fprintf(stdout, " ] = ");
	fprintf(stdout, "%.2f\n", mediaDosElementos(v, n, 0));

	fprintf(stdout, "\n[POTENCIA]\t\t\t\t");
	fprintf(stdout, "%d^%d = %d\n", n,m, potencia(n,m));

	fprintf(stdout, "\n[STRING INVERTIDA]\t\t\t");
	for (i = 0; i < n; i++) {
		fprintf(stdout, "%c", s[i]);
	}
	fprintf(stdout, " ==> ");
	inverteString(s, n);
	fprintf(stdout, "\n");

	fprintf(stdout, "\n[INTEIRO INVERTIDO]\t\t\t");
	fprintf(stdout, "%d ==> ", potencia(n,m));
	inverteInteiro(potencia(n,m));
	fprintf(stdout, "\n");

	fprintf(stdout, "\n[DECIMAL PARA BINARIO]\t\t\t");
	fprintf(stdout, "%d ==> ", potencia(n,m));
	decimalBinario(potencia(n,m));
	fprintf(stdout, "\n");

	fprintf(stdout, "\n[MENOR ELEMENTO DE UM VETOR]\t\t");
	fprintf(stdout, "[");
	for (i = 0; i < n; i++) {
		fprintf(stdout, " %d", v[i]);
	}
	fprintf(stdout, " ] = ");
	fprintf(stdout, "%d\n", menorElemento(v, n));


	return 0;
}

int somaDosCubos(int n) {
	if (n > 1) {
		return (pow(n,3) + somaDosCubos(n-1));
	} else
		return 1;
}

void imprimeCrescente(int n) {
	if (n >= 0) {
		imprimeCrescente(n - 1);
		fprintf(stdout, "%d ", n);
	} else 
		return;
}

void imprimeDecrescente(int n) {
	if (n >= 0) {
		fprintf(stdout, "%d ", n);
		imprimeDecrescente(n - 1);
	} else
		return;
}

int somaDosElementos(int *vet, int n, int i) {
	if (i < n) {
		return vet[i] + (somaDosElementos(vet, n, i+1));
	} else
		return 0; 
}

float mediaDosElementos(int *vet, int n, int i) {
	if (i < n) {
		return ((float) vet[i]/n) + (mediaDosElementos(vet, n, i+1));
	} else
		return 0.0; 
}

int potencia(int base, int expoente) {
	if (expoente > 0) {
		return base * (potencia(base, expoente - 1));
	} else
		return 1;
}

void inverteString(char *str, int len) {
	if (len > 0) {
		fprintf(stdout, "%c", str[len - 1]);
		inverteString(str, len - 1);
	} else
		return;
}

void inverteInteiro(int x) {
	if (x == 0)
		return;
	else {
		fprintf(stdout, "%d", x%10);
		inverteInteiro(x/10);
	}
}

void decimalBinario(int x) {
	if (x > 1) {
		decimalBinario(x/2);
		fprintf(stdout, "%d", x%2);
	} else
		fprintf(stdout, "%d", x);
}

int menorElemento(int *vet, int n) {
	if (n == 0) {
		return vet[n - 1];
	} else {
		if (vet[n - 1] < menorElemento(vet, n - 1))
			return vet[n - 1];
		else
			return menorElemento(vet, n - 1);
	}
}