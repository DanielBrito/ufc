#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int palindromia(char* str);

int main(){

	char string[20];

	printf("Digite uma palavra: ");
	scanf("%s", string);
	
	printf("\n\n");

	if(palindromia(string)){

		printf("A palavra e palindroma.");
	}
	else{

		printf("A palavra nao e palindroma.");
	}

	printf("\n\n");

	return 0;
}


int palindromia(char* str){
	
	int tam = strlen(str);

	if(tam==1 || tam==0){

		return 1;
	}
	else
	if(str[0] != str[tam-1]){
		
		return 0;
	}
	
	str[tam-1] = '\0';
	
	return palindromia(&str[1]);
}

