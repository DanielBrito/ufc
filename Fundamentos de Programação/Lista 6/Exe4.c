#include<stdio.h>

int main()
{
    int vetor[5], i, soma=0, produto=1;

    for(i=0; i<5; i++)
    {
        printf("Digite o %do valor: ", i+1);
        scanf("%d", &vetor[i]);

        soma = soma+vetor[i];
        produto = produto*vetor[i];
    }

    printf("\n\nSOMA DOS VALORES: %d\n", soma);
    printf("PRODUTO DOS VALORES: %d\n\n", produto);

    /*

    // TESTE DE IMPRESSAO DOS VALORES DO VETOR
    printf("\n\n");

    for(i=0; i<5; i++)
    {
        printf("%d\n", vetor[i]);
    }

    */

    return 0;
}
