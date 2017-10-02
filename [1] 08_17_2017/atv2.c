#include <stdio.h>
#include <math.h>

void verificarSeSaudavel(float imc) {
	if (!(imc > 18.5 && imc <= 25)) {
		if (imc < 18.5)
			printf(" e elx precisa ganhar %.2fkg para se enquadrar como saudavel.",(18.5 - imc));
		else if (imc > 25)
			printf(" e elx precisa perder %.2fkg para se enquadrar como saudavel.",(imc - 25));
	}
}


int main() {
	float altura = 0;
	float peso = 0;
	float imc = 0;
	
	//BRUTUS
	altura = 1.84;
	peso = 122;
	imc = (peso /(pow(altura,2)));
	
	printf("\nO IMC de Brutus e de %.2f",imc);
	verificarSeSaudavel(imc);
	
	//OLIVIA
	altura = 1.76;
	peso = 45;
	imc = (peso /(pow(altura,2)));

	printf("\nO IMC de Olivia e de %.2f",imc);
	verificarSeSaudavel(imc);

	printf("\n\n");
	system("pause");
	return 0;
}
