#include<stdio.h>
#include<stdlib.h>

void troca(int v[], int i,int j);
void quicksort(int v[], int esq, int dir);
int particao(int v[],int esq,int dir);


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

    quicksort(vetor,0,tam-1);

    printf("Ordenado:\n");

    for(i=0; i<tam; i++){

        printf("%d ",vetor[i]);
    }

      printf("\n\n");

      return 0;
}


    void troca(int v[], int i,int j){

      int temp;

      temp=v[i];
      v[i]=v[j];
      v[j]=temp;
    }


void quicksort(int v[], int esq, int dir){

    int i;

    if(esq>=dir){

        return ;
    }

    i=particao(v,esq,dir);

    quicksort(v,esq,i-1);
    quicksort(v,i+1,dir);
}


int particao(int v[],int esq,int dir){

    int i, fim;

    troca(v,esq,(esq+dir)/2);

    fim=esq;

    for(i=esq+1;i<=dir;i++){

        if(v[i]<v[esq]){

            troca(v,++fim,i);
        }

    }

    troca(v,esq,fim);

    return fim;
}
