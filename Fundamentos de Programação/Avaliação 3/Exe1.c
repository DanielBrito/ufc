// Imprimir as letras 'e' de uma string na forma maiúscula

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

void muda(char *frase)
{
    int i, tam=0;

    tam = strlen(frase);

    for(i=0; i<tam; i++)
    {
        if(frase[i] == 'e')
        {
            printf("%c", toupper(frase[i]));
        }
        else
        {
            printf("%c", frase[i]);
        }
    }
}

int main()
{
    char string[30] = "minha frase tem muitas letras";

    muda(string);

    printf("\n\n");

    return 0;
}
