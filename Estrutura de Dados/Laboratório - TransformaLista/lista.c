#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

struct lista{

	char info;
	struct lista* prox;
};

Lista* listaCria(){

	return NULL;
}

Lista* listaInsere(Lista* l, char ch){

	Lista* ant = NULL;
	Lista* aux = l;

	while(aux!=NULL){

		ant = aux;
		aux = aux->prox;
	}

	Lista* novo = (Lista*) malloc(sizeof(Lista));
	novo->info = ch;

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

Lista* listaRemoveInicio(Lista* l){

	Lista* aux;

	if(listaVazia(l)){

		return NULL;
	}

    aux = l;
    l = l->prox;

    free(aux);

	return l;
}

int listaVazia(Lista* l){

    return l==NULL;
}

char listaRetornaInicio(Lista* l){

	if(listaVazia(l)){

		exit(1);
	}

	return l->info;
}

void setProx(Lista* l, Lista* p){

    l->prox = p;
}

void listaLibera(Lista* l){

	Lista* p=l;

	while(p!=NULL){

		Lista* t = p->prox;
		free(p);
		p = t;
	}
}

void listaImprime(Lista* l){

	Lista* p;

	for(p=l; p!=NULL; p=p->prox){

		printf("%c  ", p->info);
	}
}