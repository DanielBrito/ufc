#include<stdio.h>
#include<stdlib.h>
#include "lista.h"

int main(){

	Lista* listaA;

	listaA = cria();

	listaA = insere(listaA, 9);
	listaA = insere(listaA, 0);
	listaA = insere(listaA, 7);
	listaA = insere(listaA, 8);
	listaA = insere(listaA, 0);
	listaA = insere(listaA, 5);
	listaA = insere(listaA, 6);
	listaA = insere(listaA, 0);
	listaA = insere(listaA, 3);
	listaA = insere(listaA, 4);
	listaA = insere(listaA, 0);
	listaA = insere(listaA, 1);

	printf("Lista original:  ");
	imprime(listaA);

	printf("\n\n");

	printf("Lista sem os elementos nulos: ");

	listaA = removeNulos(listaA);

	imprime(listaA);

	printf("\n\n");

	printf("Numeros primos da lista: ");

	listaA = encontraPrimos(listaA);

	imprime(listaA);

	printf("\n\n");

	libera(listaA);

	return 0;
}