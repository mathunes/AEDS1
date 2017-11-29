#include <stdio.h>

int verificaSorteado(int *cartela, int *sorteado);
int verificaNumero(int num, int *cartela);

int main(int argc, char *argv[]) {
	FILE *arq;
	int cartela[6];

	int sorteado[] = {6,9,22,23,48,52};
	int lost[] = {4,8,15,16,23,42};

	int acertos;

	int countSorteados = 0;
	int countQuina = 0;
	int countQuadra = 0;
	int countLost = 0;

	arq = fopen("cartelas.txt", "r");

		if (arq == NULL) {
			printf("Erro ao abrir o arquivo.\n");
			return 0;
		} else {
			while(!feof(arq)) {
				fscanf(arq, "%d %d %d %d %d %d", &cartela[0], &cartela[1], &cartela[2], &cartela[3], &cartela[4], &cartela[5]);

				acertos = verificaSorteado(cartela, sorteado);
				if (acertos == 6)
					countSorteados++;
				else if (acertos == 5)
					countQuina++;
				else if (acertos == 4)
					countQuadra++;

				if (verificaSorteado(cartela, lost) == 6)
					countLost++;
			}

			printf("\nTotal de vencedores: %d\nTotal de quinas: %d\nTotal de quadras: %d\nTotal de lost: %d\n", countSorteados, countQuina, countQuadra, countLost);
			fclose(arq);
			return 0;
		}
}

int verificaSorteado(int *cartela, int *sorteado) {
	int i;
	int acertos = 0;

	for (i = 0; i < 6; i++) {
		if (verificaNumero(cartela[i], sorteado))
			acertos++;
	}

	return acertos;
}

int verificaNumero(int num, int *cartela) {
	int i;

	for (i = 0; i < 6; i++) {
		if (cartela[i] == num) 
			return 1;
	}

	return 0;
}