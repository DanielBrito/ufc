#include<stdio.h>

#define TAM 5  // ALTERAR PARA 10

int main()
{
    int vetor[TAM];
    int i, quadrado=0, soma_quadrado=0;

    for(i=0; i<TAM; i++)
    {
        printf("Digite o %do valor: ", i+1);
        scanf("%d", &vetor[i]);

        quadrado = vetor[i]*vetor[i];

        soma_quadrado = soma_quadrado+ quadrado;
    }

    printf("\n\n");

    printf("A soma dos quadrados dos valores digitados e %d\n\n", soma_quadrado);

    return 0;
}
