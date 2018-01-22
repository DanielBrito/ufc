#include<math.h>
#include<stdio.h>
#include<stdlib.h>
#include"Pilha.h"

struct lista{
	
	float info;
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


void p_push(Pilha* p, float v){

	Lista* n = (Lista*)malloc(sizeof(Lista));
	n->info = v;
	n->prox = p->prim;
	p->prim = n;
}


float p_pop(Pilha* p){

	Lista *t;
	float v;

	if(p_vazia(p)){

		printf("Pilha vazia.\n");
		exit(1);
	}

	t = p->prim;
	v = t->info;
	p->prim = t->prox;

	free(t);

	return v;
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

		printf("%.2f\n", q->info);
	}
}