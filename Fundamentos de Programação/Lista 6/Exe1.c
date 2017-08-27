#include<stdio.h>

float soma (float num[]);

int main()
{
    float num[6], resultado=0; // = [0] [1] [2] [3] [4] [5]
    int i;

    for(i=0; i<6; i++)
    {
        printf("Digite um valor: ");
        scanf("%f", &num[i]);
    }

    resultado = soma(num);

    printf("\n\nA soma dos numeros digitados e %.2f.\n\n", resultado);

    return 0;
}

float soma(float vet[])
{
    int i, total=0;

    for(i=0; i<6; i++)
    {
        total = vet[i]+total;
    }

    return total;
}
