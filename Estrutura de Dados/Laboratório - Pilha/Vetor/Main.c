#include<math.h>
#include<stdio.h>
#include<stdlib.h>
#include"Pilha.h"

/* 1 - Função para comparar duas pilhas. Se forem iguais, retorna 1, caso contrário, retorna 0: */
int compara(Pilha* p1, Pilha* p2);

/* 2 - Função para criar uma cópia de uma pilha passada por parâmentro: */
Pilha* copia(Pilha* p);

/* Função auxiliar para inverter uma pilha: */
Pilha* inverte(Pilha* p);

int main(){

    Pilha* p1;
    Pilha* p2;
    Pilha* p3;
    Pilha* pC;
   	int i;
   	float x;

    p1 = p_cria();
    p2 = p_cria();
    p3 = p_cria();
    pC = p_cria();

    for(i=1; i<=5; i++){
        
        p_push(p1, i);
    }

    for(i=1; i<=6; i++){
        
        p_push(p2, i);
    }

    printf("Teste 1: ");

    if(compara(p1, p2)==1){

    	printf("Pilhas iguais.\n");
    }
    else{

    	printf("Pilhas diferentes.\n");
    }

    p1 = p_cria();
    p2 = p_cria();

    x=1;

    for(i=0; i<5; i++){
        
        p_push(p1, x);
        ++x;
    }

    x=1;

    for(i=0; i<9; i++){
        
        p_push(p2, x);
        ++x;
    }

    printf("\nTeste 2: ");

    if(compara(p1, p2)==1){

    	printf("Pilhas iguais.\n");
    }
    else{

    	printf("Pilhas diferentes.\n");
    }

    for(i=9; i>=0; i--){
        
        p_push(p3, i);
    }

    pC = copia(p3);

    printf("\nCópia da Pilha 3:\n\n");

    while(!p_vazia(pC)){

    	printf("%.2f\n", p_pop(pC));
    }

    p_libera(p1);
    p_libera(p2);
    p_libera(p3);
    p_libera(pC);

    return 0;
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
