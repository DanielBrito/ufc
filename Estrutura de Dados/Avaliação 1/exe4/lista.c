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


// AVALIAÇÃO - QUESTÃO 4:

/* 

Considerando o tipo Lista definido na primeira questão, implemente uma função que receba 
um vetor de valores inteiros com n elementos e construa uma lista encadeada armazenando 
os elementos do vetor nas células da lista. Aassim, se for recebido o vetor armazenando 
os elementos do vetor nas células da lista. Assim,, se for recebido um vetor 
v[5] = {7, 5, 3, 13, 11}, a função deve retornar uma lista cuja primeira célula tem a 
informação 7, a segunda a informação 5, e assim por diante. Se o vetor tiver zero 
elementos, a função deve ter como valor de retorno uma lista vazia. O protótipo da 
função é dado por Lista* constroi(int* v, int n).

*/


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