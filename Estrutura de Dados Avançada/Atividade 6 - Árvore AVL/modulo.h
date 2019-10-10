#include<stdio.h>
#include<stdlib.h>
#include<time.h>

// Definição da quantidade máxima de pacotes que compõem cada tipo de mensagem:

#define MAX_MSG_A 20
#define MAX_MSG_B 50
#define MAX_MSG_C 70

// Estrutura (Árvore AVL) que irá armazenar as mensagens fragmentadas, ou seja, os (identificadores dos) pacotes:

struct no{

	int idPacote;
	char idMensagem;
	int fatorBalanceamento;
	struct no* esq;
	struct no* dir;
};

typedef struct no Tno;

// Método para inicializar e realizar a manipulação dos dados:

void inicializar();

// Métodos para manipulação dos arquivos:

void gerarArquivos();
void lerArquivos();

// Métodos para manipulação da Árvore AVL:

int alturaAVL(Tno* a);
int calcularFB(Tno* a);
Tno* rotacaoSimplesEsquerda(Tno* a);
Tno* rotacaoSimplesDireita(Tno* a);
Tno* balanceioEsquerda(Tno* a);
Tno* balanceioDireita(Tno* a);
Tno* balanceamento(Tno* a);
Tno* inserir(Tno* a, int idPacote, char idMensagem);
void imprimir(Tno* a, char idMensagem);
void liberar(Tno* a);