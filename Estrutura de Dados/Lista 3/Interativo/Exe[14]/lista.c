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

	printf("\n");
}


void imprimeUmElemento(Lista* l){

	if(l!=NULL){

		printf("%d", l->info);
	}
	else{

		printf("Lista vazia");
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


// QUESTÃO 14:

Lista* fusaoDeListasOrdenadas(Lista* lA, Lista* lB){

	Lista* auxLA=lA; /* armazena cebeça da lista A */
	Lista* auxLB=lB; /* armazena cebeça da lista B */
	Lista* auxB, *auxA;

	if(auxLA->info<=auxLB->info){

		while(auxLA->prox!=NULL && auxLB->prox!=NULL){

			while(auxLA->prox->info<=auxLB->info && auxLA!=NULL && auxLB!=NULL){

				auxLA = auxLA->prox;
			}

			auxA = auxLA->prox;
			lB = auxLB->prox;
			auxLB->prox = auxLA->prox;
			auxLA->prox = auxLB;

			auxLA = auxA;
			auxLB = lB;
		}

		return lA;
	}
	else{

		while(auxLA->prox!=NULL && auxLA->prox!=NULL){

			while(auxLB->prox->info<auxLA->info && auxLA->prox!=NULL && auxLB!=NULL){

				auxLB = auxLB->prox;
			}

			auxB = auxLB->prox;
			lA = auxLA->prox;
			auxLA->prox = auxLB->prox;
			auxLB->prox = auxLA;

			auxLB = auxB;
			auxLA = lA;
		}

		if(auxLA!=NULL){

			auxLB->prox = auxLA;
		}

		return lB;
	}	
}