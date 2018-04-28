#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

struct lista{

	char c;
	struct lista* prox;
};

Lista* listaCria(){

	return NULL;
}

Lista* listaInsereIni(Lista* l, char ch){

	Lista* nova = (Lista*)malloc(sizeof(Lista));
	nova->prox = l;
	nova->c = ch;

	return nova;
}

void listaLibera(Lista* l){

	while(l!=NULL){

		Lista* aux = l;
		l = l->prox;
		free(aux);
	}
}

Lista* listaRemovePrim(Lista* l){

	if(l==NULL){

		printf("Erro, lista vazia!\n");
		exit(1);
	}

	Lista* aux = l->prox;
	free(l);

	return aux;
}

int listaVazia(Lista* l){

	return l == NULL;
}

char listaPrimeiro(Lista* l){

	if(l==NULL){

		printf("Erro, lista vazia!\n");
		exit(1);
	}

	return l->c;
}

/*

char leTopo(Lista* l){  // FUNÇÃO desempilha DE "pilhaLista.c" ?

	if(l==NULL){

		printf("Erro, lista vazia!\n");
		exit(1);
	}

	return l->c;
}

*/