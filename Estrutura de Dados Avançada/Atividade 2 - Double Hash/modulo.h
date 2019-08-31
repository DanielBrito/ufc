#include<stdlib.h>
#include<string.h>
#include<stdio.h>
#include<stdbool.h>

#define MAX_CARTOES 5
#define MAX_TRANSACOES 50
#define PRIMO 13

#define SAIR 0

struct transacao{

    int codigoBoleto;
};

typedef struct transacao Transacao;

struct cartao{

	char nomeCliente[50];
	int numeroCartao;
	char bandeira[20];
	int codigoSeguranca;
    Transacao transacoes[MAX_TRANSACOES];
    int qtdTransacoes;
};

typedef struct cartao Cartao;

struct banco{

	Cartao cartoes[MAX_CARTOES];
	int qtdCartoes;
};

typedef struct banco Banco;

void inicializarBanco(Banco* B);
void inicializarCartao(Cartao* C);

int buscarCartao(Banco B, int pos, Cartao* C);
void listarTransacoes(Banco S);

float taxaDeOcupacao(Banco B);

int hash1(int chave);
int hash2(int chave);

int doubleHashInserir(Banco B, int index1, int chave);
int doubleHashBuscar(Banco B, int index1, int chave, Cartao* C);

void subMenu();