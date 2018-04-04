#include <stdio.h>

int somaVetor(int* v, int n);

int main(){
	
	int vetor[5] = {1,2,3,4,5};
	int i;

	for(i=0; i<5; i++){

		printf("[%d] ", vetor[i]);
	}

	printf("\n\n");

	printf("Soma dos elementos do vetor = %d", somaVetor(vetor, 5));

	printf("\n");

	return 0;
}

int somaVetor(int* v, int n){

	if(n==1){

		return v[0];
	}

	return v[0] + somaVetor(v+1, n-1);
}