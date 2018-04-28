#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

#define N 60

struct pilha{

    int topo;
    char v[N];
};


Pilha* inicializaPilha(){

    Pilha *p;

    p = (Pilha*)malloc(sizeof(Pilha));
    p->topo = 0;

    return p;
}


void empilha(Pilha* p, char ch){

    if(p->topo == N){

        printf("Erro! Pilha cheia!\n");
        exit(1);
    }

    p->v[p->topo] = ch;
    p->topo++;
}


char desempilha(Pilha* p){

    char ch;

    if(pilhaVazia(p)){

        printf("Erro! Pilha vazia!\n");
        exit(1);
    }

    ch = p->v[p->topo-1];
    p->topo--;

    return ch;
}


int pilhaVazia(Pilha* p){

    return p->topo == 0;
}

int pilhaCheia(Pilha* p){

	if(p->topo==N){

		return 1;
	}

	return 0;
}

void libera(Pilha* p){

    free(p);
}

void imprimePilha(Pilha* p){

    Pilha* aux;
    aux = inicializaPilha();
    char ch;

    while(!pilhaVazia(p)){

        ch = desempilha(p);
        empilha(aux, ch);
        printf("%c\n", ch);
    }

    while(!pilhaVazia(aux)){

        empilha(p, desempilha(aux));
    }

    libera(aux);

    printf("\n");
}

void imprimeReversa(Pilha* p){

    Pilha* aux;
    aux = inicializaPilha();
    char ch;

    if(pilhaVazia(p)){

        printf("Erro! Pilha vazia!\n");
        exit(1);
    }

    while(!pilhaVazia(p)){

        ch = desempilha(p);
        empilha(aux, ch);
    }

    while(!pilhaVazia(aux)){

        ch = desempilha(aux);
        printf("%c\n", ch);
        empilha(p, ch);
    }

    libera(aux);

    printf("\n");
}

Pilha* invertePilhaV(Pilha* p){

    Pilha* c = inicializaPilha();
    Pilha* aux = inicializaPilha();

    char ch;

    while(!pilhaVazia(p)){

        ch = desempilha(p);
        empilha(c, ch);
        empilha(aux, ch);
    }

    while(!pilhaVazia(aux)){

        ch = desempilha(aux);
        empilha(p, ch);
    }

    libera(aux);

    return c;
}

Pilha* copiaPilhaV(Pilha* p){

    Pilha* c = inicializaPilha();
    Pilha* aux = inicializaPilha();
    char ch;

    while(!pilhaVazia(p)){

        ch = desempilha(p);
        empilha(c, ch);
        empilha(aux, ch);
    }

    while(!pilhaVazia(aux)){

        ch = desempilha(aux);
        empilha(p, ch);
    }

    libera(aux);

    c = invertePilhaV(c);

    return c;
}

int palindrome(Pilha* p){

    if(p->topo == 1){

        return 1;
    }

    Pilha* c = inicializaPilha();
    Pilha* aux = inicializaPilha();

    char ch1, ch2;

    c = copiaPilhaV(p);
    c = invertePilhaV(c);

    while(!pilhaVazia(p)){

        ch1 = desempilha(p);
        ch2 = desempilha(c);

        empilha(aux, ch1);

        if(ch1!=ch2){

            while(!pilhaVazia(aux)){

                ch1 = desempilha(aux);
                empilha(p, ch1);
            }

            return 0;
        }
    }

    while(!pilhaVazia(aux)){

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

    while(!pilhaVazia(p)){

        c = desempilha(p);

        if(c==ch){

            while(!pilhaVazia(aux)){

                c = desempilha(aux);
                empilha(p, c);
            }
        }
        else{

            empilha(aux, c);
        }
    }

    while(!pilhaVazia(aux)){

        c = desempilha(aux);
        empilha(p, c);
    }

    libera(aux);
}

void maiusculoMinusculo(Pilha* p){

    Pilha* maisculas = inicializaPilha();
    Pilha* minusculas = inicializaPilha();
    char ch;

    while(!pilhaVazia(p)){

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

    libera(minusculas);
    libera(maisculas);
}