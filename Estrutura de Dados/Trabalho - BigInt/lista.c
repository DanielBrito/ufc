#include <stdio.h>
#include <stdlib.h>
#include "lista.h"
#include "operacoes.h"

struct no{

	char dig;
	struct no* prox;
	struct no* ant;
};

struct lista{

	No* ini;
	No* fim;
	No* no;
};

Lista* cria(){

	return NULL;
}

Lista* insereInicio(Lista* l, char ch){

	if(l==NULL){

		Lista* novo = (Lista*)malloc(sizeof(Lista));
		l = novo;
	}

	No* novoNo = (No*)malloc(sizeof(No));

	novoNo->dig = ch;
	novoNo->prox = l->no;
	novoNo->ant = NULL;

	if(l->no!=NULL){

		l->no->ant = novoNo;
		l->ini = novoNo;
	}
	else{

		l->ini = novoNo;
		l->fim = novoNo;
	}

	l->no = novoNo;

	return l;
}

Lista* insereFinal(Lista* l, char v){

	if(l==NULL){

		Lista* novo = (Lista*)malloc(sizeof(Lista));
		l = novo;
		l->no = NULL;
	}

	No* novoNo = (No*)malloc(sizeof(No));

	novoNo->dig = v;
	novoNo->prox = NULL;

	if(l->no!=NULL){

		novoNo->ant = l->fim;
		l->fim->prox = novoNo;
		l->fim = novoNo;
	}
	else{

		novoNo->ant = NULL;
		l->fim = novoNo;
		l->ini = novoNo;
		l->no = novoNo;
	}

	return l;
}

void imprime(Lista* l){

	No* aux;

	if(l==NULL){

		return;
	}

	for(aux=l->no; aux!=NULL; aux=aux->prox){

		printf("%c", aux->dig);
	}
}

void libera(Lista* l){

	No* aux = l->no;

	while(aux!=NULL){

		No* t = aux->prox;
		free(aux);
		aux = t;
	}

}

int acessaDigito(No* no){

	return converteInt(no->dig);
}

No* acessaProx(No* no){

	return no->prox;
}

No* acessaAnt(No* no){

	return no->ant;
}

No* acessaNo(Lista* l){

	return l->no;
}

No* acessaIni(Lista* l){

	return l->ini;
}

No* acessaFim(Lista* l){

	return l->fim;
}

Lista* removeZeroInicio(Lista *l){

	No* auxL = l->no;
	No* aux;

	while(auxL != NULL && auxL->dig == '0'){

		aux = auxL;
		auxL = auxL->prox;
		free(aux);

		if(auxL != NULL){

			auxL->ant = NULL;
		}
	}

	if(auxL == NULL){

		Lista *zero = cria();
		zero = insereFinal(zero, '0');

		return zero;
	}
	else{

		l->no = auxL;
	}

	return l;
}

int contaDigitos(Lista *l){

	No *aux = l->no;
	int cont = 0;

	for(aux ; aux != NULL; aux = aux->prox){
		
		cont++;
	}

	return cont;
}

int converteInt(char ch){

    if(ch == '0') return 0;
    if(ch == '1') return 1; 
    if(ch == '2') return 2; 
    if(ch == '3') return 3; 
    if(ch == '4') return 4; 
    if(ch == '5') return 5; 
    if(ch == '6') return 6; 
    if(ch == '7') return 7; 
    if(ch == '8') return 8; 
    if(ch == '9') return 9; 
}

char converteChar(int v){

    if(v == 0) return '0'; 
    if(v == 1) return '1'; 
    if(v == 2) return '2'; 
    if(v == 3) return '3'; 
    if(v == 4) return '4'; 
    if(v == 5) return '5'; 
    if(v == 6) return '6'; 
    if(v == 7) return '7'; 
    if(v == 8) return '8'; 
    if(v == 9) return '9'; 
}

Lista* alteraNo(Lista *l, Lista *novo){

	l->no = novo->no;

	return l;
}