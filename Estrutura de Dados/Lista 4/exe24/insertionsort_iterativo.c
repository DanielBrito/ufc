#include<stdio.h>
#include<stdlib.h>

#define TAM 10

void insertionsort(int t, int* v);

int main(){
	
	int vetor[TAM] = {7, 9, 6, 4, 0, 2, 5, 1, 8, 3};
	int i;

	printf("Vetor desordenado:\n");

	for(i=0; i<TAM; i++){

		printf("%d ", vetor[i]);
	}

	printf("\n\n");

	insertionsort(TAM, vetor);

	printf("Vetor ordenado:\n");

	for(i=0; i<TAM; i++){

		printf("%d ", vetor[i]);
	}

	printf("\n\n");

	return 0;
}


void insertionsort(int t, int* v){

	int i, j, x;

	for(j=1; j<t; j++){

		x = v[j];

		for(i=j-1; i>=0 && v[i]>x; i--){

			v[i+1] = v[i];
		}

		v[i+1] = x;
	}
}