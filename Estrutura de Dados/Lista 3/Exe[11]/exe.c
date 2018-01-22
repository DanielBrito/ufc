#include<stdio.h>
#include<stdlib.h>
#include "lista.h"

int main(){

	Lista* listaA;
	Lista* listaB;
	Lista* listaC;

	listaA = cria();
	listaB = cria();

	listaA = insere(listaA, 1);
	listaA = insere(listaA, 2);
	listaA = insere(listaA, 3);
	listaA = insere(listaA, 4);
	listaA = insere(listaA, 5);

	listaB = insere(listaB, 9);
	listaB = insere(listaB, 8);
	listaB = insere(listaB, 7);
	listaB = insere(listaB, 6);
	listaB = insere(listaB, 5);

	listaC = somaListas(listaA, listaB);

	imprime(listaC);

	printf("\n\n");

	libera(listaA);
	libera(listaB);
	libera(listaC);

	return 0;
}