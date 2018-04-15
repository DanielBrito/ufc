#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

/* Seja l uma lista de inteiros de tamanho k. Implemente uma função recursiva
que retorna uma nova lista ln, tal que casa célula i de ln seja formada pela 
multiplicação de todos os elementos pares da sub-lista de l que se inicia na 
célula i. O protótipo da função é dado por: Lista* multiplicaPares(Lista* l); */

int main(){

	Lista* l = cria();
	Lista* lResult = cria();

	l = insere(l,2);
	l = insere(l,2);
	l = insere(l,5);
	l = insere(l,7);
	l = insere(l,3);
	l = insere(l,9);
	l = insere(l,2);

	printf("Lista:\n"); 
	imprime(l);

	printf("\n");

	lResult = multiplicaParesInterativo(l);

	printf("Resultado:\n"); 
	imprime(lResult);

	libera(l);
	libera(lResult);

	return 0;
}
