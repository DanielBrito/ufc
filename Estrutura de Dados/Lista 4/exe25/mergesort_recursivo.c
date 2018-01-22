#include<stdio.h>
#include<stdlib.h>

#define TAM 10

void mergesortRecursivo(int p, int t, int* v);
void intercala(int p, int q, int r, int* v);

int main(){
	
	int vetor[TAM] = {7, 9, 6, 4, 0, 2, 5, 1, 8, 3};
	int i;

	printf("Vetor desordenado:\n");

	for(i=0; i<TAM; i++){

		printf("%d ", vetor[i]);
	}

	printf("\n\n");

	mergesortRecursivo(0, TAM, vetor);

	printf("Vetor ordenado:\n");

	for(i=0; i<TAM; i++){

		printf("%d ", vetor[i]);
	}

	printf("\n\n");

	return 0;
}


void intercala(int p, int q, int r, int* v){

	int i, j, k, *w;

	w = malloc((r-p)*sizeof(int));

	i = p;
	j = q;
	k = 0;

	while(i<q && j<r){

		if(v[i]<=v[j]){

			w[k++] = v[i++];
		}
		else{

			w[k++] = v[j++];
		}
	}

	while(i<q){

		w[k++] = v[i++];
	}

	while(j<r){

		w[k++] = v[j++];
	}

	for(i=p; i<r; i++){

		v[i] = w[i-p];
	}

	free(w);
}


void mergesortRecursivo(int p, int t, int* v){

	int q;

	if(p<t-1){

		q = (p+t)/2;

		mergesortRecursivo(p, q, v);
		mergesortRecursivo(q, t, v);
		intercala(p, q, t, v);
	}
}