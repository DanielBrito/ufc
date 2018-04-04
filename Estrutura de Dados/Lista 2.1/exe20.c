#include <stdio.h>
#include <string.h>

int palindrome(char* str, int n);

int main(){
	
	char palavra[30];

	printf("Digite uma palavra: ");
	scanf("%s", palavra);

	printf("\n");

	if(palindrome(palavra, strlen(palavra))){

		printf("A palavra '%s' é um palíndromo", palavra);
	}
	else{

		printf("A palavra '%s' não é um palíndromo", palavra);
	}

	printf("\n");

	return 0;
}

int palindrome(char* str, int n){

	if(n<=1){

		return 1;
	}

	if(str[0]!=str[n-1]){

		return 0;
	}

	palindrome(str+1, n-1);

	return 1;
}