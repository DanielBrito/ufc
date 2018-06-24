#include<stdio.h>
#include<stdlib.h>
#include "lista.h"

int main(){

	Lista* listaA;
	Lista* listaB;

	listaA = cria();
	listaB = cria();

	listaA = insereOrdenado(listaA, 1);
	listaA = insereOrdenado(listaA, 2);
	listaA = insereOrdenado(listaA, 4);
	listaA = insereOrdenado(listaA, 10);
	listaA = insereOrdenado(listaA, 12);

	listaB = insereOrdenado(listaB, 3);
	listaB = insereOrdenado(listaB, 5);
	listaB = insereOrdenado(listaB, 21);
	listaB = insereOrdenado(listaB, 9);
	listaB = insereOrdenado(listaB, 13);
	listaB = insereOrdenado(listaB, 6);

	printf("Lista A:  ");
	imprime(listaA);

	printf("Lista B:  ");
	imprime(listaB);

	printf("\n");

	printf("Fusao das listas ordenadas:\n");

	listaA = fusaoDeListasOrdenadas(listaA, listaB);

	imprime(listaA);

	printf("\n");

	libera(listaA);
	libera(listaB);

	return 0;
}