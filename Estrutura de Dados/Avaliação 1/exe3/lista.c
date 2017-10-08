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


Lista* separa(Lista* lA, int v){

	Lista* p=lA;

	Lista* lB=NULL;

	if(p==NULL){

		return NULL;
	}
	else{

		for(p; p!=NULL; p=p->prox){

			if(p->info == v){

				lB = p->prox;
				p->prox = NULL;
				return lB;
			}
		}

		return NULL;
	}


}