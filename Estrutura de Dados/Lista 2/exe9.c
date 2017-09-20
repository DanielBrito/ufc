#include<stdio.h>

int fatorialDuplo(int n);

int main(){

    int num;

    do{

        system("cls");

        printf("Digite um numero impar: ");
        scanf("%d", &num);

    }while(num%2==0);

    printf("\n\n");

    printf("O fatorial duplo de %d = %d", num, fatorialDuplo(num));

    printf("\n\n");

    return 0;
}


int fatorialDuplo(int n){

    int i;

    if(n==1){

        return 1;
    }
    else{

        if(n%2==1){

            return n*fatorialDuplo(n-2);
        }
    }
}
