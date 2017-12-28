#include<stdio.h>

/*
	Faca um programa que receba a altura e o peso de uma pessoa. De acordo com
	a tabela a seguir, verifique e mostre a classificacao dessa pessoa:
	
	     ALTURA								PESO
								Ate 60Kg            Acima de 60Kg
	Menores que 1,20		       A                      D
	De 1,20 ate 1,70		   	   B                      E
	Maiores que 1,70               C                      F
*/

int main(){
	
	float altura, peso;
	
	printf("Digite a altura: ");
	scanf("%f", &altura);
	
	printf("Digite o peso: ");
	scanf("%f", &peso);
	
	printf("\n");
	
	if(altura<1.20){
		
		if(peso<=60){
			
			printf("Classificacao: A");
		}
		else{
			
			printf("Classificacao: D");
		}
	}
	else
	if(altura>=1.20 && altura<=1.70){
		
		if(peso<=60){
			
			printf("Classificacao: B");
		}
		else{
			
			printf("Classificacao: E");
		}
	}
	else{
		
		if(peso<=60){
			
			printf("Classificacao: C");
		}
		else{
			
			printf("Classificacao: F");
		}
	}

	printf("\n\n");
	
	return 0;
}
