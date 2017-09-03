#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int tamanho(char* str);
int conta_vogais(char* str);

int main(){
	
	char string[20];
	
	printf("Digite uma string: ");
	gets(string);
	
	printf("\nA string '%s' tem %d vogais.", string, conta_vogais(string));

    printf("\n\n\n");

	system("PAUSE");
    return 0;
}

int tamanho(char* str){
	
	int tam=0, i=0;
	
	while(str[i] != '\0'){
		
		tam += 1;
		i++;
	}
	
	return tam;
}

int conta_vogais(char* str){
	
	int cont=0, tam=0, i, j;
	char vogais[10] = "aeiouAEIOU";
	
	tam = tamanho(str);
	
	for(i=0; i<tam; i++){
		
		for(j=0; j<10; j++){
			
			if(str[i] == vogais[j]){
				
				cont++;
			}
		}
	}
	
	return cont;
}
