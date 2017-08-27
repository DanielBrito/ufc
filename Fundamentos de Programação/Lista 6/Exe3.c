#include<stdio.h>
#define TAM 101

int main()
{
    float vet[TAM];
    int i, n=300;

    for(i=0; i<TAM; i++)
    {
        vet[i] = n;

        /*

        // TESTE DE IMPRESSAO

        printf("Posicao %3d | Valor %.2f\n", i+1, vet[i]);

        n++;

        */

        if(i>=0 && i<50) // Triplica os valores de 300 à 349
        {
            printf("Posicao %3d | Valor %.2f\n", i+1, vet[i]*3);
        }
        else
        if(i>=50 && i<=TAM) // Divide os valores de 350 à 400
        {
            printf("Posicao %3d | Valor %.2f\n", i+1, vet[i]/4);
        }

        n++;
    }

    return 0;
}
