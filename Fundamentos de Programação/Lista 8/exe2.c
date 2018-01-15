#include<stdio.h>
#include<stdlib.h>

#define MAX 30

void imprimirVetor(int* vet);

int main(){
	
	int vetor1[MAX];
	int vetor2[MAX];
	
	int i, j;
	
	for(i=0; i<MAX; i++){
		
		vetor1[i] = i*2;
	}
	
	for(i=0; i<MAX; i++){
		
		vetor2[i] = i*3;
	}
	
	printf("VETOR 1: ");
	imprimirVetor(vetor1);
	printf("\n");
	
	printf("VETOR 2: ");
	imprimirVetor(vetor2);
	printf("\n\n");
	
	printf("INTESECCAO: ");
	
	for(i=0; i<MAX; i++){
		
		for(j=0; j<MAX; j++){
			
			if(vetor1[i]==vetor2[j]){
				
				printf("%2d ", vetor1[i]);
			}
		}
	}
	
	printf("\n\n");
	
	return 0;
}

void imprimirVetor(int* vet){
	
	int i;
	
	for(i=0; i<MAX; i++){
		
		printf("%2d ", vet[i]);
	}
}
