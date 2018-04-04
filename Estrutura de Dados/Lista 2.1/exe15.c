#include <stdio.h>

void inverte(int* v, int n){

	if(n<1){

		return;
	}

	int aux = v[0];
	v[0] = v[n-1];
	v[n-1] = aux;

	inverte(v+1, n-2);
}

int main(){
	
	int vet[5] = {1,2,3,4,5};
	int i;

	printf("Vetor original:\n");

	for(i=0; i<5; i++){

		printf("%d ", vet[i]);
	}

	inverte(vet, 5);

	printf("\n\n");

	printf("Vetor invertido:\n");

	for(i=0; i<5; i++){

		printf("%d ", vet[i]);
	}

	printf("\n");

	return 0;
}