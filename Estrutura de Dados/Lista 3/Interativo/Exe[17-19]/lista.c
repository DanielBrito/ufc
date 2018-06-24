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

int verificaPrimo(int num){
	
	int i;

	if(num==1){

		return 0;
	}

	for(i=2; i<num; i++){

		if(num%i==0){

			return 0;
		}
	}

	return 1;
}

// QUESTÃO 17:

Lista* removeNulos(Lista* l){

	Lista* p;

	for(p=l; p!=NULL; p=p->prox){

		if(p->info==0){

			l = retira(l, p->info);
		}
	}

	return l;
}

// QUESTÃO 18:

int igualdade(Lista* lA, Lista* lB){

	Lista* auxA, *auxB=lB, *aux=auxB;

	for(auxA=lA; auxA!=NULL; auxA=auxA->prox){

		if(conta(lA, auxA->info)!=conta(lB, auxA->info)){

			return 0;
		}

		aux = aux->prox;
	}

	if(aux!=NULL){

		return 0;
	}

	return 1;
}

int conta(Lista* l, int v){

	Lista* p;
	int cont=0;

	for(p=l; p!=NULL; p=p->prox){

		if(p->info==v){

			++cont;
		}
	}

	return cont;
}

// QUESTÃO 19:

Lista* encontraPrimos(Lista* l){

	Lista* primos = cria();
	Lista* p;

	for(p=l; p!=NULL; p=p->prox){

		if(verificaPrimo(p->info)){

			primos = insereOrdenado(primos, p->info);
		}
	}

	return primos;
}