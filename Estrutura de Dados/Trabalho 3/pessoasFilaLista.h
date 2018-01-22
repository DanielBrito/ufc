#include "cartasPilha.h"

typedef struct relatorioRoupa RelatorioRoupa;

typedef struct relatorioCarta RelatorioCarta;

typedef struct roupa Roupa;

typedef struct fila Fila;

typedef struct lista Lista;

RelatorioCarta* criaCarta();

RelatorioRoupa* criaRoupa();

Roupa* cria_Roupa();

void inserirNoRelatorioRoupa(RelatorioRoupa* *relRoupas, Roupa* roupa);

void inserirNoRelatorioCarta(RelatorioCarta* *relCarta, char *nome, Carta* carta);

void imprime_Relatorio_Cartas(RelatorioCarta* l);

void imprime_Relario_Roupas(RelatorioRoupa* l);


/* Fila de Pessoas */

Fila* f_cria();

void f_inserir(Fila* f, float v);

int f_vazia(Fila* f);

void f_libera(Fila* f);

void f_retirar(Fila* *f);

void fila_imprime(Fila* f);

void troca(Fila* f, Pilha* p, RelatorioRoupa* *relRoupa, RelatorioCarta* *relCarta);

void inserir_pessoa_fila(Fila* f, char *nome, Roupa* roupa);

int f_quantidade(Fila* f);

void imprimeFila(Fila *f);

Lista* cria_pessoa(char *nome, Roupa* roupa);

Roupa* cria_Roupa();

void preencherRoupa(Roupa* r, char *tipo, char tamanho, char *cor);

void l_liberaCarta(RelatorioCarta* l);

void l_liberaRoupa(RelatorioRoupa* l);
