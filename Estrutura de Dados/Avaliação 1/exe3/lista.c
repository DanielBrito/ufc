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


// AVALIAÇÃO - QUESTÃO 3:

/* 

Considerando o tipo Lista definido na primeira questão, implemente uma função que receba 
como parâmetro uma lista encadeada e um valor inteiro v e divida a lista em duas, de tal 
forma que a segunda lista comece da primeira célula logo após a primeira ocorrência de v 
na lista original.

Essa função deve obedecer ao protótipo: Lista* separa(Lista*l, int v);

A função deve retornar um ponteiro para a segunda sub-divisão da lista original, enquanto 
l devev continuar apontando para o primeiro elemento da sub-divisão da lista.

*/


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