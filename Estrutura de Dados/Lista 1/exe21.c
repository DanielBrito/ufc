#include<stdio.h>
#include<stdlib.h>

int tam(char* str1){

    int i=0;

    while(str1[i] != '\0'){

        i++;
    }

    return i;
}

char* conc(char* str1, char* str2){

    int tam1, tam2, tam3, i, j;
    char* str3;

    tam1 = tam(str1);
    tam2 = tam(str2);
    tam3 = tam1 + tam2;

    str3 = (char*) malloc(sizeof(char)*tam3);

    for(i=0; i<tam1; i++)
    {
        str3[i] = str1[i];
    }

    for(j=0; j<tam2; j++)
    {
        str3[i] = str2[j];
        i++;
    }

    return str3;
}


int main(){

    char string1[20], string2[20];
    int tamanho1 = 0, tamanho2=0;

    printf("Digite a string 1: ");
    gets(string1);

    printf("Digite a string 2: ");
    gets(string2);

    printf("\n\nStrings concatenadas: %s", conc(string1, string2));

    printf("\n\n");

    return 0;
}
