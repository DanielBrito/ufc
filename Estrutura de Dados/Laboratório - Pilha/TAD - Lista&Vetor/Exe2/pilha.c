#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

#define N 50
#define MAX 80

struct pilha{

    int topo;
    int v[N];
};


Pilha* inicializaPilha1(){

    Pilha* p;

    p = (Pilha*)malloc(sizeof(Pilha));
    p->topo = 0;

    return p;
}

Pilha* inicializaPilha2(){

    Pilha* p;

    p = (Pilha*)malloc(sizeof(Pilha));
    p->topo = MAX-1;

    return p;
}


void empilhaP1(Pilha* p1, Pilha* p2, int n){

    if(pilha1Cheia(p1, p2)){ 

        printf("Erro! Pilha 1 cheia!\n");
        exit(1);
    }

    p1->v[p1->topo] = n;
    p1->topo++;
}

void empilhaP2(Pilha* p1, Pilha* p2, int n){

    if(pilha2Cheia(p1, p2)){ 

        printf("Erro! Pilha 2 cheia!\n");
        exit(1);
    }

    p2->v[p2->topo] = n;
    p2->topo--;
}


int desempilhaP1(Pilha* p){

    int n;

    if(pilha1Vazia(p)){

        printf("Erro! Pilha vazia!\n");
        exit(1);
    }

    n = p->v[p->topo-1];
    p->topo--;

    return n;
}

int desempilhaP2(Pilha* p){

    int n;

    if(pilha2Vazia(p)){

        printf("Erro! Pilha vazia!\n");
        exit(1);
    }

    n = p->v[p->topo+1];
    p->topo++;

    return n;
}


int pilha1Vazia(Pilha* p){

    return p->topo == 0;
}

int pilha2Vazia(Pilha* p){

    return p->topo == MAX-1;
}

int pilha1Cheia(Pilha* p1, Pilha* p2){

	if(p1->topo == p2->topo || p1->topo == 50){ /* Máximo = 50 elementos [0..49] */

        return 1;
    }

    return 0;
}

int pilha2Cheia(Pilha* p1, Pilha* p2){

    if(p1->topo-1 == p2->topo || p2->topo == (MAX-1)-N){ /* Máximo = 50 elementos [MAX-1..29] */

        return 1;
    }

    return 0;
}

void libera(Pilha* p){

    free(p);
}
