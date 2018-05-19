#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

#define N 50
#define MAX 80

struct pilha{

    int topo1;
    int topo2;
    int v[N];
};

Pilha* inicializaPilhas(){

    Pilha* p = (Pilha*)malloc(sizeof(Pilha));
    p->topo1 = 0;
    p->topo2 = MAX-1;

    return p;
}

void empilhaP1(Pilha* p, int n){

    if(pilha1Cheia(p)){ 

        printf("Erro! Pilha 1 cheia!\n");
        exit(1);
    }

    p->v[p->topo1] = n;
    p->topo1++;
}

void empilhaP2(Pilha* p, int n){

    if(pilha2Cheia(p)){ 

        printf("Erro! Pilha 2 cheia!\n");
        exit(1);
    }

    p->v[p->topo2] = n;
    p->topo2--;
}


int desempilhaP1(Pilha* p){

    int n;

    if(pilha1Vazia(p)){

        printf("Erro! Pilha vazia!\n");
        exit(1);
    }

    n = p->v[p->topo1-1];
    p->topo1--;

    return n;
}

int desempilhaP2(Pilha* p){

    int n;

    if(pilha2Vazia(p)){

        printf("Erro! Pilha vazia!\n");
        exit(1);
    }

    n = p->v[p->topo2+1];
    p->topo2++;

    return n;
}


int pilha1Vazia(Pilha* p){

    return p->topo1 == 0;
}

int pilha2Vazia(Pilha* p){

    return p->topo2 == MAX-1;
}

int pilha1Cheia(Pilha* p){

	if(p->topo1 == p->topo2 || p->topo1 == 50){ /* Máximo = 50 elementos [0..49] */

        return 1;
    }

    return 0;
}

int pilha2Cheia(Pilha* p){

    if(p->topo1-1 == p->topo2 || p->topo2 == (MAX-1)-N){ /* Máximo = 50 elementos [MAX-1..29] */

        return 1;
    }

    return 0;
}

void libera(Pilha* p){

    free(p);
}