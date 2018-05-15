#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

struct lista{
	
	char info;
	struct lista* prox;
};

typedef struct lista Lista;

struct pilha{

	Lista* prim;
};


Pilha* p_cria(void){

	Pilha* p = (Pilha*)malloc(sizeof(Pilha));
	p->prim = NULL;

	return p;
}


void p_push(Pilha* p, char ch){

	Lista* n = (Lista*)malloc(sizeof(Lista));
	n->info = ch;
	n->prox = p->prim;
	p->prim = n;
}


char p_pop(Pilha* p){

	Lista *t;
	char ch;

	if(p_vazia(p)){

		printf("Pilha vazia.\n");
		exit(1);
	}

	t = p->prim;
	ch = t->info;
	p->prim = t->prox;

	free(t);

	return ch;
}


int p_vazia(Pilha* p){

	return (p->prim==NULL);
}


void p_libera(Pilha* p){

	Lista* q = p->prim;

	while(q!=NULL){

		Lista* t = q->prox;

		free(q);

		q = t;
	}

	free(p);
}


void p_imprime(Pilha* p){

	Lista *q;

	for(q=p->prim; q!=NULL; q=q->prox){

		printf("%c \n", q->info);
	}
}