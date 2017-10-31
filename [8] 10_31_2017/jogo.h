struct Guerreiro {
	int ataque;
	int defesa;
	int pontos_vida;
	int id_jogador;
};

typedef struct Guerreiro Guerreiro;

int rolaDados();

void criaGuerreiro(Guerreiro *guerreiro);

void ataca(Guerreiro *atk, Guerreiro *def);