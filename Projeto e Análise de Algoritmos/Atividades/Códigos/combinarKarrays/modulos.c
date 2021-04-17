// Time Complexity :O( n * k * log k), Insertion and deletion in a Min Heap requires log k time. 
// So the Overall time compelxity is O( n * k * log k)

#include "lib.h"

heap* criar(int nmax){

	heap* h = (heap*)malloc(sizeof(heap));

	h->n=0;
	h->nmax = nmax;
	h->v = (int*)malloc(sizeof(int)*nmax);

	return h;
}

void heap_libera(heap *h){

	free(h->v);
	free(h);
}

int heap_vazia (heap *h){

	return h->n == 0;
}

void sobe (heap *h, int i){

	int pai;

	while(i>0){
		
		pai = pai(i);

		if(h->v[pai] <= h->v[i]) break;

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

	int filhoEsquerda = esq(i);
	int filhoDireita = dir(i);

	while(filhoEsquerda < h->n){

		filhoDireita = dir(i);

		if((filhoDireita > h->n) && (h->v[filhoDireita] < h->v[filhoEsquerda])){

			filhoEsquerda = filhoDireita;
		}

		if(h->v[filhoEsquerda] > h->v[i]){

			break;
		}

		troca(h, i, filhoEsquerda);

		i = filhoEsquerda;
		filhoEsquerda = esq(i);
	}
	
}

void heap_insere(heap *h, int valor){

	h->v[h->n++] = valor;

	sobe(h, h->n-1);		
}

int heap_retira (heap *h){

	int raiz = h->v[0];
	h->v[0] = h->v[--h->n];
	desce(h, 0);

	return raiz;	
}

void mostrar(heap *h){
	int i=0;
	if(h->n >0){
		puts("-----------ELEMENTOS-----------");
		for(int i=0;i<h->n;i++)
			printf("%d -", h->v[i]);
	}
	else{
		printf("Sem elementos");
	}
}
