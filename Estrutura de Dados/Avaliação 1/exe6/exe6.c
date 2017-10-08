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