// AVALIAÇÃO - QUESTÃO 5:

/*

Escreva uma função recursiva que recebe como entrada uma cadeia de caracteres e 
retorna 1 se essa cadeia for palíndroma e 0 caso contrário. O protótipo da função 
é dado por int palindrome(char *str)

*/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int palindrome(char* str);

int main(){

	char string[30];
	char copia[30];

	printf("Digite uma palavra: ");
	scanf("%s", string);

	strcpy(copia, string);

	if(palindrome(string)==1){

		printf("A string '%s' e um palindromo.", copia);
	}
	else{

		printf("A string '%s' nao e um palindromo.", copia);
	}

	printf("\n\n");	

	return 0;
}


int palindrome(char* str){

	int tam = strlen(str);

	if(tam==0 || tam==1){

		return 1;
	}
	else{

		if(str[0] != str[tam-1]){

			return 0;
		}

		str[tam-1] = '\0';
	}

	return palindrome(&str[1]);

}