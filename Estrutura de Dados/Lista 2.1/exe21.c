#include <stdio.h>

int contaChar(char* str, char ch);

int main(){
	
	char palavra[30];
	char letra;

	printf("Digite uma palavra: ");
	scanf("%s", palavra);

	printf("Digite um caractere: ");
	scanf(" %c",  &letra);

	printf("\n");

	printf("O caractere '%c' aparece %d vez(es) na palavra '%s'", letra, contaChar(palavra, letra), palavra);

	printf("\n");

	return 0;
}

int contaChar(char* str, char ch){

	if(str[0]=='\0'){

		return 0;
	}

	if(str[0]==ch){

		return 1 + contaChar(str+1, ch);
	}

	return contaChar(str+1, ch);
}