#include<stdio.h>
#include<stdlib.h>

#define TAM 10

void selectionsort(int t, int* v);

int main(){
	
	int vetor[TAM] = {7, 9, 6, 4, 0, 2, 5, 1, 8, 3};
	int i;

	printf("Vetor desordenado:\n");

	for(i=0; i<TAM; i++){

		printf("%d ", vetor[i]);
	}

	printf("\n\n");

	selectionsort(TAM, vetor);

	printf("Vetor ordenado:\n");

	for(i=0; i<TAM; i++){

		printf("%d ", vetor[i]);
	}

	printf("\n\n");

	return 0;
}


void selectionsort(int t, int* v){

	int i, j, min, x;

	for(i=0; i<t-1; i++){

		min = i;

		for(j=i+1; j<t; j++){

			if(v[j]<v[min]){

				min = j;
			}
		}

		x = v[i];
		v[i] = v[min];
		v[min] = x;
	}
}