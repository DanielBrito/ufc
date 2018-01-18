#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/*
	3) Faça um programa que receba uma string, conte e mostre quantas vezes
	uma letra é encontrada na string.
*/

int main(){
	
	char string[20];
	char letra;
	char* p;
	int cont=0;
	
	printf("Digite uma string: ");
	scanf(" %[^\n]", string);
	
	printf("\nDigite uma letra: ");
	scanf(" %c", &letra);
	
	p = strchr(string, letra);
	
	while(p!=NULL){
		
		cont++;
		p = strchr(p+1, letra);
	}
	
	printf("\n\nA letra '%c' aparece %d vez(es) na string digitada.", letra, cont);
	
	printf("\n\n");
	
	return 0;
}
