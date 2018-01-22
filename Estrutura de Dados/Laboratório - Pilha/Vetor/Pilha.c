#include<math.h>
#include<stdio.h>
#include<stdlib.h>
#include"Pilha.h"

#define N 60

struct pilha{

    int topo;
    float v[N];
};


Pilha* p_cria(void){

    Pilha *p;

    p = (Pilha*)malloc(sizeof(Pilha));
    p->topo = 0;

    return p;
}


void p_push(Pilha* p, float v){

    if(p->topo == N){

        printf("Erro! Pilha cheia!\n");
        exit(1);
    }

    p->v[p->topo] = v;
    p->topo++;
}


float p_pop(Pilha* p){

    float aux;

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
