#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/*
	11) Faça uma função que receba uma palavra e verifique se ela
	é um palíndromo.
*/

int palindromia(char* str);

int main(){
	
	char string[40];
	int i, j;
	
	printf("Digite uma palavra: ");
	scanf(" %[^\n]", string);
	
	printf("\n\n");
	
	if(palindromia(string)){
		
		printf("A palavra e um palindromo.");
	}
	else{
		
		printf("A palavra nao e um palindromo.");
	}
	
	printf("\n\n");
	
	return 0;
}


int palindromia(char* str){
	
	int i, j;
	
	for(i=0, j=strlen(str)-1; i<strlen(str), j>=0; i++, j--){
		
		if(str[i]!=str[j]){
			
			return 0;
		}
	}
	
	return 1;
}
