#include<stdio.h>
#include<stdlib.h>

int multiplicacao(int x, int y);

int main(){

    int n1, n2;

    printf("Digite um numero: ");
    scanf("%d", &n1);

    printf("Digite um numero: ");
    scanf("%d", &n2);

    printf("%d * %d = %d", n1, n2, multiplicacao(n1, n2));

    printf("\n\n");

    return 0;
}


int multiplicacao(int x, int y){

    if(y==1){

        return x;
    }

    return x+multiplicacao(x, y-1);
}
