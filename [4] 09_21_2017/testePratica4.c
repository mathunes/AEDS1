#include <stdio.h>
#include "pratica4.h"

int main() {
	
	printf("\n");
	printf("50 km/h = %.2f m/s\n", paraMetrosPorSegundo(50.0));
	printf("Area do circulo de raio 25.5 = %.2f\n", areaCirculo(25.5));
	printf("5 E %s\n10 E %s\n",ehPar(5) ? "Par" : "Impar", ehPar(10) ? "Par" : "Impar");
	printf("15 %s divisivel por 3 ou 5\n12 %s divisivel por 3 ou 5\n50 %s divisivel po 3 ou 5\n", ehDivisivelPor3ou5(15) ? "E" : "NAO E", ehDivisivelPor3ou5(12) ? "E" : "NAO E", ehDivisivelPor3ou5(50) ? "E" : "NAO E");
	printf("Mulher de 1.7m o peso ideal e %.2f\nHomem de 2.2m o peso ideal e %.2f\n", pesoIdeal(1.7,'f'), pesoIdeal(2.2, 'M'));
	printf("Valores: 1, 5, 6\n");
	printf("Media Geometrica: %.2f\n", calculaMedia(1,5,6,1));
	printf("Media Ponderada: %.2f\n", calculaMedia(1,5,6,2));
	printf("Media Harmonica: %.2f\n", calculaMedia(1,5,6,3));
	printf("Media Aritimetica: %.2f\n", calculaMedia(1,5,6,4));
	printf("Soma dos impares de 15 = %d\n", somaImpares(15));
	printf("Fatorial de 5 = %.2f\n", fatorial(5));
	printf("Soma dos numeros divisiveis por 3 ou 5 de 20 = %d\n", somaNumerosDiv3ou5(20));
	printf("Quantidade de divisores de 66 = %d\n", numeroDivisores(66));
	printf("Fibonacci[8] = %d\n", enesimoFibonacci(8));
	printf("MDC 18 e 12 = %d\n", mdc(18,12));
	printf("MMC 18 e 12 = %d\n", mmc(18,12));

	return 0;
}
