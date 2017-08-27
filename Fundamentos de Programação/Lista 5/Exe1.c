#include<stdio.h>

void caracteres(char);

int main()
{
    char c;

    printf("Digite um caractere: ");
    scanf("%c", &c);

    caracteres(c);

    system("PAUSE");
    return 0;
}

void caracteres(char ch)
{
    int i;

    for(i=0; i<10; i++)
    {
        printf("%c", ch);
    }
}
