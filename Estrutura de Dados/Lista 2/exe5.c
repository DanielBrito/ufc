#include<stdio.h>
#include<stdlib.h>

void crescente(int n);

int main(){


    int num;

    printf("Digite um numero: ");
    scanf("%d", &num);

    crescente(num);

    printf("\n\n");

    return 0;
}


void crescente(int n){

    if(n==0){

        printf("%d ", n);
    }
    else{

        crescente(n-1);
        printf("%d ", n);
    }
}
