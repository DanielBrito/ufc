#include<stdio.h>
#include<stdlib.h>
#include "lista.h"

int main(){

	Lista* listaA;
	Lista* listaB;
	Lista* listaC;

	listaA = cria();
	listaB = cria();

	listaA = insereOrdenado(listaA, 14);
	listaA = insereOrdenado(listaA, 31);
	listaA = insereOrdenado(listaA, 21);
	listaA = insereOrdenado(listaA, 15);
	listaA = insereOrdenado(listaA, 12);

	listaB = insereOrdenado(listaB, 1);
	listaB = insereOrdenado(listaB, 30);
	listaB = insereOrdenado(listaB, 20);
	listaB = insereOrdenado(listaB, 14);
	listaB = insereOrdenado(listaB, 12);

	printf("Lista A:  ");
	imprime(listaA);

	printf("\n");

	printf("Lista B:  ");
	imprime(listaB);

	printf("\n\n");

	printf("Uniao dos conjuntos: ");

	listaC = uniaoDeConjuntos(listaA, listaB);

	imprime(listaC);

	printf("\n\n");

	printf("Intersecao dos conjuntos: ");

	listaC = intersecaoDeConjuntos(listaA, listaB);

	imprime(listaC);

	printf("\n\n");

	libera(listaA);
	libera(listaB);
	libera(listaC);

	return 0;
}