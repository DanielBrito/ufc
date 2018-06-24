#include<stdio.h>
#include<stdlib.h>
#include "lista.h"

int main(){

	Lista* lista, *listaA, *listaB;

	lista = cria();
	listaA = cria();
	listaB = cria();

	lista = insere(lista, 9);
	lista = insere(lista, 0);
	lista = insere(lista, 7);
	lista = insere(lista, 8);
	lista = insere(lista, 0);
	lista = insere(lista, 5);
	lista = insere(lista, 6);
	lista = insere(lista, 0);
	lista = insere(lista, 3);
	lista = insere(lista, 4);
	lista = insere(lista, 0);
	lista = insere(lista, 1);

	printf("Lista original:  ");
	imprime(lista);

	printf("\nLista sem os elementos nulos: ");
	lista = removeNulos(lista);
	imprime(lista);

	printf("\nNumeros primos da lista: ");
	lista = encontraPrimos(lista);
	imprime(lista);

	printf("\n\n");

	listaA = insere(listaA, 2);
	listaA = insere(listaA, 2);
	listaA = insere(listaA, 4);
	listaA = insere(listaA, 5);
	listaA = insere(listaA, 2);

	listaB = insere(listaB, 2);
	listaB = insere(listaB, 4);
	listaB = insere(listaB, 2);
	listaB = insere(listaB, 5);
	listaB = insere(listaB, 2);

	printf("Lista A:  ");
	imprime(listaA);

	printf("\nLista B:  ");
	imprime(listaB);

	printf("\nListas iguais? ");
	igualdade(listaA, listaB) ? printf("Sim") : printf("Não");

	printf("\n\n");

	libera(lista);
	libera(listaA);
	libera(listaB);

	return 0;
}