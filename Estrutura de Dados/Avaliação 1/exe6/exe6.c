// AVALIAÇÃO - QUESTÃO 6:

/*

Considerando o tipo Lista definido na primeira questão, implemente uma função recursiva 
que recebe como entrada uma lista ordenada em ordem crescente e retorna uma lista ordenada 
em ordem decrescente. Faça isto sem criar novas células, apenas altere os ponteiros. 
O protótipo da função é dado por Lista* inverte(Lista* l)

*/

#include<stdio.h>
#include<stdlib.h>
#include "lista.h"

int main(){

	Lista* listaA;

	listaA = cria();

	listaA = insereOrdenado(listaA, 4);
	listaA = insereOrdenado(listaA, 2);
	listaA = insereOrdenado(listaA, 3);
	listaA = insereOrdenado(listaA, 1);
	listaA = insereOrdenado(listaA, 5);

	printf("Lista original:  ");
	imprime(listaA);

	printf("\n\n");

	printf("Lista invertida: ");

	listaA = inverteLista(listaA);

	imprime(listaA);

	printf("\n\n");

	libera(listaA);

	return 0;
}