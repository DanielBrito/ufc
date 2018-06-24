#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

int main(){

    Fila* f = filaCria();
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

            filaInsere(f, i);
        }
        else{

            i++;
        }
    }

    printf("\nFatoracao prima de %d:\n", num);
    filaImprime(f);

    filaLibera(f);

    printf("\n");

    return 0;
}