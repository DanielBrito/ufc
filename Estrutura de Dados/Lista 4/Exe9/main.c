#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

int main(){

    Fila* f = filaCria();

    filaInsere(f, 10);
    filaInsere(f, 2);
    filaInsere(f, 18);
    filaInsere(f, -6);
    filaInsere(f, 15);
    filaInsere(f, 0);

    printf("Fila original:\n");
    filaImprime(f);

    inverteFila(f);

    printf("\nFila invertida:\n");
    filaImprime(f);

    filaLibera(f);
//
    printf("\n");

    return 0;
}