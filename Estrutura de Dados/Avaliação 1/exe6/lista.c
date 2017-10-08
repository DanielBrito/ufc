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


Lista* inverteLista(Lista* l){

	Lista* p = l;
	Lista* ant = NULL;
	Lista* aux;

	while(p!=NULL){

		aux = p->prox;
		p->prox = ant;
		ant = p;
		p = aux;
	}

	l = ant;

	return l;
}