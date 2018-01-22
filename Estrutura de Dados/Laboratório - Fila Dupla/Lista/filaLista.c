#include<stdio.h>
#include<stdlib.h>
#include"filaLista.h"

struct lista2{

	float info;
	struct lista2* ant;
	struct lista2* prox;
};

struct fila2{

	Lista2* ini;
	Lista2* fim;
};


Fila2* fila2_cria(){

	Fila2* f = (Fila2*)malloc(sizeof(Fila2));

	f->ini = f->fim = NULL;

	return f;
}


Lista2* insere2_ini(Lista2* ini, float v){

	Lista2* p = (Lista2*)malloc(sizeof(Lista2));

	p->info = v;
	p->prox = ini;
	p->ant = NULL;

	if(ini != NULL){

		ini->ant = p;
	}

	return p;
}


Lista2* insere2_fim(Lista2* fim, float v){

	Lista2* p = (Lista2*)malloc(sizeof(Lista2));

	p->info = v;
	p->prox = NULL;
	p->ant = fim;

	if(fim!=NULL){

		fim->prox = p;
	}

	return p;
}


Lista2* retira2_ini(Lista2* ini){

	Lista2* p = ini->prox;

	if(p!=NULL){

		p->ant = NULL;
	}

	free(ini);

	return p;
}


Lista2* retira2_fim(Lista2* fim){

	Lista2* p = fim->ant;

	if(p!=NULL){

		p->prox;
	}

	free(fim);

	return p;
}


void fila2_insere_ini(Fila2* f, float v){

	f->ini = insere2_ini(f->ini, v);

	if(f->fim==NULL){

		f->fim = f->ini;
	}
}


void fila2_insere_fim(Fila2* f, float v){

	f->fim = insere2_fim(f->fim, v);

	if(f->ini==NULL){

		f->ini = f->fim;
	}
}


float fila2_retira_ini(Fila2* f){

	float v;

	if(fila2_vazia(f)){

		printf("Fila vazia!\n");
		exit(1);
	}

	v = f->ini->info;
	f->ini = retira2_ini(f->ini);

	if(f->ini==NULL){

		f->fim = NULL;
	}

	return v;
}


float fila2_retira_fim(Fila2* f){

	float v;

	if(fila2_vazia(f)){

		printf("Fila vazia!\n");
		exit(1);
	}

	v = f->fim->info;

	f->fim = retira2_fim(f->fim);

	if(f->fim==NULL){

		f->ini = NULL;
	}

	return v;
}


int fila2_vazia(Fila2* f){

	return (f->ini==NULL);
}