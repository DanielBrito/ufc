#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cartasPilha.h"

#define n 50

struct carta{
	
	int id;
	char nomeCarta[n];
};

struct pilha{
	
	int topo;
	Carta* cartas[n];
};


void dados_carta(Carta* carta){
	
	printf("[Carta Recebida] - Nome: %s | Id: %d\n", carta->nomeCarta, carta->id);
}


Pilha* p_cria(){

	Pilha *p = (Pilha*)malloc(sizeof(Pilha));
	p->topo = 0;
	
	return p;
}

void p_push(Pilha *p, Carta* carta){	

	if(p->topo == n){

		printf("Erro! Pilha está cheia!\n");
		
		exit(1);
	}
	
	p->cartas[p->topo] = carta;
	p->topo++;
}

void p_pop(Pilha* p){

	if(p_vazia(p)){

		printf("Erro! Pilha está vazia!");
		
		exit(1);
	}

	p->topo--;
}

void imprime(Pilha *p){

	char k;

	Carta* card;

	Pilha* aux = p_cria();

	while(!p_vazia(p)){

		card = p_pop_aux(p);

		printf("Nome: %s Id: %d \n", card->nomeCarta,card->id);
		
		p_push(aux, card);

	}

	while(!p_vazia(aux)){

		card = p_pop_aux(aux);
		p_push(p,card);
	}
}



Carta* p_pop_aux(Pilha *p){

	if(p_vazia(p)){
		
		printf("Pilha vazia!");
		
		exit(1);
	}

	Carta* card = p->cartas[p->topo-1];

	p->topo--;

	return card;
}


int p_vazia(Pilha *p){
	
	if(p->topo == 0){
		
		return 1;
	}
	
	return 0;
}

void p_libera(Pilha *p){
	
	free(p);
}

void preencherCarta(Carta* *card, char *nome, int id){
	
	Carta* aux = *card;
	
	strcpy(aux->nomeCarta,nome); 
	aux->id = id;
}

Carta* cria_Carta(){
	
	Carta *p = (Carta*)malloc(sizeof(Carta));
	
	return p;
}
