#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/*
	4) Faça uma função que receba uma string (frase) como parâmetro e
	retorne quantas vogais existem na string.
*/

int contaVogais1(char* str);
int contaVogais2(char* str);

int main(){
	
	char frase[30];
	
	printf("Digite uma frase: ");
	scanf(" %[^\n]", frase);
	
	printf("\n\n");
	
	printf("Versao1: Existe(m) %d vogal(ais) na frase digitada.\n", contaVogais1(frase));
	printf("Versao2: Existe(m) %d vogal(ais) na frase digitada.", contaVogais2(frase));
	
	printf("\n\n");
	
	return 0;
}


int contaVogais1(char* str){
	
	int i, cont=0;
	
	for(i=0; i<strlen(str); i++){
		
		if(str[i]=='a'||str[i]=='e'||str[i]=='i'||str[i]=='o'||str[i]=='u'){
			
			cont++;
		}
	}
	
	return cont;
}


int contaVogais2(char* str){
	
	char vogais[5] = "aeiou";
	int i, j, cont=0;
	
	for(i=0; i<strlen(str); i++){
		
		for(j=0; j<strlen(vogais); j++){
			
			if(str[i]==vogais[j]){
				
				cont++;
				break;
			}
		}
	}
	
	return cont;
}
