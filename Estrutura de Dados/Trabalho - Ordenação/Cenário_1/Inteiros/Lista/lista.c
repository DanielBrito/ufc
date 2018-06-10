#include <stdlib.h>
#include <stdio.h>
#include "lista.h"

struct lista{

	int info;
	struct lista* prox;
};

Lista* cria(){

	return NULL;
}

void libera(Lista* l){

	Lista* p=l;

	while(p!=NULL){

		Lista* t = p->prox;

		free(p);

		p = t;
	}
}

Lista* insere(Lista* l, int i){

	Lista* novo = (Lista*) malloc(sizeof(Lista));
	novo->info = i;
	novo->prox = l;
	return novo;
}

Lista* insereFinal(Lista* l, int i){

	Lista* ant = NULL;
	Lista* aux = l;

	while(aux!=NULL){

		ant = aux;
		aux = aux->prox;
	}

	Lista* novo = (Lista*) malloc(sizeof(Lista));
	novo->info = i;

	if(ant==NULL){

		novo->prox = l;
		l = novo;
	}
	else{

		novo->prox = ant->prox;
		ant->prox = novo;
	}

	return l;
}

Lista* retira(Lista* l, int v){

	Lista* ant=NULL;
	Lista* p=l;

	while(p!=NULL && p->info!=v){

		ant = p;
		p = p->prox;
	}

	if(p==NULL){

		return l;
	}

	if(ant==NULL){

		l = p->prox;
	}
	else{

		ant->prox = p->prox;
	}

	free(p);

	return l;
}

int vazia(Lista* l){

	return (l==NULL);
}

Lista* busca(Lista* l, int v){

	Lista* p;

	for(p=l; p!=NULL; p=p->prox){

		if(p->info == v){

			return p;
		}
	}

	return NULL;
}


void imprime(Lista* l){

	Lista* p;

	for(p=l; p!=NULL; p=p->prox){

		printf("%d  ", p->info);
	}
}
