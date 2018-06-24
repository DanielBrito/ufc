#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

int main(){

    Fila* f = filaCria();

    filaInsere(f, 1);
    filaInsere(f, -4);
    filaInsere(f, 32);
    filaInsere(f, 45);
    filaInsere(f, -15);
    filaInsere(f, 0);
    filaInsere(f, 38);
    filaInsere(f, -13);
    filaInsere(f, 7);
    filaInsere(f, -1);

    printf("Fila original:\n");
    filaImprime(f);

    removeNegativos(f);

    printf("\nFila sem elementos negativos:\n");
    filaImprime(f);

    filaLibera(f);

    printf("\n");

    return 0;
}