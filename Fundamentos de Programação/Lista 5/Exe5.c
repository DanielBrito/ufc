#include<stdio.h>

void imprime_mes(int m)
{
    if(m==1)
    {
        printf("\n1 - Janeiro\n\n");
    }
    else
    if(m==2)
    {
        printf("\n2 - Fevereiro\n\n");
    }
    else
    if
    (m==3)
    {
        printf("\n3 - Marco\n\n");
    }
}

int main()
{
    int mes;

    printf("Digite um numero que representa um mes do 1o trimestre: ");
    scanf("%d", &mes);

    if(mes<1 || mes>3)
        printf("\nMes invalido!\n\n");
    else
        imprime_mes(mes);

    system("PAUSE");
    return 0;
}
