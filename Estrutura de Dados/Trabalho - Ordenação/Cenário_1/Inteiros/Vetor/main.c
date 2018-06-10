#include <stdio.h>
#include <stdlib.h>
#include <sys/resource.h>
#include "quickSort.h"

#define MAX 5000

static void vetorAleatorio(int* v, unsigned int n);

int main(){

    struct rusage resources;
    int rc;
    double utime, stime, total_time;

    int* vetor = (int*)malloc(MAX*sizeof(int));
    int comparacoes =0;
    
    FILE* arquivo;

    arquivo = fopen("descricao.txt", "a");

    if(arquivo==NULL){

        printf("Erro na abertura do arquivo!\n");
        exit(1);
    }

    vetorAleatorio(vetor, MAX);
	quickSort(0, MAX-1, vetor, &comparacoes);

    if((rc=getrusage(RUSAGE_SELF, &resources))!=0){

        perror("getrusage failed");
    }

    utime = (double)resources.ru_utime.tv_sec + 1.e-6 * (double)resources.ru_utime.tv_usec;
    stime = (double)resources.ru_stime.tv_sec + 1.e-6 * (double)resources.ru_stime.tv_usec;
    total_time = utime+stime;

    printf("Total de comparacoes: %d\nTempo de usuario: %.5f\nTempo de sistema: %.5f\nTotal time: %.5f\n", comparacoes, utime, stime, total_time);

    fprintf(arquivo, "Total de comparacoes: %d\nTempo de usuario: %.5f\nTempo de sistema: %.5f\nTempo total: %.5f\n\n", comparacoes, utime, stime, total_time);
    
    fclose(arquivo);

    printf("\nDados gravados no arquivo com sucesso!\n\n");

    free(vetor);

	return 0;
}

static void vetorAleatorio(int* v, unsigned int n){

    unsigned int i;

    for(i=0; i<n; i++){

        v[i]=rand();
    }
}