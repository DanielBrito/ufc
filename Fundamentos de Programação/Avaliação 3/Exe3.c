// Verificador de senha

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

int conta_letras(char string[], int t)
{
    int i, cont_letra = 0;

    for(i=0; i<t; i++)
    {
        if(isalpha(string[i]) != 0)
        {
            cont_letra++;
        }
    }

    return cont_letra;
}

int conta_numeros(char string[], int t)
{
    int i, cont_numero = 0;

    for(i=0; i<t; i++)
    {
        if(isdigit(string[i]) != 0)
        {
            cont_numero++;
        }
    }

    return cont_numero;
}

int main()
{
    char senha[50] = "";
    int tam = 0;
    int qtd_letras = 0, qtd_numeros = 0;


    printf("Digite a senha: ");
    scanf("%s", senha);

    tam = strlen(senha);

    qtd_letras = conta_letras(senha, tam);
    qtd_numeros = conta_numeros(senha, tam);

    /*

    printf("LETRAS: %d\nNUMEROS: %d", qtd_letras, qtd_numeros); // TESTE DE IMPRESSAO

    */

    if(((tam>=6) && (tam<=10)) && qtd_letras>=1 && qtd_numeros>=2)
    {
        puts("Senha valida!");
    }
    else
    {
        puts("Senha invalida!");
    }

    printf("\n\n");

    return 0;
}
