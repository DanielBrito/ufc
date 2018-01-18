#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/*
	6) Faça uma função que receba uma frase como parâmetro, calcule e
	mostre a quantidade de palavras da frase digitada.
*/

int main(){
	
	char string[40];
	char* p;
	int cont=0;
	
	printf("Digite uma frase: ");
	scanf(" %[^\n]", string);
	
	p = strtok(string, " ");
	
	while(p!=NULL){
	
		p = strtok(NULL, " ");
		cont++;
	}
	
	printf("\n\nA frase digitada tem %d palavras.", cont);
	
	printf("\n\n");
	
	return 0;
}
