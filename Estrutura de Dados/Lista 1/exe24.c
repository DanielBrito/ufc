#include<stdio.h>

int tamanho(char* str);
int palindromia(char* str);

int main(){
	
	char string[20];
	
	printf("Digite uma string: ");
	scanf("%s", string);
	
	if(!palindromia(string)){
		
		printf("A string e um palindromo.");
	}
	else{
		
		printf("A string nao e um palindromo");
	}
	
	printf("\n\n");
	
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


int palindromia(char* str){
	
	int i=0, tam=0;
	
	tam = tamanho(str)-1; // Pois a string vai de [0] até [TAM-1]
	
	while(i<=tam){
		
		if(str[i]!=str[tam]){
			
			return 1;
		}
		
		i++;
		tam--;
	}
	
	return 0;
}
