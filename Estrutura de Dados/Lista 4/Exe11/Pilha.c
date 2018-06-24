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

float* retornaValores(Pilha* p, float* vet, int n){

    int i=0;

    while(i<n){

        vet[i] = p_pop(p);

        i++;
    }

    return vet;
}

Pilha* inverte(Pilha* p){

	Pilha* c = p_cria();
	Pilha* aux = p_cria();

	float x;

	while(!p_vazia(p)){

		x = p_pop(p);
		p_push(c, x);
		p_push(aux, x);
	}

	while(!p_vazia(aux)){

		x = p_pop(aux);
		p_push(p, x);
	}

	p_libera(aux);

	return c;
}

Pilha* copia(Pilha* p){

	Pilha* c = p_cria();
    Pilha* aux = p_cria();
    float x;

	while(!p_vazia(p)){

        x = p_pop(p);
		p_push(c, x);
        p_push(aux, x);
	}

    while(!p_vazia(aux)){

		x = p_pop(aux);
		p_push(p, x);
	}

	c = inverte(c);
    p_libera(aux);

	return c;
}

int contaElementos(Pilha* p){

    Pilha* c = p_cria();
    c = copia(p);
    int cont=0;

    while(!p_vazia(c)){

        p_pop(c);
        ++cont;
    }

    return cont;
}
