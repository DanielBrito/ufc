#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

int main(){

    Pilha* p = p_cria();

    p_push(p, 13);
    p_push(p, 7);
    p_push(p, 5);
    p_push(p, 2);
    p_push(p, 0);

    printf("Pilha original:\n");
    p_imprime(p);

    invertePilha(p);

    printf("\nPilha invertida:\n");
    p_imprime(p);

    p_libera(p);
//
    printf("\n");

    return 0;
}