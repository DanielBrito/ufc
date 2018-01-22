#include<stdio.h>
#include<stdlib.h>

void insertionSortRec(int n, int *v){

  int i, j, x;

  if(n>1){

    insertionSortRec(n-1, v);

    x = v[n-1];

    for(i=n-2; i>=0 && v[i]<x; i--){

      v[i+1] = v[i];
    }

    v[i+1] = x;
  }
}

int main(){

    int tam, i;
    int* vetor;

    printf("Tamanho do vetor: ");
    scanf("%d", &tam);

    vetor = (int*)malloc(tam*sizeof(int));

    for(i=0; i<tam; i++){

        printf("Valor [%d]: ", i);
        scanf("%d", &vetor[i]);
    }

    printf("\n\n");

    printf("Vetor desordenado:\n");

    for(i=0; i<tam; i++){

        printf("%d ", vetor[i]);
    }

    printf("\n\n");

    insertionSortRec(tam, vetor);

    printf("Vetor ordenado (decrescente):\n");

    for(i=0; i<tam; i++){

        printf("%d ", vetor[i]);
    }

    printf("\n\n");
    return 0;
}
