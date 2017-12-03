#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>
#include "mapeamento.h"

#define MAX 256


int main(){

	char vetor[MAX];
	int nextFitAux=0;
	int* nextFitAuxP = &nextFitAux;

    inicializarVetor(vetor);
	inicializarPosicoesOcupadas(vetor);

	system("clear");

	menu(vetor, nextFitAuxP);
	
	printf("\n");

	return 0;
}