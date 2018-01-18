#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/*
	9) Faça um programa que receba uma frase com letras minúsculas e
	converta a primeira letra de cada palavra da frase para maiúscula.
*/

int main(){
	
	char string[40];
	int i;
	
	printf("Digite uma frase: ");
	scanf(" %[^\n]", string);
	
	for(i=0; i<strlen(string); i++){
		
		if(i==0){
			
			string[i] = toupper(string[i]);
		}
		else
		if(string[i]==' '){
			
			 string[i+1] = toupper(string[i+1]);
		}
	}
	
	printf("\n\n");
	
	printf("%s", string);
	
	printf("\n\n");
	
	return 0;
}
