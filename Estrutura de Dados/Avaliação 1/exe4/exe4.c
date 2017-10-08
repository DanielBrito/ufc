#include<stdio.h>
#include<stdlib.h>
#include "lista.h"

int main(){


	int n, i;
	int *vetor;

	printf("Digite o tamanho do vetor: ");
	scanf("%d", &n);

	printf("\n");

	vetor = (int*)malloc(n*sizeof(int));

	for(i=0; i<n; i++){

		printf("Valor da posicao [%d]: ", i);
		scanf("%d", &vetor[i]);
	}

	printf("\n");


	// TESTE DE IMPRESSÃO:

	for(i=0; i<n; i++){

		printf("Valor da posicao [%d]: %d\n", i, vetor[i]);
	}


	printf("\n");

	Lista* listaVetor;

	printf("Lista com valores do vetor: ");

	listaVetor = constroi(vetor, n);

	imprime(listaVetor);

	printf("\n\n");

	libera(listaVetor);

	return 0;
}