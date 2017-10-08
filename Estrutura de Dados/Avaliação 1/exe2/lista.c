#include "lista.h"
#include <stdlib.h>
#include <stdio.h>

struct lista{

	int info;
	struct lista* prox;
};


Lista* cria(){

	return NULL;
}


Lista* insere(Lista* l, int i){

	Lista* novo = (Lista*) malloc(sizeof(Lista));
	novo->info = i;
	novo->prox = l;
	return novo;
}


void libera(Lista* l){

	Lista* p=l;

	while(p!=NULL){

		Lista* t = p->prox;

		free(p);

		p = t;
	}
}


void imprime(Lista* l){

	Lista* p;

	for(p=l; p!=NULL; p=p->prox){

		printf("%d  ", p->info);
	}
}


Lista* insereOrdenado(Lista* l, int v){

	Lista* novo;
	Lista* ant = NULL;
	Lista* atual = l;

	while(atual!=NULL && atual->info < v){

		ant = atual;
		atual = atual->prox; 
	}

	novo = (Lista*) malloc(sizeof(Lista));
	novo->info = v;

	if(ant == NULL){

		novo->prox = l;
		l = novo;
	}
	else{

		novo->prox = ant->prox;
		ant->prox = novo;		
	}

	return l;
}


// AVALIAÇÃO - QUESTÃO 2:

/* 

Considerando o tipo Lista definido na primeira questão, implemente uma função recursiva 
que intercala duas listas ordenadas, produzindo uma terceira lista ordenada. Não devem 
ser alocadas novas células extras, as células devem ser religadas para compor a nova 
lista ordenada. O protótipo da função é dado por Lista* intercala(Lista* l1, Lista* l2).

*/

Lista* intercala(Lista* lA, Lista* lB){

	if(lA == NULL){

		return lB;
	}
	else
	if(lB == NULL){

		return lA;
	}
	else
	if(lA->info <= lB->info){

		lA->prox = intercala(lA->prox, lB);
		return lA;
	}
	else{

		lB->prox = intercala(lB->prox, lA);
		return lB;
	}
}