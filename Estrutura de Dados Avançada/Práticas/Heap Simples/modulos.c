#include "lib.h"

heap* criar(int nmax){
	heap *h = (heap *) malloc(sizeof(heap));
	h->n = 0;
	h->nmax = nmax;
	h->v = (int *) malloc(h->nmax * sizeof(int));
	return h;
}
void heap_libera(heap *h){
	free(h->v);
	free(h);
}

int heap_vazia (heap *h){
	if(h->n == 0) return 0;
	else return 1;
}

void sobe (heap *h, int i){
	int pai;
	while(i>0){ //enquanto não estiver na raiz
		pai = pai(i);
		if((h->v[pai])> (h->v[i]))
			break;
		troca(h, pai, i);
		i = pai;
	}
}

void troca (heap *h, int i, int j){
	int temp = h->v[i];
	h->v[i] = h->v[j];
	h->v[j] = temp;
}

void desce (heap *h, int i){
	int filho_esq = esq(i);
	int filho_dir;
	while(filho_esq < h->n){
		filho_dir = dir(i);
		if((filho_dir < h->n) && (h->v[filho_dir] > h->v[filho_esq]))
			filho_esq = filho_dir;
		if(h->v[filho_esq] < h->v[i])
			break;	
		troca(h,i,filho_esq);
		i = filho_esq;
		filho_esq = esq(i);	
	}
}

void heap_insere(heap *h, int valor){
	h->v[h->n++] = valor;
	sobe(h, h->n-1);	
}

int heap_retira (heap *h){
	int raiz = h->v[0]; //remove o elemento do topo
	h->v[0] = h->v[--(h->n)];
	desce(h,0);
	return raiz;
}

void mostrar(heap *h){
	int i=0;
	puts("-----------ELEMENTOS-----------");
	for(int i=0;i<h->n;i++)
		printf("%d -", h->v[i]);
}
