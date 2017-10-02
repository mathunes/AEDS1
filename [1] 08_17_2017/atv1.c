#include <stdio.h>

int main() {
	float saldo = 0;
	float rendimentoMensal = 1.0056;
	
	//PRIMEIRO MÊS
	saldo += 789.54;
	
	//SEGUNDO MÊS
	saldo *= rendimentoMensal;
	saldo += 303.20;
	
	//TERCEIRO MÊS
	saldo *= rendimentoMensal;
	saldo -= 58.25;
	
	//QUARTO MÊS
	saldo *= rendimentoMensal;
	
	printf("\nR$%f\n\n",saldo);
	
	
	system("pause");
	return 0;
}
