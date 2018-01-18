#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/*
	7) Faça um programa que receba uma string e converta toda a string para
	letras maiúsculas usando a função strupr().
*/

int main(){
	
	char string[40];
	
	printf("Digite uma frase: ");
	scanf(" %[^\n]", string);
	
	printf("\n\n");
	
	strcpy(string, strupr(string));
	
	printf("%s", string);
	
	printf("\n\n");
	
	return 0;
}
