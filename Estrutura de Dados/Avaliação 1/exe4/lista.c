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


Lista* constroi(int* v, int n){

	Lista* listaV;
	listaV = cria();

	int i;

	for(i=0; i<n; i++){

		Lista* novo = (Lista*)malloc(sizeof(Lista));

		Lista* p = listaV;

		novo->info = v[i];
		novo->prox = listaV;

		if(p==NULL){

			listaV = novo;
		}
		else{

			while(p->prox!=NULL){

				p = p->prox;
			}

			p->prox = novo;
			novo->prox = NULL;
		}
	}

	return listaV;
}