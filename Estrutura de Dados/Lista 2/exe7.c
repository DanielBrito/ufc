#include<stdio.h>
#include<stdlib.h>

void parDecrescente(int n);

int main(){


    int num;

    printf("Digite um numero: ");
    scanf("%d", &num);

    parDecrescente(num);

    printf("\n\n");

    return 0;
}


void parDecrescente(int n){

    if(n==0){

        printf("%d ", n);
    }
    else{

        if(n%2==0){

            printf("%d ", n);
        }

        parDecrescente(n-1);
    }
}
