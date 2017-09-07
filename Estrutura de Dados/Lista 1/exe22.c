#include<stdio.h>
#include<stdlib.h>

char* concatena(char* str1, char* str2, int num);
int tam(char* str);

int main(){

    char string1[20], string2[20];
    int tamanho1 = 0, tamanho2=0, num;

    printf("Digite a string 1: ");
    gets(string1);

    printf("Digite a string 2: ");
    gets(string2);
    
    printf("Digite um valor: ");
    scanf("%d", &num);

    printf("\nStrings concatenadas: %s", concatena(string1, string2, num));

    printf("\n\n");
    
    system("PAUSE");

    return 0;
}


int tam(char* str){

    int i=0;

    while(str[i] != '\0'){

        i++;
    }

    return i;
}

char* concatena(char* str1, char* str2, int num){

    int tam1, tam2, i;
    
    tam1 = tam(str1);
    tam2 = tam(str2);
    
    for(i=0; i<num; i++){
    	
    	str1[tam1] = str2[i];
    	
    	tam1++;
	}
	
	str1[tam1] = '\0';
    
    return str1;
}
