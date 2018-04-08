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

void libera(Lista* l){

	Lista* p=l;

	while(p!=NULL){

		Lista* t = p->prox;

		free(p);

		p = t;
	}
}

Lista* insere(Lista* l, int i){

	Lista* novo = (Lista*) malloc(sizeof(Lista));
	novo->info = i;
	novo->prox = l;
	return novo;
}

Lista* insereFinal(Lista* l, int i){

	Lista* ant = NULL;
	Lista* aux = l;

	while(aux!=NULL){

		ant = aux;
		aux = aux->prox;
	}

	Lista* novo = (Lista*) malloc(sizeof(Lista));
	novo->info = i;

	if(ant==NULL){

		novo->prox = l;
		l = novo;
	}
	else{

		novo->prox = ant->prox;
		ant->prox = novo;
	}

	return l;
}

Lista* insereFinalRec(Lista* l, int i){

	Lista* aux = l;

	if(aux==NULL){

		Lista* novo = (Lista*)malloc(sizeof(Lista));

		novo->info = i;
		novo->prox = aux;

		return novo;
	}

	aux->prox = insereFinalRec(aux->prox, i);
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

int vazia(Lista* l){

	return (l==NULL);
}

Lista* busca(Lista* l, int v){

	Lista* p;

	for(p=l; p!=NULL; p=p->prox){

		if(p->info == v){

			return p;
		}
	}

	return NULL;
}


void imprime(Lista* l){

	Lista* p;

	for(p=l; p!=NULL; p=p->prox){

		printf("%d  ", p->info);
	}
}

void imprimeNo(Lista* l){

	if(l!=NULL){

		printf("%d", l->info);
	}
	else{

		printf("Lista vazia");
	}
}

Lista* somaListas(Lista* l1, Lista* l2){

	Lista* l3, *auxL1, *auxL2;

	l3 = cria();

	for(auxL1=l1, auxL2=l2; auxL1!=NULL; auxL1=auxL1->prox, auxL2=auxL2->prox){
		
		l3 = insereFinal(l3, auxL1->info + auxL2->info);
	}

	return l3;
}

int somaPrimos(Lista* l){

	Lista* aux = l;

	if(aux==NULL){

		return 0;
	}

	if(testaPrimo(aux->info)){

		return aux->info + somaPrimos(aux->prox);
	}

	return somaPrimos(aux->prox);
}


Lista* removeKEsimaCelula(Lista* l, int v){

	Lista* p;
	Lista* q;

	p = l;

	int i;

	if(v==1){

		l = p->prox;

		free(p);

		return l;
	}

	for(i=0; i<v-2; i++){

		p = p->prox;
	}

	q = p->prox;
	p->prox = q->prox;

	free(q);

	return l;
}

/* FUNÇÕES AUXILIARES */

int testaPrimo(int n){

	int i, cont=0;

	if(n<1){

		return 0;
	}

	for(i=1; i<=n; i++){

		if(n%i==0){

			++cont;

			if(cont>2){

				return 0;
			}
		}
	}

	return 1;
}

/* CORREÇÃO */

Lista* retiraK(Lista* l, int k){

	Lista* ant=NULL;
	Lista* p=l;
	int cont=0;

	while(cont<k-1 && p->prox!=NULL){

		ant = p;
		p = p->prox;

		cont++;
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

/* CORREÇÃO */

Lista* intercala(Lista* l1, Lista* l2){

	if(l1 == NULL){

		return l2;
	}

	if(l2 == NULL){

		return l1;
	}

	l1->prox = intercala(l2, l1->prox);

	return l1;

}