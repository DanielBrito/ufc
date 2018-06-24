#include<stdio.h>
#include<stdlib.h>
#include "lista.h"

int main(){

	Lista* listaA;
	Lista* listaB;
	Lista* listaC;
	Lista* listaD;
	Lista* listaE;
	Lista* listaF;
	Lista* listaG;

	listaA = cria();
	listaB = cria();
	listaC = cria();
	listaD = cria();
	listaE = cria();
	listaF = cria();
	listaG = cria();

	listaA = insere(listaA, 5);
	listaA = insere(listaA, 4);
	listaA = insere(listaA, 1);
	listaA = insere(listaA, 3);
	listaA = insere(listaA, 9);

	listaB = insere(listaB, 9);
	listaB = insere(listaB, 20);
	listaB = insere(listaB, 10);
	listaB = insere(listaB, 13);
	listaB = insere(listaB, 5);

	listaD = insere(listaD, 2);
	listaD = insere(listaD, 13);
	listaD = insere(listaD, 13);
	listaD = insere(listaD, 13);
	listaD = insere(listaD, 9);

	listaE = insereFinalRec(listaE, 1);
	listaE = insereFinalRec(listaE, 2);
	listaE = insereFinalRec(listaE, 3);
	listaE = insereFinalRec(listaE, 4);
	listaE = insereFinalRec(listaE, 5);

	listaF = insereFinalRec(listaF, 5);
	listaF = insereFinalRec(listaF, 4);
	listaF = insereFinalRec(listaF, 3);
	listaF = insereFinalRec(listaF, 2);
	listaF = insereFinalRec(listaF, 1);

	printf("Lista A:\n");
	imprime(listaA);

	printf("\n\n");

	Lista* menor;
	menor = buscaMenorElemento(listaA);

	printf("Menor elemento da Lista A:\n");
	imprimeUmElemento(menor);

	printf("\n\n");

	printf("Lista B:\n");
	imprime(listaB);

	printf("\n\n");

	listaB = retiraValorMaximo(listaB);

	printf("Lista B sem o maior elemento:\n");

	imprime(listaB);

	printf("\n\n");

	printf("Quantidade de celulas da Lista A:\n%d", contaCelulas(listaB));

	printf("\n\n");

	printf("Lista C com as Listas A e B concatenadas:\n");

	listaC = concatenaListas(listaA, listaB);

	imprime(listaC);

	printf("\n\n");

	int k = 3;

	printf("Lista C sem o elemento da posição %d:\n", k);

	listaC = removeKEsimaCelula(listaC, k);

	imprime(listaC);

	printf("\n\n");

	int x = 5;

	printf("Lista C sem o elemento '%d':\n", x);

	listaC = removeElementoX(listaC, x);

	imprime(listaC);

	printf("\n\n");

	printf("Lista D:\n");
	imprime(listaD);

	printf("\n\n");

	printf("Lista D sem os elementos repetidos:\n");

	listaD = removeElementosRepetidos(listaD);

	imprime(listaD);

	printf("\n\n");

	x = 9;

	printf("Quantas vezes '%d' aparece na Lista C: \n%d", x, contaElemento(listaC, x));

	printf("\n\n");

	printf("Quantidade de numeros primos na Lista C: \n%d", contaPrimos(listaC));

	printf("\n\n");

	printf("Soma dos numeros primos da Lista C: \n%d", somaPrimos(listaC));

	printf("\n\n");

	printf("Lista E:\n");
	imprime(listaE);

	printf("\n\n");

	printf("Lista F:\n");
	imprime(listaF);

	printf("\n\n");

	printf("Soma das Listas E e F:\n");

	listaG = somaListas(listaE, listaF);

	imprime(listaG);

	printf("\n\n");

	libera(listaA);
	libera(listaB);
	libera(listaC);
	libera(listaD);
	libera(listaE);
	libera(listaF);
	libera(listaG);

	return 0;
}