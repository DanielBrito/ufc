#include<stdio.h>

/*
	Faca um programa que leia 5 numeros digitados pelo usuario, calcule
	e mostre a media aritmetica dos numeros digitados. Este programa devera
	ser implementado usando uma estrutura de repeticao.
*/

int main(){
	
	int i;
	float num, soma;
	
	for(i=0; i<5; i++){
		
		printf("Digite o %do numero: ", i+1);
		scanf("%f", &num);
		
		soma += num;
	}
	
	printf("\n");
	
	printf("Media aritmetica = %.2f", soma/5);
	
	printf("\n\n");
	
	return 0;
}
