#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

int main(){

	Lista* listaA;
	Lista* listaB;
	Lista* listaC;
	Lista* listaD;
	Lista* listaE;
	Lista* listaF;

	listaA = cria();
	listaB = cria();
	listaC = cria();
	listaD = cria();
	listaE = cria();
	listaF = cria();

	listaA = insere(listaA, 3);
	listaA = insere(listaA, 6);
	listaA = insere(listaA, 9);
	listaA = insere(listaA, 12);
	listaA = insere(listaA, 15);

	listaB = insere(listaB, 2);
	listaB = insere(listaB, 4);
	listaB = insere(listaB, 6);
	listaB = insere(listaB, 8);
	listaB = insere(listaB, 10);

	listaD = insere(listaD, 3);
	listaD = insere(listaD, 5);
	listaD = insere(listaD, 7);
	listaD = insere(listaD, 10);
	listaD = insere(listaD, 12);

	listaE = insere(listaE, 5);
	listaE = insere(listaE, 4);
	listaE = insere(listaE, 3);
	listaE = insere(listaE, 2);
	listaE = insere(listaE, 1);

	printf("Lista A:\n");
	imprime(listaA);

	printf("\n\n");

	printf("Lista B:\n");
	imprime(listaB);

	printf("\n\n");

	listaC = somaListas(listaA, listaB);

	printf("Soma das listas:\n");
	imprime(listaC);

	printf("\n\n");

	printf("Lista D:\n");

	imprime(listaD);

	printf("\n\n");

	printf("Soma dos elementos primos da lista D:\n%d", somaPrimos(listaD));

	printf("\n\n");

	printf("Lista E:\n");
	imprime(listaE);

	printf("\n\n");

	int k = 3;

	listaE = removeKEsimaCelula(listaE, k);

	printf("Lista E sem o %do elemento: \n", k);
	imprime(listaE);

	printf("\n\n");

	int l = 1;

	listaE = retiraK(listaE, l);

	printf("Lista E sem o %do elemento: \n", l);
	imprime(listaE);

	printf("\n\n");

	printf("Lista A e Lista B intercaladas:\n");
	
	listaF = intercala(listaA, listaB);

	imprime(listaF);

	printf("\n\n");

	libera(listaA);
	libera(listaB);
	libera(listaC);
	libera(listaD);
	libera(listaE);
	libera(listaF);

	return 0;
}