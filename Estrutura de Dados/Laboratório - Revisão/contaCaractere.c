#include<stdio.h>
#include<string.h>

int conta_char(char* str, char c)
{
    int i, cont = 0;

    for(i=0; i<strlen(str); i++)
    {
        if(c == str[i])
        {
            cont++;
        }
    }

    return cont;
}

int main()
{
    char string[20];
    char letra;

    printf("Digite uma string: ");
    scanf(" %[^\n]", string);

    printf("Digite um caractere: ");
    scanf(" %c", &letra);

    printf("\n\n");

    printf("O caractere '%c' aparece %d vez(es) na string '%s'.\n\n", letra, conta_char(string, letra), string);

    return 0;
}
