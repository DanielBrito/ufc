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

		printf("%d \t", aux->info);
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

Lista* listaImpares(Lista*l, Lista** par){

	Lista* imp, *imp_aux=NULL, *par_aux=NULL;

	if(l!=NULL && l->info%2==0){

		par_aux = l;
		*par = l;
		l = l->prox;

		while(l!=NULL && l->info%2 == 0){

			par_aux->prox = l;
			par_aux = par_aux->prox;
			l = l->prox;
		}

		imp = l;
		imp_aux = l;
	}
	else 
	if(l!=NULL && l->info%2==1){

		imp_aux = l;
		imp = l;
		l = l->prox;

		while(l!=NULL && l->info%2 == 1){

			imp_aux->prox = l;
			imp_aux = imp_aux->prox;
			l = l->prox;
		}

		*par = l;
		par_aux = l;
	}

	if(l!=NULL){

		l = l->prox;
	}
			
	while(l!=NULL){

		if(l->info%2==0){

			par_aux->prox = l;
			par_aux = par_aux->prox;

		}
		else{

			imp_aux->prox = l;
			imp_aux = imp_aux->prox;
		}

		l = l->prox;
	}

	if(imp_aux!=NULL){

		imp_aux->prox = NULL;
	}

	if(par_aux!=NULL){

		par_aux->prox = NULL;
	}

	return imp;
}

