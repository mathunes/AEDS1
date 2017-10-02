#include <stdio.h>

void aumentaOsIguais(int *end_var1, int *end_var2);
unsigned long long fast_pow_2(int exp);
int ddd(unsigned int num);
int soma1SePar(unsigned int num);
int parOuImpar(unsigned int num);

int main() {

	int x, y, expoente;
	unsigned int numero;

	//**FUNCAO aumentaOsIguais()

	printf("\n::aumentaOsIguais:: Insira valores de x e y:\n\n");
	printf("x: "); scanf("%d", &x);
	printf("y: "); scanf("%d", &y);

	aumentaOsIguais(&x, &y);
	printf("\n::FIM DA FUNCAO aumentaOsIguais:: x = %d e y = %d\n", x, y);

	//**************************************************************************//
	//**FUNCAO fast_pow_2()

	printf("\n::fast_pow_2:: Insira um valor para o expoente:\n\n");
	printf("Expoente: "); scanf("%d", &expoente);

	printf("\n::FIM DA FUNCAO fast_pow_2:: 2^(%d) = %llu\n", expoente, fast_pow_2(expoente));

	//**************************************************************************//
	//**FUNCAO ddd()

	printf("\n::ddd:: Insira um numero de telefone com ddd:\n\n");
	printf("Telefone: "); scanf("%d", &numero);

	printf("\n::FIM DA FUNCAO ddd:: ddd = %d\n", ddd(numero));

	//**************************************************************************//
	//**FUNCAO soma1SePar()

	printf("\n::soma1SePar:: Insira um numero:\n\n");
	printf("Numero: "); scanf("%d", &numero);

	printf("\n::FIM DA FUNCAO soma1SePar:: %u -> %d\n", numero, soma1SePar(numero));

	//**************************************************************************//
	//**FUNCAO parOuImpar()

	printf("\n::parOuImpar:: Insira um numero:\n\n");
	printf("Numero: "); scanf("%d", &numero);

	printf("\n::FIM DA FUNCAO parOuImpar:: %u -> %s\n", numero, parOuImpar(numero) ? "Impar" : "Par");

	return 0;
}

void aumentaOsIguais(int *end_var1, int *end_var2) {

	if (*end_var1 == *end_var2) {
		int sumAux = *end_var1 + *end_var2;

		*end_var1 = sumAux;
		*end_var2 = sumAux;
	} else {
		*end_var1 -= 1;
		*end_var2 -= 1; 
	}

}

unsigned long long fast_pow_2(int expoente) {
	return (1 << expoente);
}

int ddd(unsigned int num) {
	return ((num >> 24) / 6);
}

int soma1SePar(unsigned int num) {
	return (num | 1);
}

int parOuImpar(unsigned int num) {
	return (num & 1);
}
