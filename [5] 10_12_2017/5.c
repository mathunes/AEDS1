#include <stdio.h>

void upperCase (char *str, size_t size);
void lowerCase (char *str, size_t size);
void switchCase (char *str, size_t size);

void cleanString (char *str, size_t size);

int main() {
	char line[128];
	cleanString(line, sizeof(line));

	printf("Digite uma linha de ate 127 caracteres:\n");
	fflush(stdin);
	fgets(line, 128, stdin);
	printf("\nLinha digitada: [%s]\n", line);

	switchCase(line, sizeof(line));
	printf("\nsWiTcH lInHa: [%s]\n", line);		

	lowerCase(line, sizeof(line));
	printf("\nlower linha: [%s]\n", line);	

	upperCase(line, sizeof(line));
	printf("\nUPPER LINHA: [%s]\n", line);

	return 0;
}

void cleanString (char *str, size_t size) {
	int i;

	for (i = 0; i < size; i++) {
		*(str + i) = '\0';
	}
}

void switchCase(char *str, size_t size) {
	int i;

	for (i = 0; i < size; i++) {
		if ((*(str + i) >= 97) && (*(str + i) <= 122))
			*(str + i) -= 32;
		else if ((*(str + i) >= 65) && (*(str + i) <= 90))
			*(str + i) += 32;
	}
}

void upperCase(char *str, size_t size) {
	int i;

	for (i = 0; i < size; i++) {
		if ((*(str + i) >= 97) && (*(str + i) <= 122))
			*(str + i) -= 32;
	}
}

void lowerCase(char *str, size_t size) {
	int i;

	for (i = 0; i < size; i++) {
		if ((*(str + i) >= 65) && (*(str + i) <= 90))
			*(str + i) += 32;
	}
}