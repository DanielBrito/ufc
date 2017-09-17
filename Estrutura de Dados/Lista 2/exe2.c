#include<stdio.h>
#include<stdlib.h>

void inverte(int* v, int t);

int main(){

    int tamanho, i;
    int* vetor;

    printf("Digite o tamanho do vetor: ");
    scanf("%d", &tamanho);

    vetor = (int*)malloc(tamanho*sizeof(int));

    for(i=0; i<tamanho; i++){

        printf("Numero [%d]: ", i);
        scanf("%d", &vetor[i]);
    }

    inverte(vetor, tamanho);

    printf("\n");

    printf("VETOR INVERTIDO\n");

    for(i=0; i<tamanho; i++){

        printf("%d ", vetor[i]);
    }

    printf("\n\n");

    free(vetor);

    return 0;
}


void inverte(int* v, int t){

    int aux;

    if(t==0 || t==1){

        return;
    }
    else{

        aux = v[0];
        v[0] = v[t-1];
        v[t-1] = aux;
        inverte(&v[1], t-2);
    }
}
