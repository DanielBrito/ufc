#include "lib.h"

#define n 3

int main(void) {

	int i, j, r, maximo_elementos;

	int arrays[n][n] = {{1, 3, 5}, {2, 4, 8}, {7, 10, 21}};

	maximo_elementos = n*n;
	r = 0;

	int resultado[maximo_elementos];

	heap *h = criar(maximo_elementos);

	for(i=0; i<n; i++){

		for(j=0; j<n; j++){

			heap_insere(h, arrays[i][j]);
		}
	}

	while(!heap_vazia(h)){

		resultado[r++] = heap_retira(h);
	}

	for(r=0; r<maximo_elementos; r++){

		printf("%d ", resultado[r]);
	}

	printf("\n");

  return 0;
}
