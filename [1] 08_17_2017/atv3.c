#include <stdio.h>
#include <stdlib.h>

int main() {

    char cpf[10] = "";
    int cont;
    int i;

    printf("\nCPF: ");
    scanf("%s",&cpf);

    printf("\nCPF sem digito verificador: %s", cpf);

    cont = 0;
    for (i = 0; i < 9; i++) {
        cont += (cpf[i] - '0')//Conversão do char 'x' para o int x
            * (i*-1+10);//Função (f(x) = -x+10) para determinar o peso*
    }

    //Atribui a dezena do codigo verificador de acordo com o resultado de (cont%11)
    if (cont%11 == 0 || cont%11 == 1) cpf[9] = '0';
    else cpf[9] = (char)((11 - (cont % 11)) + '0');

    cont = 0;
    for (i = 0; i < 10; i++) {
        cont += (cpf[i] - '0')//Conversão do char 'x' para o int x
                * (i * -1 + 11);//Função (f(x) = -x+11) para determinar o peso*
    }

    //Atribui a unidade do codigo verificador de acordo com o resultado de (cont%11)
    if (cont%11 == 0 || cont%11 == 1) cpf[10] = '0';
    else cpf[10] = (char)((11 - (cont % 11)) + '0');

    printf("\nCPF com digito verificador: %s\n",cpf);

    system("pause");
    return 0;
}
