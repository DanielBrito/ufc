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

		printf("%2d  ", p->info);
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

// QUESTÃO 16 - a:

Lista* uniaoDeConjuntos(Lista* lA, Lista* lB){

	Lista* uniao = cria();
	Lista* auxA, *auxB;
	int igual=0;

	for(auxA=lA; auxA!=NULL; auxA=auxA->prox){

		uniao = insereOrdenado(uniao, auxA->info);
	}

	for(auxB=lB; auxB!=NULL; auxB=auxB->prox){

		igual = 0;

		for(auxA=lA; auxA!=NULL; auxA=auxA->prox){

			if(auxB->info==auxA->info){

				++igual;
			}
		}

		if(igual==0){

			uniao = insereOrdenado(uniao, auxB->info);
		}
	}

	return uniao;
}

Lista* intersecaoDeConjuntos(Lista* lA, Lista* lB){

	Lista* inter = cria();
	Lista* p;
	Lista* q = lB;

	for(p=lA; p!=NULL; p=p->prox){
		
		q = lB;

		while(q->prox!=NULL){

			if(p->info==q->info){

				inter = insereOrdenado(inter, p->info);
			}

			q = q->prox;
		}
	}

	return inter;
}


// QUESTÃO 16 - c:

Lista* diferencaEntreConjuntos(Lista* lA, Lista* lB){

	Lista* dif = cria();
	Lista* p, *q;
	int igual;

	for(p=lA; p!=NULL; p=p->prox){

		igual = 0;

		for(q=lB; q!=NULL; q=q->prox){

			if(p->info==q->info){

				++igual;
			}
		}

		if(igual==0){

			dif = insereOrdenado(dif, p->info);
		}
	}

	return dif;
}


// QUESTÃO 16 - d:

int pertinencia(Lista* l, int v){

	Lista* p;

	for(p=l; p!=NULL; p=p->prox){

		if(p->info==v){

			return 1;
		}
	}

	return 0;
}
