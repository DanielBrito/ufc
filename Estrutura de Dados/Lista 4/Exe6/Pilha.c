#include <stdio.h>
#include <stdlib.h>
#include "Pilha.h"

#define N 60

struct pilha{

    int topo;
    char v[N];
};


Pilha* p_cria(void){

    Pilha *p;

    p = (Pilha*)malloc(sizeof(Pilha));
    p->topo = 0;

    return p;
}


void p_push(Pilha* p, char c){

    if(p->topo == N){

        printf("Erro! Pilha cheia!\n");
        exit(1);
    }

    p->v[p->topo] = c;
    p->topo++;
}


char p_pop(Pilha* p){

    char c;

    if(p_vazia(p)){

        printf("Erro! Pilha vazia!\n");
        exit(1);
    }

    c = p->v[p->topo-1];
    p->topo--;

    return c;
}


int p_vazia(Pilha* p){

    return p->topo == 0;
}


void p_libera(Pilha* p){

    free(p);
}

Pilha* copia(Pilha* p){

	Pilha* c = p_cria();
    Pilha* aux = p_cria();
    char ch;

	while(!p_vazia(p)){

        ch = p_pop(p);
		p_push(c, ch);
        p_push(aux, ch);
	}

    while(!p_vazia(aux)){

		ch = p_pop(aux);
		p_push(p, ch);
	}

	c = inverte(c);
    p_libera(aux);

	return c;
}

Pilha* inverte(Pilha* p){

	Pilha* c = p_cria();
	Pilha* aux = p_cria();

	char ch;

	while(!p_vazia(p)){

		ch = p_pop(p);
		p_push(c, ch);
		p_push(aux, ch);
	}

	while(!p_vazia(aux)){

		ch = p_pop(aux);
		p_push(p, ch);
	}

	p_libera(aux);

	return p;
}

void p_imprime(Pilha* p){

    Pilha* inv = p_cria();
    inv = inverte(p);

    while(!p_vazia(inv)){

        printf("%c\n", p_pop(inv));
    }
}