#include<stdio.h>
#include<stdlib.h>

typedef struct no{

	int elemento;
	struct no* esq;
	struct no* dir;
	int densidade;

}heap;

void menu();
heap* cria_heap(int valor);
void heap_libera(heap *h);
void troca_heaps (heap* a, heap*b);
heap* remover(heap* h);
void troca_filhos (heap* a);

heap* uniao(heap* h1, heap* h2);
heap* uniao_heaps(heap* h1, heap* h2);

void imprime(heap *h);

