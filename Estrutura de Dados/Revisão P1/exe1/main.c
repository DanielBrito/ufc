#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

/* Implemente uma função que percorra uma lista encadeada de inteiros l e
retorne uma outra lista (sem criar novos nós) que contenha apenas os elementos
cujo conteúdo é um número ímpar. A função retorna um apontador para a nova
lista e a lista recebida como parâmetro deve ser modificada de modo que os
valores 'retirados' para a nova lista não devem mais pertencer à l. O protótipo
da função é dado por: Lista* listaImpares(Lista* l, Lista* par); */

int main(){

	Lista* l = cria();
	Lista* par = cria();

	l = insere(l,9);
	l = insere(l,4);
	l = insere(l,8);
	l = insere(l,5);
	l = insere(l,2);
	l = insere(l,7);

	imprime(l);

	l = listaImpares(l, &par);

	imprime(l);

	imprime(par);

	libera(l);
	libera(par);

	return 0;
}
