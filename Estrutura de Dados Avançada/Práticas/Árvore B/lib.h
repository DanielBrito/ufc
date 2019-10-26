#include<stdlib.h>
#include<stdio.h>

#define FALSE 0
#define TRUE 1

#define ordem 2
#define maximo (ordem*2)

typedef struct registro{

  int chave;

} Tregistro;

typedef struct pagina* Tpagina;

typedef struct pagina{

  short n;
  Tregistro registro[maximo];
  Tpagina folha[maximo+1];

} pagina;

void menu();
Tregistro* pesquisar(int, Tpagina );
void insere_na_pagina(Tpagina, Tregistro, Tpagina );
int insere_rec(Tregistro, Tpagina, Tregistro *, Tpagina *);
Tpagina insere(Tregistro, Tpagina);
void imprime(Tpagina, int);


