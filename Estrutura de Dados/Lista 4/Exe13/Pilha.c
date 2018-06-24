#include<math.h>
#include<stdio.h>
#include<stdlib.h>
#include"Pilha.h"

#define N 60

struct pilha{

    int topo;
    int v[N];
};


Pilha* p_cria(void){

    Pilha *p;

    p = (Pilha*)malloc(sizeof(Pilha));
    p->topo = 0;

    return p;
}


void p_push(Pilha* p, int v){

    if(p->topo == N){

        printf("Erro! Pilha cheia!\n");
        exit(1);
    }

    p->v[p->topo] = v;
    p->topo++;
}


int p_pop(Pilha* p){

    int aux;

    if(p_vazia(p)){

        printf("Erro! Pilha vazia!\n");
        exit(1);
    }

    aux = p->v[p->topo-1];
    p->topo--;

    return aux;
}


int p_vazia(Pilha* p){

    return p->topo == 0;
}


void p_libera(Pilha* p){

    free(p);
}

void p_imprime(Pilha* p){

    while(!p_vazia(p)){

        printf("%d", p_pop(p));
    }

    printf("\n");
}