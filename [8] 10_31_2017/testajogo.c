#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "jogo.h"

int main() {
	Guerreiro guerreiro1;
	Guerreiro guerreiro2;
	Guerreiro vencedor;
	int rodada = 1;

	srand((unsigned)time(NULL));

	guerreiro1.id_jogador = 1;
	criaGuerreiro(&guerreiro1);

	guerreiro2.id_jogador = 2;
	criaGuerreiro(&guerreiro2);

	do {
		if (rodada%2 != 0)
			ataca(&guerreiro1, &guerreiro2);
		else
			ataca(&guerreiro2, &guerreiro1);

		rodada++;
	} while (guerreiro1.pontos_vida > 0 && guerreiro2.pontos_vida > 0);

	vencedor = (guerreiro1.pontos_vida == 0) ? guerreiro2 : guerreiro1;

	printf("guerreiro %d venceu!", vencedor.id_jogador);

	return 0;	
}