#include <stdio.h>
#include <string.h>

/*Exemplos:
Roberto Cabral Rabelo Filho - possui 10 vogais
RObErto CabrAl Rabelo Filho - possui 10 vogais
*/

int contaVogais(char* str){

	char vogais[10] = "aeiouAEIOU";
	int tam = strlen(str);
	int i, j, cont=0;

	for(i=0; i<tam; i++){

		for(j=0; j<10; j++){

			if(str[i]==vogais[j]){

				cont++;

				break;
			}
		}
	}

	return cont;
}

int main(){

	char palavra[100];

	printf("Digite uma palavra: ");
	scanf(" %[^\n]", palavra);

	printf("A string - %s - possui %d vogais\n", palavra, contaVogais(palavra));
	
	return 0;
}