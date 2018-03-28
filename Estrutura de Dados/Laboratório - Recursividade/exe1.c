#include <stdio.h>
#include <string.h>

void inverteStr(char* str, int n){
	
	if(n<1){

		return;
	}

	int aux = str[0];
	str[0] = str[n-1];
	str[n-1] = aux;

	inverteStr(str+1, n-2);
}

int main(){

	char palavra[30];
	
	printf("Digite uma palavra: ");
	scanf("%s", palavra);
	
	printf("\n");

	printf("Palavra original: %s\n\n", palavra);

	inverteStr(palavra, strlen(palavra));

	printf("Palavra invertida: %s\n", palavra);
	
	printf("\n");

	return 0;
}
