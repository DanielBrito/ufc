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

int compara(Pilha* p1, Pilha* p2){

	float aux1, aux2;
	int diferentes = 0;

	Pilha* auxP1 = p_cria();
	Pilha* auxP2 = p_cria();

	while(!p_vazia(p1) && !p_vazia(p2)){

		aux1 = p_pop(p1); 
		aux2 = p_pop(p2);

		if(aux1!=aux2){

			diferentes = 1;
		}

		p_push(auxP1, aux1);
		p_push(auxP2, aux2);
    }

    auxP1 = inverte(auxP1);
	auxP2 = inverte(auxP2);

	while(!p_vazia(auxP1) && !p_vazia(auxP2)){

		aux1 = p_pop(auxP1);
		aux2 = p_pop(auxP2);

		p_push(p1, aux1);
		p_push(p2, aux2);
	}

    if(diferentes==1){

        p_libera(auxP1);
        p_libera(auxP2);

    	return 0;
    }

    if((p_vazia(p1) && !p_vazia(p2)) || (!p_vazia(p1) && p_vazia(p2))){

        p_libera(auxP1);
        p_libera(auxP2);

        return 0;
    }

    p_libera(auxP1);
    p_libera(auxP2);

    return 1;
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