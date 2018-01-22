#include<stdio.h>
#include<stdlib.h>

#define TAM 10

void bubblesortRecursivo(int t, int* v);

int main(){
	
	int vetor[TAM] = {7, 9, 6, 4, 0, 2, 5, 1, 8, 3};
	int i;

	printf("Vetor desordenado:\n");

	for(i=0; i<TAM; i++){

		printf("%d ", vetor[i]);
	}

	printf("\n\n");

	bubblesortRecursivo(TAM, vetor);

	printf("Vetor ordenado:\n");

	for(i=0; i<TAM; i++){

		printf("%d ", vetor[i]);
	}

	printf("\n\n");

	return 0;
}


void bubblesortRecursivo(int t, int* v){

    int i, j, aux;

    if(t>1){

    	for(j=0; j<=t-1; j++){

        	if(v[j]>v[j+1]){

          		aux = v[j];
          		v[j] = v[j+1];
          		v[j+1]=aux;
        	}

        	bubblesortRecursivo(t-1, v);
     	}
    }
}