#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<limits.h>

#define MIN_GUICHES 3 // Definição da quantidade mínima de guichês para atendimento.
#define GUICHE_PREFERENCIAL 1 // Definição do guichê preferencial.

#define MAX_HEAP 50 // Definição do tamanho de cada fila (heap).

// Definição da estrutura que representa um cliente a ser atendido:

struct cliente{

    int tipoAtendimento;
    bool necessidadeEspecial;
    int senha;
    char codigoSenha;
};

typedef struct cliente Cliente;

// Definição da estrutura que representa a fila de clientes em um determinado guichê:

struct heap{

	int qtdClientes;
	Cliente* clientes[MAX_HEAP];
};

typedef struct heap Heap;

// Definição da estrutura que representa cada um dos guichês da empresa (em forma de lista encadeada):

struct guiche{

    int id;
    Cliente* clienteAtendimento;
    struct guiche* prox;
};

typedef struct guiche Guiche;

// Métodos para exibição dos menus:

void menuPrincipal();
void subMenu();

// Métodos para gerenciamento dos guichês:

void abrirGuiche();
Guiche* inserir(Guiche* g, int id);
void fecharGuiche();
Guiche* remover(Guiche* g, int id);
void situacaoGuiches();
bool verificarExistenciaGuiche(int id);
Guiche* buscarGuiche(int id);
bool verificarAtendimentoGuiche(Guiche* g);

// Métodos para gerenciamento dos atendimentos:

void gerarSenha();
void atenderCliente();
void exibirCliente(Cliente* c);
void finalizarAtendimento();

// Métodos para manipulação da estrutura heap:

#define pai(i) (((i)-1)/2)
#define esq(i) (2*(i)+1)
#define dir(i) (2*(i)+2)

Heap* criarHeap();
bool heapVazia(Heap* h);
bool heapCheia(Heap* h);
void trocarHeap(Heap* h, int i, int j);
void subirHeap(Heap* h, int i);
void descerHeap(Heap* h, int i);
void inserirHeap(Heap* h, Cliente* c);
Cliente* retirarHeap(Heap* h);
void mostrarHeap(Heap* h);

// Métodos para inicialização e tratamento das alocações de memória:

void inicializar();
void liberarHeap(Heap* h);
void liberarGuiches();
void finalizar();