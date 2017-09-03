#include<stdio.h>
#include<math.h>

int coprimos(int x, int y);

int main(){

    int num1, num2, i;

    printf("Digite um numero: ");
    scanf("%d", &num1);

    printf("Digite um numero: ");
    scanf("%d", &num2);

    printf("\n");

    if(coprimos(num1, num2))

        printf("Os numeros %d e %d sao coprimos.", num1, num2);
    else
        printf("Os numeros %d e %d nao sao coprimos.", num1, num2);

    printf("\n\n");

    return 0;
}


int coprimos(int x, int y){

    int i, j, cont=0;

    for(i=1, j=1; i<=x, j<=y; i++, j++){

        if(x%i==0 && y%i==0){

            cont++;

            if(cont > 1){

                return 0;
            }
        }
    }

    return 1;
}
