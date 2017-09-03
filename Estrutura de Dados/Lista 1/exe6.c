#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
#include<string.h>

void minusculo(char* str);
int tam(char* str);

int main(){
	
	char string[30];
	int tam=0;
	
	printf("Digite uma string: ");
	gets(string);
	
	minusculo(string);
	
	printf("\n\n");
	
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


void minusculo(char* str){
	
	int tam, i;
	
	tam = tamanho(str);
	
	for(i=0; i<tam; i++){
		
		if(str[i] >= 65 && str[i] <= 90){
			
			str[i] = str[i]+32;
		}
	}
	
	printf("Nova string: %s", str);
}
