#include<stdio.h>
#include<stdlib.h>

#define TAM 10

void insertionsortRecursivo(int t, int* v);

int main(){
	
	int vetor[TAM] = {7, 9, 6, 4, 0, 2, 5, 1, 8, 3};
	int i;

	printf("Vetor desordenado:\n");

	for(i=0; i<TAM; i++){

		printf("%d ", vetor[i]);
	}

	printf("\n\n");

	insertionsortRecursivo(TAM, vetor);

	printf("Vetor ordenado:\n");

	for(i=0; i<TAM; i++){

		printf("%d ", vetor[i]);
	}

	printf("\n\n");

	return 0;
}


void insertionsortRecursivo(int t, int* v){

	int i, j, x;

  	if(t>1){

    	insertionsortRecursivo(t-1, v);

    	x = v[t-1];

    	for(i=t-2; i>=0 && v[i]>x; i--){

      		v[i+1] = v[i];
    	}

    	v[i+1] = x;
 	}
}