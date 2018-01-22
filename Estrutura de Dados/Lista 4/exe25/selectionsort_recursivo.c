#include<stdio.h>
#include<stdlib.h>

#define TAM 10

void selectionsortRecursivo(int* v, int i, int t);

int main(){
	
	int vetor[TAM] = {7, 9, 6, 4, 0, 2, 5, 1, 8, 3};
	int i;

	printf("Vetor desordenado:\n");

	for(i=0; i<TAM; i++){

		printf("%d ", vetor[i]);
	}

	printf("\n\n");

	selectionsortRecursivo(vetor, 0, TAM);

	printf("Vetor ordenado:\n");

	for(i=0; i<TAM; i++){

		printf("%d ", vetor[i]);
	}

	printf("\n\n");

	return 0;
}


void selectionsortRecursivo(int* v, int i, int t){

	int j, min, temp;

	if(i>=t-1){

		return;
	}

	min = i;

	for(j=i+1; j<t; j++){

		if(v[j]<v[min]){

			min = j;
		}
	}

	temp = v[i];
	v[i] = v[min];
	v[min] = temp;

	selectionsortRecursivo(v, i+1, t);
}