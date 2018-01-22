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

	listaB = insere(listaB, 5);
	listaB = insere(listaB, 4);
	listaB = insere(listaB, 3);
	listaB = insere(listaB, 2);
	listaB = insere(listaB, 1);

	imprime(listaA);

	printf("\n");

	imprime(listaB);

	printf("\n\n");

	if(igualdadeMesmaOrdem(listaA, listaB)==1){

		printf("A ordem e os elementos das listas sao iguais.");
	}
	else{

		printf("A ordem e os elementos das listas sao diferentes.");
	}

	printf("\n\n");

	libera(listaA);
	libera(listaB);

	return 0;
}