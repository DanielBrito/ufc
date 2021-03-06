#include<stdio.h>
#include<stdlib.h>

int contaCaractere(char* str, char l);

int main(){

	char string[20];
	char letra;

	printf("Digite uma string: ");
	scanf(" %[^\n]", string);

	printf("Digite uma letra: ");
	scanf(" %c", &letra);
	
	printf("\n\n");

	printf("A letra '%c' aparece %d vez(es) na string '%s'.", letra, contaCaractere(string, letra), string);

	printf("\n\n");

	return 0;
}

int contaCaractere(char* str, char l){

	int i=0, cont=0;

	while(str[i] != '\0'){

		if(str[i]==l){

			cont++;

			return cont + contaCaractere(&str[i+1], l);
		}
		else{

			return contaCaractere(&str[i+1], l);
		}
	}
}
