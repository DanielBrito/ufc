#include <stdio.h>
#include <stdlib.h>
#include "ordenacaoLista.h"

#define MAX 10

Lista* listaAleatoria(Lista* l, unsigned int len);

int main(){

	Lista* lBubble = criar();

	lBubble = listaAleatoria(lBubble, MAX);

	imprimir(lBubble);

	testar(lBubble)==1 ? printf("Ordenado.\n") : printf("Desordenado.\n");

	lBubble = bubbleSort(lBubble);

	printf("\n");

	imprimir(lBubble);

	testar(lBubble)==1 ? printf("Ordenado.\n") : printf("Desordenado.\n");

	liberar(lBubble);

	return 0;	
}

Lista* listaAleatoria(Lista* l, unsigned int len){

	unsigned int i;

	for(i=0; i<len; i++){

		l = inserir(l, rand()%50);
	}

	return l;
}