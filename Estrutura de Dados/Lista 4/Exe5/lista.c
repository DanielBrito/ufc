#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

struct lista{

	int info;
	struct lista* prox;
};

Lista* listaCria(){

	return NULL;
}

Lista* listaInsere(Lista* l, int v){

	Lista* novo = (Lista*) malloc(sizeof(Lista));
	novo->info = v;
	novo->prox = NULL;

	return novo;
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

int listaRetornaInicio(Lista* l){

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