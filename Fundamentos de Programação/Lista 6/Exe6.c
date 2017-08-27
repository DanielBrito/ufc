#include<stdio.h>

int main()
{
    int vet_A[10] = {0, 2, 4, 6, 8, 10, 12, 14, 16, 18};
    int vet_B[10] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};
    int vet_C[20] = {0};
    int i=0, j=0, k=0;

    /*// RECEBER VALORES

    printf("* VALORES DO VETOR 1 *\n\n");

    for(i=0; i<10; i++)
    {
        printf("Digite o %2do valor: ", i+1);
        scanf("%d", &vet_A[i]);
    }

    printf("\n\n* VALORES DO VETOR 2 *\n\n");

    for(i=0; i<10; i++)
    {
        printf("Digite o %2do valor: ", i+1);
        scanf("%d", &vet_B[i]);
    }
    */

    printf("\n\n* VETORES INTERCALADOS *\n\n");

    for(k=0; k<20; k++)
    {
        if(k%2==0)
        {
            vet_C[k] = vet_A[i];
            i++;
        }
        else
        {
            vet_C[k] = vet_B[j];
            j++;
        }
    }

    // IMPRIMIR VETOR

    for(k=0; k<20; k++)
    {
        printf("%d\n", vet_C[k]);
    }

    return 0;
}
