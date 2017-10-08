// AVALIAÇÃO - QUESTÃO 2:

/* 

Considerando o tipo Lista definido na primeira questão, implemente uma função recursiva 
que intercala duas listas ordenadas, produzindo uma terceira lista ordenada. Não devem 
ser alocadas novas células extras, as células devem ser religadas para compor a nova 
lista ordenada. O protótipo da função é dado por Lista* intercala(Lista* l1, Lista* l2).

*/

#include<stdio.h>
#include<stdlib.h>
#include "lista.h"

int main(){

	Lista* listaA;
	Lista* listaB;

	listaA = cria();
	listaB = cria();

	listaA = insereOrdenado(listaA, 13);
	listaA = insereOrdenado(listaA, 4);
	listaA = insereOrdenado(listaA, 20);
	listaA = insereOrdenado(listaA, 2);
	listaA = insereOrdenado(listaA, 31);

	listaB = insereOrdenado(listaB, 9);
	listaB = insereOrdenado(listaB, 13);
	listaB = insereOrdenado(listaB, 2);
	listaB = insereOrdenado(listaB, 5);
	listaB = insereOrdenado(listaB, 1);

	printf("Lista A:  ");
	imprime(listaA);

	printf("\n");

	printf("Lista B:  ");
	imprime(listaB);

	printf("\n\n");

	printf("Listas ordenadas intercaladas: ");

	listaA = intercala(listaA, listaB);

	imprime(listaA);

	printf("\n\n");

	libera(listaA);
	libera(listaB);

	return 0;
}