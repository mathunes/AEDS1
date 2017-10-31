#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "jogo.h"

Guerreiro guerreiros[16];
Guerreiro quartas[8], semi[4], finais[2], vencedor;

void inicializaCampeonato();
Guerreiro * combate(Guerreiro *guerreiro1, Guerreiro *guerreiro2);

int main() {	
	int rodada, i;

	srand((unsigned)time(NULL));

	inicializaCampeonato();

	/*OITAVAS DE FINAL*/
	rodada = 0;

	do {
		for (i = 0; i < 16; i++) {
			printf("COMBATE ENTRE OS GUERREIROS %d e %d\n", guerreiros[i].id_jogador, guerreiros[i+1].id_jogador);
			quartas[rodada++] = *(combate(&guerreiros[i], &guerreiros[i+1]));
			i++;
		}
	} while (rodada < 8);

	printf("\n::FIM DAS OITAVAS DE FINAL::\n::GUERREIROS RESTANTES:: [");
	for (i = 0; i < 8; i++) {
		printf(" %d ", quartas[i].id_jogador);
	}
	printf("]\n\n");
	/*FIM OITAVAS DE FINAL*/

	/*QUARTAS DE FINAL*/
	rodada = 0;

	do {
		for (i = 0; i < 8; i++) {
			printf("COMBATE ENTRE OS GUERREIROS %d e %d\n", quartas[i].id_jogador, quartas[i+1].id_jogador);
			semi[rodada++] = *(combate(&quartas[i], &quartas[i+1]));
			i++;
		}
	} while (rodada < 4);

	printf("\n::FIM DAS QUARTAS DE FINAL::\n::GUERREIROS RESTANTES:: [");
	for (i = 0; i < 4; i++) {
		printf(" %d ", semi[i].id_jogador);
	}
	printf("]\n\n");
	/*FIM QUARTAS DE FINAL*/

	/*SEMI FINAIS*/
	rodada = 0;

	do {
		for (i = 0; i < 4; i++) {
			printf("COMBATE ENTRE OS GUERREIROS %d e %d\n", semi[i].id_jogador, semi[i+1].id_jogador);
			finais[rodada++] = *(combate(&semi[i], &semi[i+1]));
			i++;
		}
	} while (rodada < 2);

	printf("\n::FIM DAS SEMI FINAIS::\n::GUERREIROS RESTANTES:: [");
	for (i = 0; i < 2; i++) {
		printf(" %d ", finais[i].id_jogador);
	}
	printf("]\n\n");
	/*FIM DAS SEMI FINAIS*/

	/*FINAIS*/
	printf("COMBATE ENTRE OS GUERREIROS %d e %d\n", finais[0].id_jogador, finais[1].id_jogador);
	vencedor = 	*(combate(&finais[0], &finais[1]));
	printf("\n::FIM DO CAMPEONATO::\nGUERREIRO %d FOI O VENCEDOR! HP RESTANTE = %d", vencedor.id_jogador, vencedor.pontos_vida);
	/*FIM DAS FINAIS*/

	return 0;
}

void inicializaCampeonato() {
	int i;

	for (i = 0; i < 16; i++) {
		guerreiros[i].id_jogador = (i);
		criaGuerreiro(&guerreiros[i]);
	}
}

Guerreiro * combate (Guerreiro *guerreiro1, Guerreiro *guerreiro2) {
	int round = 1;

	do {
		if (round%2 != 0)
			ataca(guerreiro1, guerreiro2);
		else
			ataca(guerreiro2, guerreiro1);

		round++;
	} while ((*guerreiro1).pontos_vida > 0 && (*guerreiro2).pontos_vida > 0);

	return ((*guerreiro1).pontos_vida == 0) ? guerreiro2 : guerreiro1;
}