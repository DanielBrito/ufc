#include <stdio.h>
#include <stdlib.h>
#include <sys/resource.h>
#include "ordenacao.h"

#define MAX 1000000
#define SEMENTE 5

static void vetorAleatorio(int* v, unsigned int n);

int main(){

    int *v = (int*)malloc(MAX*sizeof(int));
    long long int comparacoes=0, trocas=0;

    struct rusage resources;
    int rc;
    double utime, stime, total_time;

    FILE* arquivo;

    arquivo = fopen("descricao.txt", "a");

    if(arquivo==NULL){

        printf("Erro na abertura do arquivo!\n");
        exit(1);
    }

    // vetorAleatorio(v, MAX);
    // bubbleSort(v, MAX, &comparacoes, &trocas);
    
    // vetorAleatorio(v, MAX);
    // insertionSort(v, MAX, &comparacoes, &trocas);

    // vetorAleatorio(v, MAX);
    // selectionSort(v, MAX, &comparacoes, &trocas);

    // vetorAleatorio(v, MAX);
    // heapSort(v, MAX, &comparacoes, &trocas);

    // vetorAleatorio(v, MAX);
    // mergeSort(v, MAX, &comparacoes, &trocas);

    vetorAleatorio(v, MAX);
    quickSort(0, MAX-1, v, &comparacoes, &trocas);

    if((rc=getrusage(RUSAGE_SELF, &resources))!=0){

        perror("getrusage failed");
    }

    utime = (double)resources.ru_utime.tv_sec + 1.e-6 * (double)resources.ru_utime.tv_usec;
	stime = (double)resources.ru_stime.tv_sec + 1.e-6 * (double)resources.ru_stime.tv_usec;
    total_time = utime+stime;

    printf("Total de comparacoes: %lld\nTotal de trocas: %lld\nTempo de Usuario: %.5f\nTempo de Sistema: %.5f\nTempo total: %.5f\n", comparacoes, trocas, utime, stime, total_time);
    fprintf(arquivo, "Total de comparacoes: %lld\nTotal de trocas: %lld\nTempo de Usuario: %.5f\nTempo de Sistema: %.5f\nTempo total: %.5f\n\n", comparacoes, trocas, utime, stime, total_time);    
 
    fclose(arquivo);

    printf("\nDados gravados no arquivo com sucesso!\n\n");

    free(v);

	return 0;
}

static void vetorAleatorio(int* v, unsigned int n){

    unsigned int i;
    srand(SEMENTE);

    for(i=0; i<n; i++){

        v[i] = rand();
    }
}