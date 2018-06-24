#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

int main(){

    Pilha* p = p_cria();
    int num;

    printf("Digite um numero: ");
    scanf("%d", &num);

    int i=2, d;

    d = num;

    while(d!=0){

        if(d%i == 0){

            d = d/i;

            if(d==1){

                d = 0;
            }

            p_push(p, i);
        }
        else{

            i++;
        }
    }

    printf("\nFatoracao prima de %d:\n", num);
    p_imprime(p);

    p_libera(p);

    printf("\n");

    return 0;
}