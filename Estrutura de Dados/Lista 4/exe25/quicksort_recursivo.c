#include<stdio.h>
#include<stdlib.h>

#define TAM 10

void quicksortRecursivo(int* v, int inicio, int fim);


int main(){
	
	int vetor[TAM] = {7, 9, 6, 4, 0, 2, 5, 1, 8, 3};
	int i;

	printf("Vetor desordenado:\n");

	for(i=0; i<TAM; i++){

		printf("%d ", vetor[i]);
	}

	printf("\n\n");

	quicksortRecursivo(vetor, 0, TAM-1);

	printf("Vetor ordenado:\n");

	for(i=0; i<TAM; i++){

		printf("%d ", vetor[i]);
	}

	printf("\n\n");

	return 0;
}


void quicksortRecursivo(int* v, int inicio, int fim){
	
	int pivo, aux, i, j, meio;
	
	i = inicio;
	j = fim;
	
	meio = (int)((i+j)/2);
	pivo = v[meio];
	
	do{
		while (v[i] < pivo){

			i = i + 1;
		} 

		while (v[j] > pivo){

			j = j - 1;
		} 
		
		if(i <= j){

			aux = v[i];
			v[i] = v[j];
			v[j] = aux;

			i = i + 1;
			j = j - 1;
		}

	}while(j > i);
	
	if(inicio < j){

		quicksortRecursivo(v, inicio, j);
	} 

	if(i < fim){

		quicksortRecursivo(v, i, fim);	
	} 
}
