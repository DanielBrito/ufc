#include<stdio.h>
#include<stdlib.h>

#define TAM 8

int main(){
	
	int vetor[TAM], vetorPares[TAM], vetorImpares[TAM];
	int i, cont=0;
	
	for(i=0; i<TAM; i++){
		
		printf("Digite o valor da posicao [%d]: ", i);
		scanf("%d", &vetor[i]);		
	}
	
	printf("\nVetor digitado:  ");
	
	for(i=0; i<TAM; i++){
		
		printf("[%d] ", vetor[i]);	
	}
	
	printf("\n\nNumeros pares:   ");
	
	for(i=0; i<TAM; i++){
		
		if(vetor[i]%2==0){
			
			printf("[%d] ", vetor[i]);
			
			cont++;
		}
	}
	
	while(cont<TAM){
			
		printf("[0] ");
			
		cont++;
	}
	
	cont = 0;
	
	printf("\n\nNumeros impares: ");
	
	for(i=0; i<TAM; i++){
		
		if(vetor[i]%2==1){
			
			printf("[%d] ", vetor[i]);
			
			cont++;
		}
	}
	
	while(cont<TAM){
			
		printf("[0] ");
			
		cont++;
	}
	
	printf("\n\n");
	
	return 0;
}
