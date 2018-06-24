#include "lista.h"
#include <stdlib.h>
#include <stdio.h>

struct lista{

	int coef;
	int expo;
	struct lista* prox;
};


Lista* criaPolinomio(){

	return NULL;
}


Lista* insereElementoNoPolinomio(Lista* pol, int c, int e){

	Lista* elemento = (Lista*) malloc(sizeof(Lista));
	Lista* aux;

	elemento->coef = c;
	elemento->expo = e;
	elemento->prox = NULL;

	if(pol == NULL){

		pol = elemento;
	}
	else{

		aux = pol;

		while(aux->prox != NULL){

			aux = aux->prox;
		}

		aux->prox = elemento;
	}

	return pol;
}


void imprimePolinomio(Lista* pol){

	Lista* p;

	for(p=pol; p!=NULL; p=p->prox){

		if(p->expo==0){

			printf("(%dx^%d)", p->coef, p->expo);
		}
		else{

			printf("(%dx^%d) + ", p->coef, p->expo);
		}
	}

}


Lista* somaPolinomios(Lista* polX, Lista* polY){

	Lista* polSoma;
	polSoma = criaPolinomio();

	Lista* pX;
	Lista* pY = polY;

	for(pX=polX; pX!=NULL; pX=pX->prox){

		if(pX->expo == pY->expo){
				polSoma = insereElementoNoPolinomio(polSoma, pX->coef+pY->coef, pX->expo);

				pY = pY->prox;
		}
		else{

				polSoma = insereElementoNoPolinomio(polSoma, pX->coef, pX->expo);
		}

	}

	return polSoma;
}

int ordemDosPolinomios(Lista* polX, Lista* polY){

	Lista* pX = polX;
	Lista* pY = polY;

	if(pX->expo > pY->expo){

		return 1;
	}
	else{

		return 0;
	}
}

void liberaPolinomio(Lista* pol){

	Lista* p=pol;

	while(p!=NULL){

		Lista* t = p->prox;

		free(p);

		p = t;
	}
}