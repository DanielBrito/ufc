#include<stdio.h>
#include<stdlib.h>

#define TAM 10

void bubblesort(int t, int* v);

int main(){
	
	int vetor[TAM] = {7, 9, 6, 4, 0, 2, 5, 1, 8, 3};
	int i;

	printf("Vetor desordenado:\n");

	for(i=0; i<TAM; i++){

		printf("%d ", vetor[i]);
	}

	printf("\n\n");

	bubblesort(TAM, vetor);

	printf("Vetor ordenado:\n");

	for(i=0; i<TAM; i++){

		printf("%d ", vetor[i]);
	}

	printf("\n\n");

	return 0;
}


void bubblesort(int t, int* v){

	int i, j;

	for(i=t-1; i>0; i--){

		for(j=0; j<i; j++){

			if(v[j]>v[j+1]){

				int temp = v[j];
				v[j] = v[j+1];
				v[j+1] = temp;
			}
		}
	}
}