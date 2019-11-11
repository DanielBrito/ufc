#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX 100
#define BUFFER 1000

void inicializar();

void menuPrincipal();
void subMenu();

void inserirLivro();
void buscarLivro();
void modificarLivro();
void listarLivros();

int lerContador();
void salvarRegistro(char *tituloPort, char *tituloOrig, char *autor, int ano, char *pais, char *nota);

char *unificarTexto(char *texto);
char *separarTexto(char *texto);

void pausar(); // TESTE

// Métodos para manipulação da árvore B (depois adaptar para B+):

#define ORDEM 2
#define MAXIMO (ORDEM*2)

struct registro{

    int chave;
};

typedef struct registro Registro;

typedef struct pagina* Pagina;

struct pagina{

    int n;
    Registro registro[MAXIMO];
    Pagina folha[MAXIMO+1];
    struct pagina* prox;
    bool flagFolha; // True = folha | False: não-folha 

}pagina;

Registro* pesquisar(int, Pagina);
void inserir_na_pagina(Pagina, Registro, Pagina);
int inserir_recursivo(Registro, Pagina, Registro*, Pagina*);
Pagina inserir(Registro, Pagina);

void imprimirArvore(Pagina, int);