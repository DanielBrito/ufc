#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"
#include "lista.h"

struct pilha{

	struct lista* topo;
};

Pilha* inicializaPilha(){

	Pilha* p = (Pilha*)malloc(sizeof(Pilha));
	p->topo = listaCria();
	return p;
}

void empilha(Pilha* p, char ch){

	p->topo = listaInsereIni(p->topo, ch);
}

char desempilha(Pilha* p){

	if(listaVazia(p->topo)){

		printf("Erro, pilha vazia!\n");
		exit(1);
	}

	char ch;
	
	ch = listaPrimeiro(p->topo);
	p->topo = listaRemovePrim(p->topo);

	return ch;
}

int pilhaVazia(Pilha* p){

	return listaVazia(p->topo);
}

int pilhaCheia(Pilha* p){

	return 0;
}

void libera(Pilha* p){

	listaLibera(p->topo);
	free(p);
}

void imprimePilha(Pilha* p){

	Pilha* aux = inicializaPilha();
	char ch;

	while(!listaVazia(p->topo)){

		ch = desempilha(p);
		printf("%c\n", ch);
		empilha(aux, ch);
	}

	while(!listaVazia(aux->topo)){

		ch = desempilha(aux);
		empilha(p, ch);
	}

	libera(aux);

	printf("\n");
}

void imprimeReversa(Pilha* p){

	Pilha* aux = inicializaPilha();
	char ch;

	while(!listaVazia(p->topo)){

		ch = desempilha(p);
		empilha(aux, ch);
	}

	while(!listaVazia(aux->topo)){

		ch = desempilha(aux);
		printf("%c\n", ch);
		empilha(p, ch);
	}

	libera(aux);

	printf("\n");
}

int palindrome(Pilha* p){

	Pilha* c = inicializaPilha();
    Pilha* aux = inicializaPilha();

    char ch1, ch2;

    c = copiaPilhaL(p);
    c = invertePilhaL(c);

    while(!listaVazia(p->topo)){

    	ch1 = desempilha(p);
    	ch2 = desempilha(c);

    	empilha(aux, ch1);

    	if(ch1!=ch2){

    		while(!listaVazia(aux->topo)){

    			ch1 = desempilha(aux);
    			empilha(p, ch1);
    		}

    		return 0;
    	}

   	}

   	while(!listaVazia(aux->topo)){

   		ch1 = desempilha(aux);
   		empilha(p, ch1);
   	}

   	libera(aux);
   	libera(c);

   	return 1;
}

void elimina(Pilha* p, char ch){

    Pilha* aux = inicializaPilha();
    char c;

    while(!listaVazia(p->topo)){

        c = desempilha(p);

        if(c==ch){

            while(!listaVazia(aux->topo)){

                c = desempilha(aux);
                empilha(p, c);
            }
        }
        else{

            empilha(aux, c);
        }
    }

    while(!listaVazia(aux->topo)){

        c = desempilha(aux);
        empilha(p, c);
    }

    libera(aux);
}

void maiusculoMinusculo(Pilha* p){

    Pilha* maisculas = inicializaPilha();
    Pilha* minusculas = inicializaPilha();
    char ch;

    while(!listaVazia(p->topo)){

        ch = desempilha(p);

        if((int)ch>=97 && (int)ch<=122){

            empilha(minusculas, ch);
        }
        else{

            empilha(maisculas, ch);
        }
    }

    printf("LETRAS MINÚSCULAS:\n");
    imprimePilha(minusculas);

    printf("LETRAS MAIÚSCULAS:\n");
    imprimePilha(maisculas);

    libera(maisculas);
    libera(minusculas);
}

Pilha* invertePilhaL(Pilha* p){

    Pilha* c = inicializaPilha();
    Pilha* aux = inicializaPilha();

    char ch;

    while(!listaVazia(p->topo)){

        ch = desempilha(p);
        empilha(c, ch);
        empilha(aux, ch);
    }

    while(!listaVazia(aux->topo)){

        ch = desempilha(aux);
        empilha(p, ch);
    }

    libera(aux);

    return c;
}

Pilha* copiaPilhaL(Pilha* p){

    Pilha* c = inicializaPilha();
    Pilha* aux = inicializaPilha();
    char ch;

    while(!listaVazia(p->topo)){

        ch = desempilha(p);
        empilha(c, ch);
        empilha(aux, ch);
    }

    while(!listaVazia(aux->topo)){

        ch = desempilha(aux);
        empilha(p, ch);
    }

    libera(aux);

    c = invertePilhaL(c);

    return c;
}
