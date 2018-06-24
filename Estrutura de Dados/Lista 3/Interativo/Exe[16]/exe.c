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

	printf("\n\nUniao dos conjuntos: ");
	listaC = uniaoDeConjuntos(listaA, listaB);
	imprime(listaC);

	printf("\n\nIntersecao dos conjuntos: ");
	listaC = intersecaoDeConjuntos(listaA, listaB);
	imprime(listaC);

	printf("\n\nDiferença de A-B: ");
	listaC = diferencaEntreConjuntos(listaA, listaB);
	imprime(listaC);

	int n = 40;

	printf("\n\nPertinência de %d no conjunto A: " , n);
	pertinencia(listaA, n) ? printf("Pertence") : printf("Não pertence");

	printf("\n\n");

	libera(listaA);
	libera(listaB);
	libera(listaC);

	return 0;
}