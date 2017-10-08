// AVALIAÇÃO - QUESTÃO 3:

/* 

Considerando o tipo Lista definido na primeira questão, implemente uma função que receba 
como parâmetro uma lista encadeada e um valor inteiro v e divida a lista em duas, de tal 
forma que a segunda lista comece da primeira célula logo após a primeira ocorrência de v 
na lista original.

Essa função deve obedecer ao protótipo: Lista* separa(Lista*l, int v);

A função deve retornar um ponteiro para a segunda sub-divisão da lista original, enquanto 
l deve continuar apontando para o primeiro elemento da sub-divisão da lista.

*/

#include<stdio.h>
#include<stdlib.h>
#include "lista.h"

int main(){

	Lista* listaA;
	Lista* listaB;

	listaA = cria();
	listaB = cria();

	listaA = insere(listaA, 9);
	listaA = insere(listaA, 8);
	listaA = insere(listaA, 7);
	listaA = insere(listaA, 6);
	listaA = insere(listaA, 5);
	listaA = insere(listaA, 4);
	listaA = insere(listaA, 3);
	listaA = insere(listaA, 2);
	listaA = insere(listaA, 1);

	printf("Lista Original:  ");
	imprime(listaA);

	listaB = separa(listaA, 5);

	printf("\n\n");

	printf("Primeira sub-divisao: ");
	imprime(listaA);

	printf("\n");

	printf("Segunda sub-divisao: ");
	imprime(listaB);

	printf("\n\n");

	libera(listaA);
	libera(listaB);

	return 0;
}