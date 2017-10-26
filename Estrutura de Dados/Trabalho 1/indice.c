#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"lista.h"
#include"indice.h"


struct indice{

	int pagina;
	struct indice* proxPagina;
};


/* Observação: A "struct nome" era para estar no arquivo "lista.c", mas, por algum 
   motivo, ela não estava sendo reconhecida pelas funções de "indice.c". */

struct nome{

	char texto[100];
	struct indice* id;
	struct nome* proxNome;
};


Indice* criarListaIndice(void){

	return NULL;
}


Indice* inserirIndice(Indice* ind, int pg){

	Indice* novo;
	Indice* ant = NULL;
	Indice* aux = ind;

	while(aux!=NULL && aux->pagina<pg){

		ant = aux;
		aux = aux->proxPagina;
	}

	novo = (Indice*)malloc(sizeof(Indice));
	novo->pagina = pg;

	if(ant==NULL){

		novo->proxPagina = ind;
		ind = novo;
	}
	else{

		novo->proxPagina = ant->proxPagina;
		ant->proxPagina = novo;
	}

	return ind;
}


Indice* remover(Indice* ind, int pg){

	Indice* ant=NULL;
	Indice* p=ind;

	while(p!=NULL && p->pagina!=pg){

		ant = p;
		p = p->proxPagina;
	}

	if(p==NULL){

		return ind;
	}

	if(ant==NULL){

		ind = p->proxPagina;
	}
	else{

		ant->proxPagina = p->proxPagina;
	}

	free(p);

	return ind;
}


Indice* removerPaginasRepetidas(Indice* ind){

	Indice* p;
	Indice* q;

	for(p=ind; p!=NULL; p=p->proxPagina){

		q = p->proxPagina;

		while(q!=NULL){

			if(p->pagina == q->pagina){

				ind = remover(ind, q->pagina);
			}

			q = q->proxPagina;
		}
	}

	return ind;
}


Indice* verificarIntersecao(Indice* indLista, Indice* indBuscado, int qtdT){

	Indice* indL;
	Indice* indB;
	Indice* pgsResultado;

	pgsResultado = criarListaIndice();

	int contIgual;

	for(indB=indBuscado; indB!=NULL; indB=indB->proxPagina){

		contIgual = 0;

		for(indL=indLista; indL!=NULL; indL=indL->proxPagina){

			if(indB->pagina==indL->pagina){

				++contIgual;

				if(contIgual==qtdT){

					pgsResultado = inserirIndice(pgsResultado, indB->pagina);
				}
			}
		}
	}

	return pgsResultado;
}


void imprimirListaIndice(Indice* ind){

	Indice* aux = ind;

	for(aux=ind; aux!=NULL; aux=aux->proxPagina){

		printf("[%d] ", aux->pagina);
	}

	printf("\n");
}


Indice* listarIndiceNomeBuscado(Nome* n, Nome* nBuscado){

	Indice* pgsNomeBuscado;
	pgsNomeBuscado = criarListaIndice();

	Nome* nB;
	Nome* nL;
	Indice* nL_Aux;

	for(nB=nBuscado; nB!=NULL; nB=nB->proxNome){

		for(nL=n; nL!=NULL; nL=nL->proxNome){

			if(strcmp(nB->texto, nL->texto)==0){

				nL_Aux = nL->id;

				for(nL_Aux; nL_Aux!=NULL; nL_Aux=nL_Aux->proxPagina){

					pgsNomeBuscado = inserirIndice(pgsNomeBuscado, nL_Aux->pagina);
				}				
			}
		}
	}

	return pgsNomeBuscado;
}


Indice* buscarNome(Nome* n, char* str, Nome* nBuscado, int qtdT){

	Indice* listaIndiceNomeBuscado;
	Indice* listaIndiceSemRepetidos;
	Indice* resultado;

	listaIndiceNomeBuscado = listarIndiceNomeBuscado(n, nBuscado);

	listaIndiceSemRepetidos = removerPaginasRepetidas(listaIndiceNomeBuscado);

	listaIndiceNomeBuscado = listarIndiceNomeBuscado(n, nBuscado);

	resultado = verificarIntersecao(listaIndiceNomeBuscado, listaIndiceSemRepetidos, qtdT);

	return resultado;
}


/*

// FUNÇÕES DE TESTE:

void imprimirListaIndiceDeNome(Nome* n){

	Nome* aux = n;

	for(aux->id; aux->id!=NULL; aux->id=aux->id->proxPagina){

		printf("%s: %d\n", aux->texto, aux->id->pagina);
	}
}

*/