#include<stdio.h>
#include<stdlib.h>
#include "lista.h"

int main(){

	Lista* listaA;
	Lista* listaB;

	listaA = cria();
	listaB = cria();

	listaA = insere(listaA, 1);
	listaA = insere(listaA, 20);
	listaA = insere(listaA, 20);
	listaA = insere(listaA, 20);
	listaA = insere(listaA, 5);

	listaB = insere(listaB, 9);
	listaB = insere(listaB, 20);
	listaB = insere(listaB, 10);
	listaB = insere(listaB, 13);
	listaB = insere(listaB, 5);

	printf("Lista original: ");

	imprime(listaA);

	printf("\n\n");

	Lista* menor;
	menor = buscaMenorElemento(listaA);

	printf("Menor elemento da lista: ");
	imprimeUmElemento(menor);

	printf("\n\n");

	listaA = retiraValorMaximo(listaA);

	printf("Lista original sem o maior elemento: ");

	imprime(listaA);

	printf("\n\n");

	// printf("Quantidade de celulas da lista: %d", contaCelulas(listaA));

	// printf("\n\n");

	// printf("Listas concatenadas: ");

	// listaA = concatenaListas(listaA, listaB);

	// imprime(listaA);

	// printf("\n\n");

	// printf("Lista sem o elemento da k-esima posicao: ");

	// listaA = removeKEsimaCelula(listaA, 3);

	// imprime(listaA);

	// printf("\n\n");

	// printf("Quantidade de celulas da lista: %d", contaCelulas(listaA));

	// printf("\n\n");

	// printf("Lista sem os elementos repetidos: ");

	// listaA = removeElementosRepetidos(listaA);

	// imprime(listaA);

	// printf("\n\n");

	// printf("Quantidade de celulas da lista: %d", contaCelulas(listaA));

	// printf("\n\n");

	// printf("Quantas vezes o elemento 'x' aparece na lista: %d", contaElemento(listaA, 13));

	// printf("\n\n");

	// printf("Quantidade de numeros primos na lista: %d", contaPrimos(listaA));

	// printf("\n\n");

	// printf("Soma dos numeros primos da lista: %d", somaPrimos(listaA));

	// printf("\n\n");

	// printf("Lista sem o elemento 'x': ");

	// listaA = removeElementoX(listaA, 13);

	// imprime(listaA);

	printf("\n\n");

	libera(listaA);
	libera(listaB);

	return 0;
}