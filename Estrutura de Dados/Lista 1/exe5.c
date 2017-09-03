#include<stdio.h>
#include<string.h>

int tamanho(char* str);
int conta_char(char* str, char c);

int main(){
	
    char string[20];
    char letra;

    printf("Digite uma string: ");
    gets(string);

    printf("Digite um caractere: ");
    scanf(" %c", &letra);

    printf("\n");

    printf("O caractere '%c' aparece %d vez(es) na string '%s'.", letra, conta_char(string, letra), string);
    
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


int conta_char(char* str, char c){
	
    int i, tam = 0, cont = 0;
    tam = tamanho(str);

    for(i=0; i<tam; i++){
    	
        if(c == str[i]){
        	
            cont++;
        }
    }

    return cont;
}
