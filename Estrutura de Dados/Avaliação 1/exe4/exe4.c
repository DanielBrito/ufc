// AVALIAÇÃO - QUESTÃO 4:

/* 

Considerando o tipo Lista definido na primeira questão, implemente uma função que receba 
um vetor de valores inteiros com n elementos e construa uma lista encadeada armazenando 
os elementos do vetor nas células da lista. Assim, se for recebido um vetor 
v[5] = {7, 5, 3, 13, 11}, a função deve retornar uma lista cuja primeira célula tem a 
informação 7, a segunda a informação 5, e assim por diante. Se o vetor tiver zero 
elementos, a função deve ter como valor de retorno uma lista vazia. O protótipo da 
função é dado por Lista* constroi(int* v, int n).

*/

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