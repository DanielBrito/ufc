#include<stdio.h>
#include<stdlib.h>

void decrescente(int n);

int main(){


    int num;

    printf("Digite um numero: ");
    scanf("%d", &num);

    decrescente(num);

    printf("\n\n");

    return 0;
}


void decrescente(int n){

    if(n==0){

        printf("%d ", n);
    }
    else{

        printf("%d ", n);
        decrescente(n-1);
    }
}
