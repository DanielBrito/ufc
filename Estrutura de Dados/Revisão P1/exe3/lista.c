#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

struct lista{

	int info;
	struct lista* prox;
};

Lista* cria(){

	return NULL;
}

void libera(Lista* l){

	while(l!=NULL){

		Lista* aux = l;
		l = l->prox;

		free(aux);
	}
}

Lista* insere(Lista* l, int v){

	Lista* novo = (Lista*)malloc(sizeof(Lista));

	novo->info = v;
	novo->prox = l;

	return novo;
}

void imprime(Lista *l){

	Lista* aux = l;

	while(aux!=NULL){

		printf("[%3d] ", aux->info);
		aux = aux->prox;
	}	

	printf("\n");
}

Lista* retira(Lista* l, int v){

	Lista* ant = NULL;
	Lista* atual = l;

	while(atual->info!=v && atual->prox!=NULL){

		ant=atual;
		atual = atual->prox;
	}

	if(atual==NULL){

		return l;
	}
	else 
	if(ant==NULL){

		l = l->prox;
		free(atual);

		return l;
	}
	else{

		ant->prox = atual->prox;
		free(atual);

		return l;
	}
}

void imprimeNo(Lista* l){

	if(l!=NULL){

		printf("%d\n", l->info);
	}
	else{

		printf("Lista vazia\n");
	}
}

Lista* busca(Lista* l, int v){

	Lista* aux=l;

	while(aux!=NULL){

		if(aux->info==v){

			return aux;
		}

		aux = aux->prox;
	}

	return NULL;
}

Lista* insereOrdenado(Lista* l, int v){

	Lista* ant=NULL, *atual=l;

	while(atual!=NULL && atual->info<v){

		ant=atual;
		atual = atual->prox;
	}

	if(ant==NULL){

		return insere(l,v);

	}
	else{

		Lista* novo = (Lista*)malloc(sizeof(Lista));

		novo->info = v;
		ant->prox = novo;
		novo->prox = atual;

		return l;
	}
}

int vazia(Lista* l){

	return l==NULL;
}

Lista* insereFinal(Lista*l, int v){

	Lista*aux = l;
	Lista*ant = NULL;

	while(aux!=NULL){

		ant = aux;
		aux = aux->prox;
	}

	if(ant==NULL){

		return insere(l,v);
	}

	Lista *novo = (Lista*)malloc(sizeof(Lista));

	novo->info = v;
	ant->prox = novo;
	novo->prox = aux;

	return l;
}

Lista* multiplicaParesInterativo(Lista* l){

	Lista* auxL = l;
	Lista* aux;
	Lista* lResult = cria();
	int produto;

	if(l==NULL){

		return l;
	}

	while(auxL!=NULL){

		if(auxL->info%2==0){

			aux = auxL->prox;

			produto = auxL->info;

			while(aux!=NULL){

				if(aux->info%2==0){

					produto *= aux->info;
				}

				aux = aux->prox;
			}

			lResult = insereFinal(lResult, produto);
		}
		else{

			aux = auxL;
			produto = 0;

			while(aux!=NULL){

				if(aux->info%2==0){

					produto = 1;

					break;
				}

				aux = aux->prox;
			}

			if(produto==0){

				aux = auxL;

				while(aux!=NULL){

					lResult = insereFinal(lResult, produto);

					aux = aux->prox;
				}

				return lResult;
			}
			else{

				aux = auxL;

				while(aux!=NULL){

					if(aux->info%2==0){

						produto *= aux->info;
					}

					aux = aux->prox;
				}

				if(auxL->prox==NULL){

					lResult = insereFinal(lResult, 0);
				}
				else{

					lResult = insereFinal(lResult, produto);
				}
			}
		}

		auxL = auxL->prox;
	}

	return lResult;
}

Lista* multiplicaParesRecursivo(Lista* l){

	return NULL;
}