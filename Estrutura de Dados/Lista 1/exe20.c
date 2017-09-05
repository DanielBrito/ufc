#include<stdio.h>

int myStrlen(char* str);

int main(){
	
	char string[50];
	
	printf("Digite uma string: ");
	scanf(" %50[^\n]", string);
	
	printf("\nA string digitada tem %d caracteres.", myStrlen(string));
	
	printf("\n\n");
	
	return 0;
}


int myStrlen(char* str){
	
	int i, tam=0;
	
	while(str[i] != '\0'){
		
		tam += 1;
		
	    // Necessário, pois, no percorrimento de uma string composta os espaços também estavam sendo incrementados:
		
		if(str[i]==' '){  
			
			tam -= 1;
		}
		
		i++;
		
	}
	
	return tam;
}
