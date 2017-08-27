#include<stdio.h>

int soma();

int main()
{
    int num;

    printf("Digite um numero inteiro (n): ");
    scanf("%d", &num);

    int resultado = soma(num);

    printf("\nA soma dos numeros divisiveis por 3 entre 1 e %d e %d.\n\n", num, resultado);

    system("PAUSE");
    return 0;
}

int soma(int n)
{
    int i, result=0;

    for(i=0; i<=n; i++)
    {
        if(i%3==0)
        {
            result = result+i;
        }
    }

    return result;
}
