#include <stdio.h>

int main() {
	float saldo = 0;
	float rendimentoMensal = 1.0056;
	
	//PRIMEIRO M�S
	saldo += 789.54;
	
	//SEGUNDO M�S
	saldo *= rendimentoMensal;
	saldo += 303.20;
	
	//TERCEIRO M�S
	saldo *= rendimentoMensal;
	saldo -= 58.25;
	
	//QUARTO M�S
	saldo *= rendimentoMensal;
	
	printf("\nR$%f\n\n",saldo);
	
	
	system("pause");
	return 0;
}
