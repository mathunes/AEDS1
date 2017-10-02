#include <stdio.h>

int stringLength (char *str);
void cleanString (char *str, size_t size);

int main() {
	char line[128];
	cleanString(line, sizeof(line));

	printf("Digite uma linha de ate 127 caracteres:\n");
	fflush(stdin);
	fgets(line, 128, stdin);
	printf("\nLinha digitada: [%s]\n", line);
	printf("\nTamanho da linha digitada = %d \n", stringLength(line));
	
	return 0;
}

int stringLength (char *str) {
	int i, count = 0;

	for (i = 0; i < 128; i++) {
		if (*(str + i) != '\0')
			count++;
	}

	return count; 
}

void cleanString (char *str, size_t size) {
	int i;

	for (i = 0; i < size; i++) {
		*(str + i) = '\0';
	}
}