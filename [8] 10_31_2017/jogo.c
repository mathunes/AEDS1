#include <stdlib.h>
#include <stdio.h>
#include "jogo.h"

int rolaDados() {
	int dados[3];
	int i;
	
	dados[0] = 1 + (rand()%6);
	dados[1] = 1 + (rand()%6);
	dados[2] = 1 + (rand()%6);

	return dados[0] + dados[1] + dados[2];
}

void criaGuerreiro(Guerreiro *guerreiro) {
	(*guerreiro).ataque = rolaDados();
	(*guerreiro).defesa = rolaDados();
	(*guerreiro).pontos_vida = rolaDados() + rolaDados() + rolaDados();
}

void ataca(Guerreiro *atk, Guerreiro *def) {
	int golpe = (*atk).ataque + rolaDados();
	int escudo = (*def).defesa + rolaDados();

	int dano = golpe - escudo;

	if (dano > 0)
		(*def).pontos_vida -= dano;
}