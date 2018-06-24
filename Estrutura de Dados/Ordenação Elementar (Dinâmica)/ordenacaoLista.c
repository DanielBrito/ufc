#include <stdlib.h>
#include <stdio.h>
#include "ordenacaoLista.h"

/* TAD LISTA */

struct lista{
	
	int v;
	struct lista *prox;
	struct lista *ant;
};

Lista* criar(){

	return NULL;
}

Lista* inserir(Lista* l, int v){

	Lista* novo = (Lista*)malloc(sizeof(Lista));

	novo->v = v;
	novo->prox = l;

	return novo;
}

void liberar(Lista *l){

	Lista *aux = l;

	while(aux!=NULL){

		Lista *t = aux->prox;
		free(aux);
		aux = t;
	}
}

void imprimir(Lista *l){

	Lista *aux = l;

	if(aux==NULL){

		printf("Lista vazia!\n");
	}
	else{

		int i = 0;

		while(aux!=NULL){

			printf("%d° = [%d]\n", i, aux->v);
			aux = aux->prox;

			i++;
		}
	}
}

int testar(Lista* l){

	Lista* p = l;

	while(p!=NULL && p->prox!=NULL){

		if(p->v>p->prox->v){

			return 0;
		}

		p->v = p->prox->v;

		p = p->prox;
	}

	return 1;
}

int contaNos(Lista* l){

	Lista* aux;
	int cont=0;

	for(aux=l; aux!=NULL; aux=aux->prox){

		++cont;
	}

	return cont;
}

/* TAD ORDENACAO */

Lista* bubbleSort(Lista* l){

	int qtdNos = contaNos(l);
	int i;

	for(i=0; i<qtdNos; i++){

		Lista* atual = l;
		Lista* proxElem = atual->prox;
		Lista* antElem = NULL;

		while(proxElem!=NULL){

			if(atual->v>proxElem->v){

				if(atual==l){

					l = proxElem;
				}
				else{

					antElem->prox = proxElem;
				}

				atual->prox = proxElem->prox;
				proxElem->prox = atual;

				antElem = proxElem;
				proxElem = atual->prox;
			}
			else{

				antElem = atual;
				atual = atual->prox;
				proxElem = atual->prox;
			}
		}
	}

	return l;
}

Lista* insertionSort(Lista* l){

	return NULL;
}

Lista* selectionSort(Lista* l){

	return NULL;
}