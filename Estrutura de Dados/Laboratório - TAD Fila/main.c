#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

int main(){

    Fila* f = filaCria();

    filaInsere(f, 1);
    filaInsere(f, 2);
    filaInsere(f, 3);
    filaInsere(f, 4);

    printf("FILA:   ");
    filaImprime(f);

    filaRetira(f);

    printf("RETIRA: ");
    filaImprime(f);

    filaRetira(f);

    printf("RETIRA: ");
    filaImprime(f);

    filaRetira(f);

    printf("RETIRA: ");
    filaImprime(f);

    filaRetira(f);

    printf("RETIRA: ");
    filaImprime(f);

    filaLibera(f);

    printf("\n");

    return 0;
}