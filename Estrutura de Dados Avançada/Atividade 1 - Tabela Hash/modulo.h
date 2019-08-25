#include<stdlib.h>
#include<string.h>
#include<stdio.h>
#include<stdbool.h>

#define MAX 100

struct cartao{

	char nomeCliente[50];
	int numeroCartao;
	char bandeira[20];
	int codigoSeguranca;
};

typedef struct cartao Cartao;

struct transacao{

	int codigoBoleto;
	Cartao cartao;	
};

typedef struct transacao Transacao;

struct banco{

	Transacao transacoes[MAX];
	int n;
};

typedef struct banco Banco;

int hashing(int chave);
void iniciarBanco(Banco* B);
int tamanho(Banco B);
int buscarPagamento(Banco B, int pos, Transacao* T);
void listarTransacoes(Banco S);
