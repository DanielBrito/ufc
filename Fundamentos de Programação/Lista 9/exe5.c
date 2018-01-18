#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/*
	5) Faça um programa que receba uma frase, divida-a em palavras e as mostre.
*/

int main(){
	
	char string[40];
	char* p;
	
	printf("Digite uma frase: ");
	scanf(" %[^\n]", string);
	
	p = strtok(string, " ");
	
	printf("\n");
	
	while(p!=NULL){
		
		printf("%s\n", p);
		p = strtok(NULL, " ");
	}
	
	printf("\n\n");
	
	return 0;
}
