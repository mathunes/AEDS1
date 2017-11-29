#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

#define BUFFER_TAM 5

int main(int argc, char *argv[]) {
	int countBuffer = 0, countTotal = 0, flag = 0;
	char ch;
	char *texto, *buffer, *textoAux;

	allocString(&buffer, BUFFER_TAM);

	fprintf(stdout, "\t\t::EDITOR DE TEXTOS::\nInsira seu texto a seguir. Para finalizar, digite '#'\n");
	do {
		ch = getche();

		//IF ch IS AN BREAK LINE, MAKE THE PROPPER CHANGES
		if (ch == '\r') {
			ch = '\n';
			fprintf(stdout, "\n");
		}

		//IF ch IS # DO NOT INSERT IT. INSERT '\0' INSTEAD
		buffer[countBuffer] = (ch == '#' ? '\0' : ch);

		countBuffer++;
		countTotal++;

		//IF countBuffer == 5, THEN
		if (countBuffer == BUFFER_TAM) {
			//AT FIRST TIME,
			if (!flag) {
				allocString(&texto, countTotal);
				strcpy(texto, buffer);
				flag = 1;
			//BEFORE THAT, 
			} else {
				allocString(&textoAux, countTotal);
				strcpy(textoAux, texto);
				
				free(texto);
				allocString(&texto, countTotal + countBuffer);				
				
				strcpy(texto, textoAux);
				strcat(texto, buffer);
				
				free(textoAux);
			}

			free(buffer);
			allocString(&buffer, BUFFER_TAM);
			
			countBuffer = 0;
		}

	} while (ch != '#');

	//IF THERE IS STRING IN THE BUFFER
	if (countBuffer > 0) {
		allocString(&textoAux, countTotal);
		strcpy(textoAux, texto);
		
		free(texto);
		allocString(&texto, countTotal + countBuffer);				
		
		strcpy(texto, textoAux);
		strcat(texto, buffer);
		
		free(textoAux);
		texto[countTotal - 1] = '\0';
		free(buffer);
	}

	fprintf(stdout, "\n\nTEXTO: [%s]\n", texto);
	free(texto);

	return 0;
}
