#include <stdio.h>

int soma(int* v, int n);
float media(int* v, int n);

int main(){
	
	int vetor[5] = {5,2,1,3,4}; /* OUTPUT = 3 */
	int i;

	for(i=0; i<5; i++){

		printf("[%d] ", vetor[i]);
	}

	printf("\n\n");

	printf("A media do vetor é %.2f", media(vetor, 5));

	printf("\n");

	return 0;
}

int soma(int* v, int n){

	if(n==1){

		return v[0];
	}

	return v[0] + soma(v+1, n-1);
}

float media(int* v, int n){

	return (float)soma(v, n)/n;
}