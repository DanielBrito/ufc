#include<stdio.h>

#define TAM 10


int main()
{
    int vet_A[10] = {11, 12, 13, 14, 15, 16, 17, 18, 19, 20};
    int vet_B[10] = {61, 62, 63, 64, 65, 66, 67, 68, 69, 70};
                  /* 72  74  76  78  80  82  84  86  88  90 */
    int vet_C[10] = {0};
    int i;

    for(i=0; i<TAM; i++)
    {
        vet_C[i] = vet_A[i] + vet_B[i];
    }

    printf("ELEMENTOS DO VETOR A:\n");

    for(i=0; i<TAM; i++)
    {
        printf("%d  ", vet_A[i]);
    }

    printf("\n\nELEMENTOS DO VETOR B:\n");

    for(i=0; i<TAM; i++)
    {
        printf("%d  ", vet_B[i]);
    }

    printf("\n\nSOMA DOS VETORES A e B:\n");

    for(i=0; i<TAM; i++)
    {
        printf("%d  ", vet_C[i]);
    }

    printf("\n\n");

    return 0;
}
