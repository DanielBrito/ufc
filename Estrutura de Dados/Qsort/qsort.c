#include <stdio.h>
#include <stdlib.h>

int comparaCrescente(const void* a, const void* b);
int comparaDecrescente(const void* a, const void* b);
void imprimeVetor(int* v, int n);

int main(){

    int i, vet[10] = {23,4,67,-8,54,90,21,14,-5,1};

    printf("Vetor original:\n");
    imprimeVetor(vet, 10);

    printf("\nVetor crescente:\n");
    qsort(vet, 10, sizeof(int), comparaCrescente);
    imprimeVetor(vet, 10);

    printf("\nVetor decrescente:\n");
    qsort(vet, 10, sizeof(int), comparaDecrescente);
    imprimeVetor(vet, 10);

    return 0;
}

int comparaCrescente(const void* a, const void* b){

    if(*(int*)a==*(int*)b){

        return 0;
    }
    else{

        if(*(int*)a<*(int*)b){

            return -1;
        }
        else{

            return 1;
        }
    }
}

int comparaDecrescente(const void* a, const void* b){

    if(*(int*)a==*(int*)b){

        return 0;
    }
    else{

        if(*(int*)a<*(int*)b){

            return 1;
        }
        else{

            return -1;
        }
    }
}

void imprimeVetor(int* v, int n){

    int i;

    for(i=0; i<n; i++){

        printf("%d ", v[i]);
    }

    printf("\n");
}