#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/*
	10) Faça um programa que receba uma string e inverta a string
	usando a função strrev().
*/

int main(){
	
	char string[40];
	int i;
	
	printf("Digite uma frase: ");
	scanf(" %[^\n]", string);
	
	printf("\n\n");
	
	strcpy(string, strrev(string));
	
	printf("%s", string);
	
	printf("\n\n");
	
	return 0;
}
