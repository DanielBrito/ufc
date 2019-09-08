#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<stdbool.h>

#define MAX 10
#define SAIR 0

// A estrutura lista representa os nós que irão armazenar os dados das mensagens trocadas:

struct lista{

    int codigoMensagem;
	int codigoRemetente;
	int codigoDestinatario;
	char mensagem[50];
	struct lista* prox;
};

typedef struct lista Lista;

// O vetor de registros irá armazenar as listas de mensagens trocadas:

Lista* registros[MAX];

// Métodos do remetente: 

void enviarMensagem(int codMensagem, char* nomeRemetente, char* nomeDestinatario, char* mensagem);
Lista* inserirMensagem(Lista* l, int codMensagem, int codRemetente, int codDestinatario, char* mensagem);

// Métodos do destinatário:

void buscarMensagem(int codMensagem, char* nomeDestinatario);
void buscarRemocao(int codMensagem, char* nomeDestinatario);
Lista* removerMensagem(Lista* l, int codDestinatario);

// Métodos para tratar da alocação dinâmica:

void inicializar();
void apagarRegistros();
void liberarLista(Lista* l);

// Métodos para realizar a transição entre as telas:

void menuPrincipal();
void menuRemetente();
void menuDestinatario();
void subMenu();

// Funções para criptografia dos dados:

int hashCodigo(int chave);
int hashNome(char* chave);