#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/*
	2) Faça um programa que mostre o tamanho de uma string usando a 
	função strlen()
*/

int main(){
	
	char string[10] = "Hackerman";
	int tamanho = strlen(string);
	
	printf("A string '%s' tem %d caracteres", string, tamanho);
	
	printf("\n\n");
	
	return 0;
}
