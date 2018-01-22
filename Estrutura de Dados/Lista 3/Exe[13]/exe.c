#include<stdio.h>
#include<stdlib.h>
#include "lista.h"

int main(){

	Lista* listaA;
	Lista* listaB;

	listaA = cria();
	listaB = cria();

	listaA = insere(listaA, 5);
	listaA = insere(listaA, 4);
	listaA = insere(listaA, 3);
	listaA = insere(listaA, 2);
	listaA = insere(listaA, 1);

	printf("Lista original:  ");
	imprime(listaA);

	printf("\n\n");

	printf("Lista invertida: ");

	listaA = inverteLista(listaA);

	imprime(listaA);

	printf("\n\n");

	libera(listaA);
	libera(listaB);

	return 0;
}