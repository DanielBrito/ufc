#include <stdio.h>
#include <stdlib.h>

int menorElemento(int* v, int n);

int main(){

	int tam, i;
	int* vetor;

	printf("Digite o tamanho do vetor: ");
	scanf("%d", &tam);

	vetor = malloc(sizeof(int)*tam);

	for(i=0; i<tam; i++){

		printf("Valor da posição [%d]: ", i);
		scanf("%d", &vetor[i]);
	}
	
	printf("\n");

	for(i=0; i<tam; i++){

		printf("[%d] ", vetor[i]);
	}

	printf("\n\n");

	printf("Menor elemento do vetor: %d", menorElemento(vetor, tam));

	printf("\n");

	return 0;
}


int menorElemento(int* v, int n){

	if(n==1){

		return v[0];
	}

	int menor = 0;

	menor = menorElemento(v, n-1);

	if(menor<v[n-1]){

		return menor;
	}

	return v[n-1];
}