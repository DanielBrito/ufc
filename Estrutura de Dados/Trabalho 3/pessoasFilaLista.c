#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pessoasFilaLista.h"
#include "cartasPilha.h"

#define MAX 50

struct roupa{
	char tipo[MAX];
	char tamanho;
	char cor[MAX];
};

struct relatorioRoupa{

   Roupa *roupa;
   struct relatorioRoupa *prox;

};

struct relatorioCarta{
	char nomeCarta[MAX]; 
   	Carta* carta;
   	struct relatorioCarta *prox;

};

struct fila{

	Lista* ini;
	Lista* fim;

};

struct lista{

	char nomePessoa[MAX];
	Roupa* roupa;
	Carta* card;
	struct lista* prox;

};

RelatorioRoupa* criaRoupa(){
   return NULL;
}

RelatorioCarta* criaCarta(){
   return NULL;
}

Roupa* cria_Roupa(){
	Roupa* p = (Roupa*)malloc(sizeof(Roupa));
	return p;
}

Fila* f_cria(){

	Fila* f = (Fila*)malloc(sizeof(Fila));

	f->ini = NULL;
	f->fim = NULL;

	return f;
}

int f_vazia(Fila* f){
	
	return f->ini ==NULL;
}

void f_libera(Fila* f){

	Lista* aux = f->ini;
	
	while(aux!=NULL){
		
		Lista* T = aux;
		aux = aux->prox;
		free(T);
	}

	free(f);
}

void l_liberaCarta(RelatorioCarta* l){

	RelatorioCarta* aux = l;
	
	while(aux!=NULL){

		RelatorioCarta* T = aux->prox;
		free(aux);
		aux = T;
	}
}

void l_liberaRoupa(RelatorioRoupa* l){
	
	RelatorioRoupa* aux = l;
	
	while(aux!=NULL){

		RelatorioRoupa* T = aux->prox;
		free(aux);
		aux = T;
	}
}

void preencherRoupa(Roupa* r, char *tipo, char tamanho, char *cor){

	strcpy(r->tipo, tipo);
	r->tamanho = tamanho;
	strcpy(r->cor,cor);

}

void inserir_pessoa_fila(Fila* f, char *nome, Roupa* roupa){

	Lista* novo = (Lista*)malloc(sizeof(Lista));

	strcpy(novo->nomePessoa, nome);
	novo->roupa = roupa;
	novo->card = NULL; 

	if(f->fim != NULL){
		
		f->fim->prox = novo;
	}
	else{
		
		f->ini = novo;
	}
	
	f->fim = novo;
}



void fila_imprime(Fila* f){

	Lista* q;
	
	for(q=f->ini; q!=NULL; q=q->prox){

		printf("[Nome]: %s \t", q->nomePessoa);
		printf("[Roupa]: Tipo: %s, Tamanho: %c, Cor: %s\n", q->roupa->tipo,q->roupa->tamanho,q->roupa->cor );
	}
}

void f_retirar(Fila* *f){

	Fila* aux = *f;
	Lista* t;

	if(f_vazia(aux)){
		
		printf("Fila vazia!\n");
		exit(1);
	}
	
	t = aux->ini;
	
	aux->ini = t->prox;

	if(aux->ini == NULL){

		aux->fim = NULL;
	}
	
	free(t);
}

void inserirNoRelatorioCarta(RelatorioCarta* *relCarta, char *nome, Carta* carta){

	RelatorioCarta* aux = *relCarta;

	RelatorioCarta* novo = (RelatorioCarta*)malloc(sizeof(RelatorioCarta));
	
	strcpy(novo->nomeCarta,nome);
	novo->carta = carta;
	novo->prox = aux;

	*relCarta = novo;
}

void inserirNoRelatorioRoupa(RelatorioRoupa* *relRoupas, Roupa* roupa){

	RelatorioRoupa* aux = *relRoupas;

	RelatorioRoupa* novo = (RelatorioRoupa*)malloc(sizeof(RelatorioRoupa));

	novo->roupa = roupa;

	novo->prox = aux;

	*relRoupas = novo;
}

void troca(Fila* f, Pilha* p, RelatorioRoupa* *relRoupa, RelatorioCarta* *relCarta){
	
	if(p_vazia(p)){
		
		printf("Não tem mais cartas, para troca!\n");

		return;
	}
	if(f_vazia(f)){
		
		printf("Não tem mais pessoas para doar roupa!\n");

		return;
	}
	else{

		Carta* carta = p_pop_aux(p);

		Lista* primeiroFila = f->ini;
		
		Roupa* roupaAux = primeiroFila->roupa;

		char nome[50];
		
		strcpy(nome,primeiroFila->nomePessoa);

		RelatorioRoupa* aux1 = *relRoupa;
		RelatorioCarta* aux2 = *relCarta;

		inserirNoRelatorioRoupa(&*relRoupa, roupaAux);
		inserirNoRelatorioCarta(&*relCarta, nome, carta);
		
		f_retirar(&f);
	}
}


void imprime_Relario_Roupas(RelatorioRoupa* l){
	
	RelatorioRoupa* aux = l;
	int i=0;
	
	while(aux!=NULL){
		
		printf("[%d]Roupa -  Tipo: [%s], Tamanho: [%c], Cor: [%s] \n",i,aux->roupa->tipo,aux->roupa->tamanho,aux->roupa->cor);
		i++;
		
		aux = aux->prox;
	}
}

void imprime_Relatorio_Cartas(RelatorioCarta* l){
	
	RelatorioCarta* aux = l;

	while(aux!=NULL){
		
		printf("[Nome da Pessoa]: [%s]  ", aux->nomeCarta);
		dados_carta(aux->carta);

		aux = aux->prox;
	}
}










