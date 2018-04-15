#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

/* Uma maneira usual de representar um conjunto é pela lista de seus elementos.
Supondo esta representação, escreva uma função que receba duas listas de inteiros
l1 e l2 e retorne uma terceira lista l3 composta pela união dos elementos de
l1 e l2. A função retorna um apontador para a nova lista e as listas recebidas
como parâmetro não devem ser modificadas. O protótipo da função é dado por:
Lista* listaUniao(Lista* l1, Lista* l2); */

int main(){

	Lista* lA = cria();
	Lista* lB = cria();
	Lista* lU = cria();

	lA = insere(lA,9);
	lA = insere(lA,30);
	lA = insere(lA,5);
	lA = insere(lA,15);
	lA = insere(lA,7);

	lB = insere(lB,15);
	lB = insere(lB,30);
	lB = insere(lB,7);
	lB = insere(lB,20);

	printf("Lista A:\n"); 
	imprime(lA);

	printf("\n");

	printf("Lista B:\n"); 
	imprime(lB);

	printf("\n");

	printf("Uniao de A e B:\n");

	lU = listaUniao(lA, lB);
	imprime(lU);

	libera(lA);
	libera(lB);
	libera(lU);

	return 0;
}
