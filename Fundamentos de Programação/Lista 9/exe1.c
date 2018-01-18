#include<stdio.h>
#include<stdlib.h>

/*
	1) Escreva um programa que realize os seguintes itens abaixo:
	
	a) Declare um vetor do tipo int com tamanho 5 e inicialize os elementos
	do vetor com os inteiros pares de 2 a 10;
	
	b) Declare um ponteiro do tipo int que aponte para o primeiro elemento
	do vetor criado no item a;
	
	c) Imprima os elementos do vetor usando a notação de índice (vetor[i]) e
	estrutura de repetição;
	
	d) Imprima os elementos do vetor usando a notação de ponteiro para vetor e
	estrutura de repetição;
*/

int main(){
	
	int vetor[5] = {2,4,6,8,10};
	int *p = vetor;
	int i;
	
	printf("IMPRESSAO - INDICES:\n");
	
	for(i=0; i<5; i++){
		
		printf("%5d ", vetor[i]);
	}
	
	printf("\n\n");
	
    printf("IMPRESSAO - PONTEIROS:\n");
    
    for(i = 0; i < 5; i++){
    	
        printf("%5d ", *(p+i));
    }
	
	printf("\n\n");
	
	return 0;
}
